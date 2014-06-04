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
#ifndef __FEA_STITCH_FEA_STITCH_DATA_PLANE_IF_HH__
#define __FEA_STITCH_FEA_STITCH_DATA_PLANE_IF_HH__
#include <string>
#include "libxorp/eventloop.hh"
#include "fea/ifconfig_get.hh"
#include "fea/ifconfig_set.hh"
#include "fea/fibconfig_entry_get.hh"
#include "fea/fibconfig_entry_set.hh"
#include "fea/fibconfig_forwarding.hh"
#include "fea/fibconfig_table_set.hh"

class FeaStitchNode;

class FeaStitchDataPlaneIF 
{
    public:
    FeaStitchDataPlaneIF(EventLoop &event_loop, FeaStitchNode& fea_stitch_node, 
            const string& dp_if_name):_event_loop(event_loop), 
    _fea_stitch_node(fea_stitch_node),_dp_if_name(dp_if_name){_is_loaded_plugins = false;};
    /**
     *Virtual destructor.
     */
    virtual ~FeaStitchDataPlaneIF();

    const string& manager_name() const {return _dp_if_name;};
    /**
     * Load the plugins.
     *
     * @param error_msg the error message (if error).
     * @return XORP_OK on success, otherwise XORP_ERROR.
     */
    virtual int load_plugins(string& error_msg) = 0;
    /**
     * Get the event loop this instance is added to.
     * 
     * @return the event loop this instance is added to.
     */
    EventLoop&	eventloop() {return _event_loop;};
    /**
     * Get the IfConfigGet plugin.
     *
     * @return the @ref IfConfigGet plugin.
     */
    IfConfigGet* ifconfig_get() { return _ifconfig_get; }

    /**
     * Get the IfConfigSet plugin.
     *
     * @return the @ref IfConfigSet plugin.
     */
    IfConfigSet* ifconfig_set() { return _ifconfig_set; }

    /**
     * Get the IfConfigObserver plugin.
     *
     * @return the @ref IfConfigObserver plugin.
     */
    IfConfigObserver* ifconfig_observer() { return _ifconfig_observer; }

    /**
     * Get the IfConfigVlanGet plugin.
     *
     * @return the @ref IfConfigVlanGet plugin.
     */
    IfConfigVlanGet* ifconfig_vlan_get() { return _ifconfig_vlan_get; }

    /**
     * Get the IfConfigVlanSet plugin.
     *
     * @return the @ref IfConfigVlanSet plugin.
     */
    IfConfigVlanSet* ifconfig_vlan_set() { return _ifconfig_vlan_set; }

    /**
     * Get the FibConfigForwarding plugin.
     *
     * @return the @ref FibConfigForwarding plugin.
     */
    FibConfigForwarding* fibconfig_forwarding() { return _fibconfig_forwarding; }

    /**
     * Get the FibConfigEntryGet plugin.
     *
     * @return the @ref FibConfigEntryGet plugin.
     */
    FibConfigEntryGet* fibconfig_entry_get() { return _fibconfig_entry_get; }

    /**
     * Get the FibConfigEntrySet plugin.
     *
     * @return the @ref FibConfigEntrySet plugin.
     */
    FibConfigEntrySet* fibconfig_entry_set() { return _fibconfig_entry_set; }

    /**
     * Get the FibConfigEntryObserver plugin.
     *
     * @return the @ref FibConfigEntryObserver plugin.
     */
    FibConfigEntryObserver* fibconfig_entry_observer() { return _fibconfig_entry_observer; }

    /**
     * Get the FibConfigTableGet plugin.
     *
     * @return the @ref FibConfigEntryGet plugin.
     */
    FibConfigTableGet* fibconfig_table_get() { return _fibconfig_table_get; }

    /**
     * Get the FibConfigTableSet plugin.
     *
     * @return the @ref FibConfigEntryGet plugin.
     */
    FibConfigTableSet* fibconfig_table_set() { return _fibconfig_table_set; }

    /**
     * Get the FibConfigTableObserver plugin.
     *
     * @return the @ref FibConfigEntryObserver plugin.
     */
    FibConfigTableObserver* fibconfig_table_observer() { return _fibconfig_table_observer; }

   
    protected:
    EventLoop   &_event_loop;
    FeaStitchNode &_fea_stitch_node;
    string _dp_if_name;
    bool _is_loaded_plugins;
    IfConfigGet*		_ifconfig_get;
    IfConfigSet*		_ifconfig_set;
    IfConfigObserver*		_ifconfig_observer;
    IfConfigVlanGet*		_ifconfig_vlan_get;
    IfConfigVlanSet*		_ifconfig_vlan_set;
#ifndef XORP_DISABLE_FIREWALL
    FirewallGet*		_firewall_get;
    FirewallSet*		_firewall_set;
#endif
    FibConfigForwarding*	_fibconfig_forwarding;
    FibConfigEntryGet*		_fibconfig_entry_get;
    FibConfigEntrySet*		_fibconfig_entry_set;
    FibConfigEntryObserver*	_fibconfig_entry_observer;
    FibConfigTableGet*		_fibconfig_table_get;
    FibConfigTableSet*		_fibconfig_table_set;
    FibConfigTableObserver*	_fibconfig_table_observer;
};
#endif//__FEA_STITCH_FEA_STITCH_DATA_PLANE_IF_HH__
