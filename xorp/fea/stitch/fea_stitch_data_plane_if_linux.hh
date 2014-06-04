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
#ifndef __FEA_STITCH_FEA_STITCH_DATA_PLANE_IF_LINUX_HH__
#define __FEA_STITCH_FEA_STITCH_DATA_PLANE_IF_LINUX_HH__
#include "fea_stitch_data_plane_if.hh"
class  FeaStitchDataPlaneIFLinux : public FeaStitchDataPlaneIF {
public:
    /**
     * Constructor.
     *
     * @param fea_node the @ref FeaNode this manager belongs to.
     */
    FeaStitchDataPlaneIFLinux(EventLoop &event_loop, FeaStitchNode& fea_stitch_node, 
            const string& dp_if_name): FeaStitchDataPlaneIF(event_loop, 
            fea_stitch_node, dp_if_name){};
    virtual ~FeaStitchDataPlaneIFLinux();

    /**
     * Load the plugins
     */
    int load_plugins(string& error_msg);


    //All variables are defined in the base-class
};
#endif//__FEA_STITCH_FEA_STITCH_DATA_PLANE_IF_LINUX_HH__
