// -*- c-basic-offset: 4; tab-width: 8; indent-tabs-mode: t -*-
// vim:set sts=4 ts=8:

// Copyright (c) 2001-2011 XORP, Inc and Others
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

#include <xorp_config.h>

#include "fea/fea_module.h"

#include "libxorp/xorp.h"
#include "libxorp/xlog.h"
#include "libxorp/debug.h"
#include "libxorp/ether_compat.h"
#include "libxorp/ipvx.hh"

#include "fea/ifconfig.hh"
#include "fea/fibconfig.hh"

#include "ifconfig_set_stitch.hh"

#include "fea/fea_node.hh"

IfConfigSetStitch::IfConfigSetStitch(FeaDataPlaneManager& fea_data_plane_manager)
    : IfConfigSet(fea_data_plane_manager)
{
}

IfConfigSetStitch::~IfConfigSetStitch()
{
    string error_msg;

    if (stop(error_msg) != XORP_OK) {
	XLOG_ERROR("Cannot stop the netlink(7) sockets mechanism to set "
		   "information about network interfaces into the underlying "
		   "system: %s",
		   error_msg.c_str());
    }
}

int
IfConfigSetStitch::start(string& error_msg)
{
	UNUSED(error_msg);

    if (_is_running)
	return (XORP_OK);

    _is_running = true;

    return (XORP_OK);
}

int
IfConfigSetStitch::stop(string& error_msg)
{
	UNUSED(error_msg);

    if (! _is_running)
	return (XORP_OK);


    _is_running = false;

    return (XORP_OK);
}

bool
IfConfigSetStitch::is_discard_emulated(const IfTreeInterface& i) const
{
    UNUSED(i);

    return (true);
}

bool
IfConfigSetStitch::is_unreachable_emulated(const IfTreeInterface& i)
    const
{
    UNUSED(i);

    return (true);
}

int
IfConfigSetStitch::config_begin(string& error_msg)
{
    // XXX: nothing to do

    UNUSED(error_msg);

    return (XORP_OK);
}

int
IfConfigSetStitch::config_end(string& error_msg)
{
    // XXX: nothing to do

    UNUSED(error_msg);

    return (XORP_OK);
}

int
IfConfigSetStitch::config_interface_begin(
    const IfTreeInterface* pulled_ifp,
    IfTreeInterface& config_iface,
    string& error_msg)
{
	UNUSED(pulled_ifp);
	UNUSED(config_iface);
	UNUSED(error_msg);

	return XORP_OK;
}

int
IfConfigSetStitch::config_interface_end(
    const IfTreeInterface* pulled_ifp,
    const IfTreeInterface& config_iface,
    string& error_msg)
{
	UNUSED(pulled_ifp);
	UNUSED(config_iface);
	UNUSED(error_msg);

    return (XORP_OK);
}

int
IfConfigSetStitch::config_vif_begin(const IfTreeInterface* pulled_ifp,
					   const IfTreeVif* pulled_vifp,
					   const IfTreeInterface& config_iface,
					   const IfTreeVif& config_vif,
					   string& error_msg)
{
    UNUSED(pulled_ifp);
    UNUSED(config_iface);
    UNUSED(config_vif);
    UNUSED(error_msg);

    if (pulled_vifp == NULL) {
	// Nothing to do: the vif has been deleted from the system
	return (XORP_OK);
    }

    // XXX: nothing to do

    return (XORP_OK);
}

int
IfConfigSetStitch::config_vif_end(const IfTreeInterface* pulled_ifp,
					 const IfTreeVif* pulled_vifp,
					 const IfTreeInterface& config_iface,
					 const IfTreeVif& config_vif,
					 string& error_msg)
{
    UNUSED(pulled_ifp);
	UNUSED(pulled_vifp);
    UNUSED(config_iface);
    UNUSED(config_vif);
    UNUSED(error_msg);

    return (XORP_OK);
}

void IfConfigSetStitch::add_addr_cb(const XrlError& xrl_error, const string* err_msg)
{
	 switch(xrl_error.error_code()) {
		case OKAY:
			XLOG_INFO("Stitch LC-FEA successfully executed the command.");
			break;
		case COMMAND_FAILED:
			XLOG_INFO("Stitch LC-FEA could not execute the command. %s", err_msg->c_str());
			break;
		default:
			XLOG_INFO("Stitch LC-FEA returned unkown error.");
			break;
	 }
}

