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
#include "fea_stitch_data_plane_if_linux.hh"
#include "fea_stitch_module.h"
#include "libxorp/xorp.h"
#include "libxorp/xlog.h"
#include "libxorp/debug.h"
#include "fea/data_plane/ifconfig/ifconfig_get_netlink_socket.hh"
#include "fea/data_plane/ifconfig/ifconfig_set_netlink_socket.hh"
#include "fea/data_plane/fibconfig/fibconfig_entry_get_netlink_socket.hh"
#include "fea/data_plane/fibconfig/fibconfig_entry_observer_netlink_socket.hh"


int FeaStitchDataPlaneIFLinux::load_plugins(string& error_msg)
{
    UNUSED(error_msg);

    if (_is_loaded_plugins)
	return (XORP_OK);

    XLOG_ASSERT(_ifconfig_get == NULL);
    XLOG_ASSERT(_ifconfig_set == NULL);
    XLOG_ASSERT(_ifconfig_observer == NULL);
    XLOG_ASSERT(_ifconfig_vlan_get == NULL);
    XLOG_ASSERT(_ifconfig_vlan_set == NULL);
#ifndef XORP_DISABLE_FIREWALL
    XLOG_ASSERT(_firewall_get == NULL);
    XLOG_ASSERT(_firewall_set == NULL);
#endif
    XLOG_ASSERT(_fibconfig_forwarding == NULL);
    XLOG_ASSERT(_fibconfig_entry_get == NULL);
    XLOG_ASSERT(_fibconfig_entry_set == NULL);
    XLOG_ASSERT(_fibconfig_entry_observer == NULL);
    XLOG_ASSERT(_fibconfig_table_get == NULL);
    XLOG_ASSERT(_fibconfig_table_set == NULL);
    XLOG_ASSERT(_fibconfig_table_observer == NULL);


    _ifconfig_get = new IfConfigGetNetlinkSocket(*this);

    _ifconfig_set = new IfConfigSetNetlinkSocket(*this);

    _ifconfig_observer = new IfConfigObserverNetlinkSocket(*this);

#if defined(HAVE_VLAN_LINUX)
    _ifconfig_vlan_get = new IfConfigVlanGetLinux(*this, false);
    _ifconfig_vlan_set = new IfConfigVlanSetLinux(*this, false);
#endif

#ifndef XORP_DISABLE_FIREWALL
#if defined(HAVE_FIREWALL_NETFILTER)
    _firewall_get = new FirewallGetNetfilter(*this);
    _firewall_set = new FirewallSetNetfilter(*this);
#endif
#endif

#if defined(HAVE_PROC_LINUX)
    _fibconfig_forwarding = new FibConfigForwardingProcLinux(*this);
#endif

#if defined(HAVE_NETLINK_SOCKETS)
    _fibconfig_entry_get = new FibConfigEntryGetNetlinkSocket(*this);
#endif

#if defined(HAVE_NETLINK_SOCKETS)
    _fibconfig_entry_set = new FibConfigEntrySetNetlinkSocket(*this);
#endif

#if defined(HAVE_NETLINK_SOCKETS)
    _fibconfig_entry_observer = new FibConfigEntryObserverNetlinkSocket(*this);
#endif

#if defined(HAVE_NETLINK_SOCKETS)
    _fibconfig_table_get = new FibConfigTableGetNetlinkSocket(*this);
#endif

#if defined(HAVE_NETLINK_SOCKETS)
    _fibconfig_table_set = new FibConfigTableSetNetlinkSocket(*this);
#endif

#if defined(HAVE_NETLINK_SOCKETS)
    _fibconfig_table_observer = new FibConfigTableObserverNetlinkSocket(*this);
#endif

    _is_loaded_plugins = true;

    return (XORP_OK);
}
