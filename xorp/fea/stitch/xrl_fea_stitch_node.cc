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
//


#include "xrl_fea_stitch_node.hh"


XrlFeaStitchNode::XrlFeaStitchNode(EventLoop& eventloop,
            const string& class_name,
            const string& finder_hostname,
            const uint16_t finder_port,
            const string& finder_target,
            const string& fea_target)
            : XrlStdRouter(eventloop, class_name.c_str(), finder_hostname.c_str(), finder_port),
            XrlFeastitchTargetBase(&xrl_router()),
            _finder_target(finder_target),
            _fea_target(fea_target)

{
    running = false;
}

XrlFeaStitchNode::~XrlFeaStitchNode()
{
}


int XrlFeaStitchNode::startup(void) 
{
    running = true;
    XLOG_INFO("Starting XRL interface of FEA stitch node");
    return XORP_OK;
}

int XrlFeaStitchNode::shutdown(void)
{
    running = false;
    XLOG_INFO("Shutting down XRL interface of FEA stitch node");
    return XORP_OK;
}

bool XrlFeaStitchNode::is_done(void)
{
    return !running;
}

XrlCmdError XrlFeaStitchNode::fea_stitch_0_1_enable_fea_stitch( const bool& enable)
{
    XLOG_INFO("Trying to enable:%d fea stitch node", enable);
    return XrlCmdError::OKAY();
}

XrlCmdError XrlFeaStitchNode::fea_stitch_0_1_start_fea_stitch()
{
    return XrlCmdError::OKAY();
}

XrlCmdError XrlFeaStitchNode::fea_stitch_0_1_stop_fea_stitch()
{
    return XrlCmdError::OKAY();
}

XrlCmdError XrlFeaStitchNode::fea_stitch_0_1_print_hello_world( const string&   str)
{
    XLOG_INFO("%s",str.c_str());
    return XrlCmdError::OKAY();
}

XrlCmdError XrlFeaStitchNode::fea_stitch_0_1_enable_log_trace_all( const bool& enable)
{
    XLOG_INFO("FEA stitch log %d", enable);
    return XrlCmdError::OKAY();
}
