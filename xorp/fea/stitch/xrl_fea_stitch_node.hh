// -*- c-basic-offset: 4; tab-width: 8; indent-tabs-mode: t -*-
// vim:set sts=4 ts=8:

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

#ifndef __FEA_STITCH_XRL_FEA_STITCH_NODE_HH_
#define __FEA_STITCH_XRL_FEA_STITCH_NODE_HH_
//
// StaticRoutes XRL-aware node definition.
//

#include "libxipc/xrl_std_router.hh"
#include "xrl/interfaces/finder_event_notifier_xif.hh"
#include "xrl/interfaces/fea_stitch_ifconfig_xif.hh"
#include "xrl/interfaces/fea_stitch_register_xif.hh"
#include "xrl/targets/fea_stitch_base.hh"
#include "fea/xrl_fea_io.hh"
#include "fea_stitch_node.hh"

enum {
    FEA_STITCH_SHUTDOWN = 0,
    FEA_STITCH_BOOTING = 1,
    FEA_STITCH_REGISTERED = 2
};

//
//The top-level class that wraps-up everything together under one roof
//This is the entry point for all XRL calls into FEA stitch.
//
class XrlFeaStitchNode : public XrlStdRouter, public XrlFeastitchTargetBase 
{
    public:
        XrlFeaStitchNode(EventLoop& eventloop,
            const string& UID,
            const string& finder_hostname,
            const uint16_t finder_port,
            const string& finder_target,
            const string& fea_target);
        virtual ~XrlFeaStitchNode();
        /**
         * Init the node. Registers with the XRL finder. If it's not able to
         * connect with finder keep trying every 10 seconds. Once we have
         * connected with the finder, we need to register with the global FEA.
         * @return XORP_OK on sucess, otherwise XORP_ERROR
         */
        int init();
        /*
         * Startup the node. 
         * @return XORP_OK on success, otherwise XORP_ERROR
         */
        int startup();

        /**
         * Shutdown the node. De-register with FEA and the finder. 
         *
         * @return XORP_OK on success, otherwise XORP_ERROR.
         */
        int shutdown();

        /**
         * Get a reference to the XrlRouter instance.
         *
         * @return a reference to the XrlRouter (@ref XrlRouter) instance.
         */
        XrlRouter& xrl_router() {return *this; };

        /**
         * Check with the stitch FEA has registered with the FEA.
         * @return status of stitch FEA registration
         */
        bool registered();

        bool is_done();
        void fea_stitch_register_cb(const XrlError& xrl_error, const string* UID);

        /**
         * Returns the UID associated with this object
         */
        string getUID() {return _UID;};
		void setUID(string& UID) {_UID = UID;};
        int getStatus() { return _status;};

		void upload_port_information_to_fea_cb(const XrlError& xrl_error, const string* ret_ifname, const uint32_t* port_num);
		int upload_port_information_to_fea(void);
    protected:
        //
        // XRL target methods
        //
        //
        XrlCmdError fea_stitch_0_1_enable_fea_stitch(const bool& enable);
        XrlCmdError fea_stitch_0_1_start_fea_stitch();
        XrlCmdError fea_stitch_0_1_stop_fea_stitch();
        XrlCmdError fea_stitch_0_1_print_hello_world(const string&   str);
        XrlCmdError fea_stitch_0_1_enable_log_trace_all( const bool& enable);
        XrlFeaIo _xrl_fea_io;
        FeaStitchNode _fea_stitch_node;
    private:
        const string& _finder_target;
        const string& _fea_target;
        int _status;
        string _UID;
        XrlFeaStitchIfconfigV0p1Client _xrl_fea_stitch_ifconfig;
		XrlFeaStitchRegisterV0p1Client _xrl_fea_stitch_register;

};
#endif
