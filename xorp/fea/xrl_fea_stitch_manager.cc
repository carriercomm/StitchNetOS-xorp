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
#include "fea_module.h"
#include "libxorp/xorp.h"
#include "libxorp/xlog.h"
#include "libxorp/debug.h"

#include "xrl_fea_stitch_manager.hh"

XrlFeaStitchManager::XrlFeaStitchManager(XrlRouter &finder):_rtm(finder), _stitch_lc_fea(&finder)
{
}

void XrlFeaStitchManager::print_lc_message_cb(const XrlError& xrl_error)
{
     switch(xrl_error.error_code()) {
        case OKAY:
            XLOG_INFO("Stitch LC-FEA successfully executed the command.");
            break;
        case COMMAND_FAILED:
            XLOG_INFO("Stitch LC-FEA could not execute the command.");
            break;
        default:
            XLOG_INFO("Stitch LC-FEA returned unkown error.");
            break;
     }
}


void XrlFeaStitchManager::print_lc_message(string& lc_message)
{
    bool success = true;
    //Send the message out to the Stitch LC-FEA
    success = _stitch_lc_fea.send_print_hello_world("stitch_fea", lc_message,
        callback(this, &XrlFeaStitchManager::print_lc_message_cb));

    if (success) {
        XLOG_INFO("Sent the message to Stitch LC-FEA");
    } else {
        XLOG_WARNING("Wasn't able to send message to Stitch LC-FEA");
    }
}

void XrlFeaStitchManager::startup(void)
{
    string  str="Hello this is the FEA";
    
    print_lc_message(str);
}
