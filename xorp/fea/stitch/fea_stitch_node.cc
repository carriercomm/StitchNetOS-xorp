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
#include "fea_stitch_node.hh"
#include "fea/data_plane/managers/fea_data_plane_manager_linux.hh"
FeaStitchNode::FeaStitchNode(EventLoop &event_loop, const string& _pt_name, 
        const string& _ift_name, FeaIo&_fea_io):FeaNode(event_loop, _fea_io, false),
    _port_tree(_pt_name),
    _if_tree(_ift_name.c_str())
{
    _stitch_dpm_linux = new FeaDataPlaneManagerLinux(*this);
}


int FeaStitchNode::startup() 
{
    string error_str = "Unable to load the linux plugins for stitch FEA node";
    _stitch_dpm_linux->load_plugins(error_str);
    XLOG_INFO("Stitch FEA Node startup done");
    return XORP_OK;
}


int FeaStitchNode::shutdown()
{
    return FeaNode::shutdown();
}
