// -*- c-basic-offset: 4; tab-width: 8; indent-tabs-mode: t -*-

// Copyright (c) 2001-2009 XORP, Inc.
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
// XORP Inc, 2953 Bunker Hill Lane, Suite 204, Santa Clara, CA 95054, USA;
// http://xorp.net

// $XORP: xorp/fea/tools/show_interfaces.hh,v 1.11 2008/10/02 21:57:13 bms Exp $

#ifndef __FEA_TOOLS_SHOW_STITCH_PORT_HH__
#define __FEA_TOOLS_SHOW_STITCH_PORT_HH__


#include "libxipc/xrl_std_router.hh"
#include "xrl/targets/stitch_portmgr_mirror_base.hh"
#include "xrl/interfaces/stitch_port_replicator_xif.hh"


class EventLoop;


class SwitchPortMgr : public XrlStitchPortmgrMirrorTargetBase{

			 
public:
    /**
     * SwitchPortMgr constructor
     *
     * @param eventloop this process's EventLoop.
     * @param class_name the XRL class name of this target.
     * @param finder_hostname the finder's host name.
     * @param finder_port the finder's port.
     * @param fea_target the FEA target name.
     */
    SwitchPortMgr(EventLoop&		eventloop,
            XrlStdRouter &xrl_router,
		     const string&	fea_target);

    /**
     * InterfaceMonitor destructor
     */
    ~SwitchPortMgr(){};

    void print_interfaces(const string& print_iface_name) const;
    XrlCmdError stitch_port_mirror_0_1_port_add(const string&   port_name);
    XrlCmdError stitch_port_mirror_0_1_port_remove(const string&   port_name);
    bool is_registered() { return _status == STITCH_PORT_MIRROR_REGISTERED ? true:false;};
    bool is_ports_recvd() { return _status == STITCH_PORT_MIRROR_PORTS_RECVD ? true:false;};
    int start();


private:
    enum port_mirror_status_e {
        STITCH_PORT_MIRROR_DOWN = 0,
        STITCH_PORT_MIRROR_REGISTERING = 1,
        STITCH_PORT_MIRROR_REGISTERED = 2,
        STITCH_PORT_MIRROR_PORTS_RECVD = 3
    }port_mirror_status_t;
    EventLoop& _eventloop;
    XrlStdRouter& _xrl_router;
    string _fea_target;
    int _status;
    XrlStitchPortReplicatorV0p1Client _fea_client;

    void fea_register_callback(const XrlError& error);
};

#endif // __FEA_TOOLS_SHOW_INTERFACES_HH__