int
IfConfigSetStitch::config_add_address(const IfTreeInterface* pulled_ifp,
					     const IfTreeVif* pulled_vifp,
					     const IfTreeAddr4* pulled_addrp,
					     const IfTreeInterface& config_iface,
					     const IfTreeVif& config_vif,
					     const IfTreeAddr4& config_addr,
					     string& error_msg)
{

    UNUSED(pulled_ifp);
    UNUSED(pulled_vifp);
    UNUSED(pulled_addrp);
    UNUSED(config_iface);
    UNUSED(config_vif);
    UNUSED(config_addr);
	UNUSED(error_msg);

	string ext_ifname, slot, port;

	ext_ifname = config_iface.ifname();
	slot = ext_ifname.substr(0, ext_ifname.find("/"));
	port = ext_ifname.substr(ext_ifname.find("/") + 1, ext_ifname.length() - ext_ifname.find("/") - 1);

	// Forward the message to the appropriate fea-stitch slot
	fea_data_plane_manager().stitch_lc_fea().send_add_addr(
		fea_data_plane_manager().fea_node().feaStitchStore().find_fea_stitch(atoi(slot.c_str()))->UID.c_str(),
		port, config_vif.vifname(), config_iface.pif_index(),
		config_addr.addr(), config_addr.prefix_len(), config_addr.broadcast(), config_addr.bcast(),
		config_addr.point_to_point(), config_addr.endpoint(), callback(this, &IfConfigSetStitch::add_addr_cb));



    return (XORP_OK);
}

int
IfConfigSetStitch::config_delete_address(
    const IfTreeInterface* pulled_ifp,
    const IfTreeVif* pulled_vifp,
    const IfTreeAddr4* pulled_addrp,
    const IfTreeInterface& config_iface,
    const IfTreeVif& config_vif,
    const IfTreeAddr4& config_addr,
    string& error_msg)
{
    UNUSED(pulled_ifp);
    UNUSED(pulled_vifp);
    UNUSED(pulled_addrp);
    UNUSED(config_iface);
    UNUSED(config_vif);
    UNUSED(config_addr);
	UNUSED(error_msg);

    return (XORP_OK);
}

int
IfConfigSetStitch::config_add_address(const IfTreeInterface* pulled_ifp,
					     const IfTreeVif* pulled_vifp,
					     const IfTreeAddr6* pulled_addrp,
					     const IfTreeInterface& config_iface,
					     const IfTreeVif& config_vif,
					     const IfTreeAddr6& config_addr,
					     string& error_msg)
{

    UNUSED(pulled_ifp);
    UNUSED(pulled_vifp);
	UNUSED(pulled_addrp);
    UNUSED(config_iface);
    UNUSED(config_vif);
    UNUSED(config_addr);
	UNUSED(error_msg);

    return (XORP_OK);
}

int
IfConfigSetStitch::config_delete_address(
    const IfTreeInterface* pulled_ifp,
    const IfTreeVif* pulled_vifp,
    const IfTreeAddr6* pulled_addrp,
    const IfTreeInterface& config_iface,
    const IfTreeVif& config_vif,
    const IfTreeAddr6& config_addr,
    string& error_msg)
{
    UNUSED(pulled_ifp);
    UNUSED(pulled_vifp);
    UNUSED(pulled_addrp);
    UNUSED(config_iface);
    UNUSED(config_vif);
    UNUSED(config_addr);
	UNUSED(error_msg);

    return (XORP_OK);
}

int
IfConfigSetStitch::set_interface_status(const string& ifname,
					       uint32_t if_index,
					       uint32_t interface_flags,
					       bool is_enabled,
					       string& error_msg)
{
    UNUSED(ifname);
    UNUSED(if_index);
    UNUSED(interface_flags);
    UNUSED(is_enabled);
	UNUSED(error_msg);

    return (XORP_OK);
}

void
IfConfigSetStitch::wait_interface_status(const IfTreeInterface* ifp,
						bool is_enabled)
{
	UNUSED(is_enabled);
	UNUSED(ifp);
}

int
IfConfigSetStitch::set_interface_mac_address(const string& ifname,
						    uint32_t if_index,
						    const Mac& mac,
						    string& error_msg)
{
    UNUSED(ifname);
    UNUSED(if_index);
    UNUSED(mac);
	UNUSED(error_msg);

	return XORP_OK;
}

int
IfConfigSetStitch::set_interface_mtu(const string& ifname,
					    uint32_t if_index,
					    uint32_t mtu,
					    string& error_msg)
{
    UNUSED(ifname);
    UNUSED(if_index);
    UNUSED(mtu);
	UNUSED(error_msg);

	return XORP_OK;
}

int
IfConfigSetStitch::add_addr(const string& ifname,
				   const string& vifname,
				   uint32_t if_index,
				   const IPvX& addr,
				   uint32_t prefix_len,
				   bool is_broadcast,
				   const IPvX& broadcast_addr,
				   bool is_point_to_point,
				   const IPvX& endpoint_addr,
				   string& error_msg)
{
    UNUSED(ifname);
    UNUSED(vifname);
	UNUSED(if_index);
    UNUSED(addr);
    UNUSED(prefix_len);
    UNUSED(is_broadcast);
    UNUSED(broadcast_addr);
    UNUSED(is_point_to_point);
    UNUSED(endpoint_addr);
	UNUSED(error_msg);

    return (XORP_OK);
}

int
IfConfigSetStitch::delete_addr(const string& ifname,
				      const string& vifname,
				      uint32_t if_index,
				      const IPvX& addr,
				      uint32_t prefix_len,
				      string& error_msg)
{
    UNUSED(ifname);
    UNUSED(vifname);
	UNUSED(if_index);
    UNUSED(addr);
    UNUSED(prefix_len);
	UNUSED(error_msg);

    return (XORP_OK);
}


