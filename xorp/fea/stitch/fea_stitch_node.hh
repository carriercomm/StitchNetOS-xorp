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
#ifndef __FEA_STITCH_FEA_STITCH_NODE_HH_
#define __FEA_STITCH_FEA_STITCH_NODE_HH_
#include "fea_stitch_module.h"
#include "libxorp/eventloop.hh"
#include "fea/fea_node.hh"
#include "fea/port_mgr_base.hh"
#include "fea/fea_data_plane_manager.hh"

class FeaStitchDataPlaneIF;

class FeaStitchNode :public FeaNode{
    public:
        FeaStitchNode(EventLoop &event_loop, const string& _pt_name, const string& _ift_name,
        FeaIo& fea_io);
        int startup();
        int shutdown();
        FeaPortTree& get_port_map() { return _port_tree;};
		FeaDataPlaneManager* stitch_dpm_linux() {return _stitch_dpm_linux;};
		void init_port_num_to_intf_name_map();
		void insert_port_num_to_intf_name_map(int port, string intf_name);
		uint32_t find_port_num_from_intf_name(const string intf_name);

    protected:
        //port tree
        FeaPortTree _port_tree;
        //if tree
        IfTree _if_tree;
		map<uint32_t, string> _port_num_to_intf_map;
        FeaDataPlaneManager* _stitch_dpm_linux;
        //fib
        //firewall
        //mfib
};
#endif //__FEA_STITCH_FEA_STITCH_NODE_HH_

