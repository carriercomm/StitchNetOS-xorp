// -*- c-basic-offset: 4; tab-width: 8; indent-tabs-mode: t -*-

//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License, Version 2, June
// 1991 as published by the Free Software Foundation. Redistribution
// and/or modification of this program under the terms of any other
// version of the GNU General Public License is not permitted.
//
// This program is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. For more details,
// see the GNU General Public License, Version 2, a copy of which can be
// found in the XORP LICENSE.gpl file.
//
//

#include "fea_stitch_module.h"

#include "libxorp/xorp.h"
#include "libxorp/xlog.h"
#include "libxorp/debug.h"
#include "libxorp/callback.hh"
#include "libxorp/eventloop.hh"
#include "libxorp/exceptions.hh"
#include "libproto/proto_unit.hh"
#include "xrl_fea_stitch_node.hh"

#ifdef HAVE_GETOPT_H
#include <getopt.h>
#endif

//
// Local functions prototypes
//
static	void usage(const char *argv0, int exit_value);

/**
 * usage:
 * @argv0: Argument 0 when the program was called (the program name itself).
 * @exit_value: The exit value of the program.
 *
 * Print the program usage.
 * If @exit_value is 0, the usage will be printed to the standart output,
 * otherwise to the standart error.
 **/
static void
usage(const char *argv0, int exit_value)
{
    FILE *output;
    const char *progname = strrchr(argv0, '/');

    if (progname != NULL)
	progname++;		// Skip the last '/'
    if (progname == NULL)
	progname = argv0;

    //
    // If the usage is printed because of error, output to stderr, otherwise
    // output to stdout.
    //
    if (exit_value == 0)
	output = stdout;
    else
	output = stderr;

    fprintf(output, "Usage: %s [-F <finder_hostname>[:<finder_port>]]\n",
	    progname);
    fprintf(output, "           -F <finder_hostname>[:<finder_port>]  : finder hostname and port\n");
    fprintf(output, "           -h                                    : usage (this message)\n");
    fprintf(output, "\n");
    fprintf(output, "Program name:   %s\n", progname);
    fprintf(output, "Module name:    %s\n", XORP_MODULE_NAME);
    fprintf(output, "Module version: %s\n", XORP_MODULE_VERSION);

    exit (exit_value);

    // NOTREACHED
}

bool is_empty(fstream& pFile)
{
    return pFile.peek() == fstream::traits_type::eof();
}

static void
fea_stitch_main(const string& finder_hostname, uint16_t finder_port) {
    string UID = "FEA-STITCH";
	fstream f_uid;

	f_uid.open("/root/uid", fstream::in);
	if (f_uid.is_open() && !is_empty(f_uid)) {
		getline(f_uid, UID);
	}
	f_uid.close();

    setup_dflt_sighandlers();

    //
    // Init stuff
    //
    EventLoop eventloop;

    //
    // FEA stitch node
    //
    XrlFeaStitchNode *xrl_fea_stitch_node = new XrlFeaStitchNode(
	eventloop,
	UID,
	finder_hostname,
	finder_port,
	"finder",
	"fea");
    wait_until_xrl_router_is_ready(eventloop,
				   xrl_fea_stitch_node->xrl_router());
    XLOG_INFO("Connected to XRL finder");

	xrl_fea_stitch_node->setUID(UID);

    // Startup
    xrl_fea_stitch_node->init();
    //Wait till the stitch FEA node has registered with the FEA.
    while(!xrl_fea_stitch_node->registered()) {
        eventloop.run();
    }

    XLOG_INFO("Initial registration with FEA with UID:%s complete.", UID.c_str());
    XLOG_INFO("New UID:%s", (xrl_fea_stitch_node->getUID()).c_str());
    //Re-register with the finder with UID retrieved from the FEA as the class
    //name
    if (UID != xrl_fea_stitch_node->getUID()) {
        UID = xrl_fea_stitch_node->getUID();
        delete xrl_fea_stitch_node;

        xrl_fea_stitch_node = new XrlFeaStitchNode(
                eventloop,
                UID,
                finder_hostname,
                finder_port,
                "finder",
                "fea");
        wait_until_xrl_router_is_ready(eventloop,
                xrl_fea_stitch_node->xrl_router());
        xrl_fea_stitch_node->init();
        XLOG_INFO("Re-connected with finder with UID:%s", UID.c_str());
        //Wait till the stitch FEA with the new FEA is registered with the FEA.
        while(!xrl_fea_stitch_node->registered()) {
            eventloop.run();
        }
        XLOG_INFO("Re-registration with FEA with UID:%s complete.", UID.c_str());

		f_uid.open("/root/uid", fstream::out | fstream::trunc);
		if (!f_uid.is_open()) {
			XLOG_ERROR("Unable to open uid mapping file in fea");
		}

		f_uid << UID;
		f_uid.close();
    }

    //start the stitch node
    xrl_fea_stitch_node->startup();

    XLOG_INFO("Stitch FEA:%s ready for execution.", UID.c_str());

    //Read all the physical ports and build the port-map
    xrl_fea_stitch_node->upload_port_information_to_fea();
    //
    // Main loop
    //
    while (xorp_do_run && !xrl_fea_stitch_node->is_done()) {
        eventloop.run();
    }
    XLOG_INFO("Ending stitch execution !! xorp_do_run:%d, stitch_is_done:%d, status:%d", xorp_do_run, xrl_fea_stitch_node->is_done(), xrl_fea_stitch_node->getStatus());
}

int
main(int argc, char *argv[])
{
    int ch;
    string::size_type idx;
    const char *argv0 = argv[0];
    string finder_hostname = FinderConstants::FINDER_DEFAULT_HOST().str();
    uint16_t finder_port = FinderConstants::FINDER_DEFAULT_PORT();

    //
    // Initialize and start xlog
    //
    xlog_init(argv[0], NULL);
    xlog_set_verbose(XLOG_VERBOSE_LOW);		// Least verbose messages
    // XXX: verbosity of the error messages temporary increased
    xlog_level_set_verbose(XLOG_LEVEL_ERROR, XLOG_VERBOSE_HIGH);
    xlog_add_default_output();
    xlog_start();

    //
    // Get the program options
    //
    while ((ch = getopt(argc, argv, "F:h")) != -1) {
	switch (ch) {
	case 'F':
	    // Finder hostname and port
	    finder_hostname = optarg;
	    idx = finder_hostname.find(':');
	    if (idx != string::npos) {
		if (idx + 1 >= finder_hostname.length()) {
		    // No port number
		    usage(argv0, 1);
		    // NOTREACHED
		}
		char* p = &finder_hostname[idx + 1];
		finder_port = static_cast<uint16_t>(atoi(p));
		finder_hostname = finder_hostname.substr(0, idx);
	    }
	    break;
	case 'h':
	case '?':
	    // Help
	    usage(argv0, 0);
	    // NOTREACHED
	    break;
	default:
	    usage(argv0, 1);
	    // NOTREACHED
	    break;
	}
    }
    argc -= optind;
    argv += optind;
    if (argc != 0) {
	usage(argv0, 1);
	// NOTREACHED
    }

    //
    // Run everything
    //
    try {
	fea_stitch_main(finder_hostname, finder_port);
    } catch(...) {
	xorp_catch_standard_exceptions();
    }

    //
    // Gracefully stop and exit xlog
    //
    xlog_stop();
    xlog_exit();

    exit (0);
}
