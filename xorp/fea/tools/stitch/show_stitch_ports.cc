#include "fea/fea_module.h"
#include "libxorp/xorp.h"
#include "libxorp/xlog.h"
#include "libxorp/debug.h"
#include "libxorp/status_codes.h"
#include "libxorp/eventloop.hh"
#include "show_stitch_ports.hh"

SwitchPortMgr::SwitchPortMgr(EventLoop& eventloop,
        XrlStdRouter &xrl_router,
        const string& fea_target):
    XrlStitchPortmgrMirrorTargetBase(&xrl_router),
    _eventloop(eventloop),
    _xrl_router(xrl_router),
    _fea_client(&xrl_router)
{
    _fea_target = fea_target;
    _status = STITCH_PORT_MIRROR_DOWN;
}

void SwitchPortMgr::fea_register_callback(const XrlError& xrl_error)
{
    switch(xrl_error.error_code()) {
        case OKAY:
            XLOG_INFO("Port mirror egistered successfully with FEA");
            _status = STITCH_PORT_MIRROR_REGISTERED;
            break;
        case COMMAND_FAILED:
            XLOG_ERROR("Could not register with FEA.");
            break;
        default:
            XLOG_ERROR("FEA returned unkown error.:%d", xrl_error.error_code());
            break;
    }

}

int SwitchPortMgr::start()
{
    int success = _fea_client.send_register_stitch_port_mirror(_fea_target.c_str(), 
            _xrl_router.instance_name(), callback(this, &SwitchPortMgr::fea_register_callback));
    if (!success) {
        XLOG_ERROR("Unable to register with FEA");
        return XORP_ERROR;
    }

    _status = STITCH_PORT_MIRROR_REGISTERING;

    return XORP_OK;
    
}

XrlCmdError SwitchPortMgr::stitch_port_mirror_0_1_port_add(const string&   port_name) 
{
  
    if (port_name != "NULL") {
        fprintf(stdout, "Port: %s\n", port_name.c_str());
    } else {
        XLOG_INFO("Got all ports");
        _status = STITCH_PORT_MIRROR_PORTS_RECVD;
    }
  return XrlCmdError::OKAY();
} 

XrlCmdError SwitchPortMgr::stitch_port_mirror_0_1_port_remove(const string&   port_name) 
{
  
  XLOG_INFO("Removing port: %s", port_name.c_str());
  return XrlCmdError::OKAY();
} 

static void
stitch_port_monitor_main(const string& finder_hostname, uint16_t finder_port)
{
    string process_name;
    process_name = c_format("stitch_port_mon<%d>", XORP_INT_CAST(getpid()));
    XLOG_INFO("About to connect start port mirror.\n");
    string fea_target = "fea";

    //
    // Init stuff
    //
    EventLoop eventloop;
    XrlStdRouter xrl_router(eventloop, process_name.c_str(), finder_hostname.c_str(), 
            finder_port);
    SwitchPortMgr port_mgr(eventloop, xrl_router, fea_target);

    wait_until_xrl_router_is_ready(eventloop,
            xrl_router);

    if (port_mgr.start() == XORP_ERROR) {
        return;
    }

    while (!port_mgr.is_ports_recvd()) {
        eventloop.run();
    }
    XLOG_INFO("Port mirror registered");
    XLOG_INFO("Port mirror done.\n"); 
}

int main(int argc, char* const argv[])
{
    int ch;
    string finder_hostname = FinderConstants::FINDER_DEFAULT_HOST().str();
    uint16_t finder_port = FinderConstants::FINDER_DEFAULT_PORT();
    string print_iface_name = "";	// XXX; empty string means print all
    string command;

    //
    // Initialize and start xlog
    //
    xlog_init(argv[0], NULL);
    xlog_set_verbose(XLOG_VERBOSE_LOW);		// Least verbose messages
    // XXX: verbosity of the error messages temporary increased
    xlog_level_set_verbose(XLOG_LEVEL_ERROR, XLOG_VERBOSE_HIGH);
    xlog_add_default_output();
    xlog_disable(XLOG_LEVEL_INFO);
    xlog_disable(XLOG_LEVEL_TRACE);
    xlog_start();

    //
    // Get the program options
    //
    while ((ch = getopt(argc, argv, "F:i:h")) != -1) {
        switch (ch) {
            default:
                break;
        }
    }
    //
    // Run everything
    //
    try {
        XLOG_INFO("Trying to connect to finder:%s, at port %d", finder_hostname.c_str(), finder_port);
        stitch_port_monitor_main(finder_hostname, finder_port);
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
