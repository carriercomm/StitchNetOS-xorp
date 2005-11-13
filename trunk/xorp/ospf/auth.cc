// -*- c-basic-offset: 4; tab-width: 8; indent-tabs-mode: t -*-
// vim:set sts=4 ts=8:

// Copyright (c) 2001-2005 International Computer Science Institute
//
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software")
// to deal in the Software without restriction, subject to the conditions
// listed in the XORP LICENSE file. These conditions include: you must
// preserve this copyright notice, and you cannot mention the copyright
// holders in advertising related to the Software without their permission.
// The Software is provided WITHOUT ANY WARRANTY, EXPRESS OR IMPLIED. This
// notice is a summary of the XORP LICENSE file; the license in that file is
// legally binding.

#ident "$XORP: xorp/ospf/auth.cc,v 1.1 2005/11/11 11:06:12 atanu Exp $"

// #define DEBUG_LOGGING
// #define DEBUG_PRINT_FUNCTION_NAME

#include "config.h"

#include "ospf_module.h"

#include "libxorp/debug.h"
#include "libxorp/xlog.h"

#include "libxorp/ipv4.hh"
#include "libxorp/ipv6.hh"
#include "libxorp/ipnet.hh"

#include "libxorp/status_codes.h"
#include "libxorp/eventloop.hh"

#include "ospf.hh"
#include "auth.hh"

void
AuthPlainText::generate(vector<uint8_t>& pkt) 
{
    XLOG_ASSERT(pkt.size() >= Packet::STANDARD_HEADER_V2);

    uint8_t *ptr = &pkt[0];
    embed_16(&ptr[Packet::AUTH_TYPE_OFFSET], AUTH_TYPE);
    memcpy(&ptr[Packet::AUTH_PAYLOAD_OFFSET], &_auth[0], sizeof(_auth));
}

bool
AuthPlainText::verify(vector<uint8_t>& pkt) 
{
    XLOG_ASSERT(pkt.size() >= Packet::STANDARD_HEADER_V2);

    uint8_t *ptr = &pkt[0];
    OspfTypes::AuType autype = extract_16(&ptr[Packet::AUTH_TYPE_OFFSET]);
    if (AUTH_TYPE != autype) {
	string error =
	    c_format("Authentication type failure expected %u received %u",
		     AUTH_TYPE, autype);
	set_verify_error(error);
	return false;
    }

    if (0 != memcmp(&ptr[Packet::AUTH_PAYLOAD_OFFSET], &_auth[0], 
		    sizeof(_auth))) {
	string error = c_format("Authentication failure password mismatch");
	set_verify_error(error);
	return false;
    }
    
    return true;
}

void
AuthPlainText::reset()
{
    size_t len = get_password().size();
    memcpy(&_auth[0], get_password().c_str(),
	   len > sizeof(_auth) ? sizeof(_auth) : len);
}
