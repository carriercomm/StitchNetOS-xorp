
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
#ifndef __FEA_PORT_MGR_HH__
#define __FEA_PORT_MGR_HH__
#include "libxorp/mac.hh"
#include <map>
class FeaPortItem 
{
    public:
        enum PortConfigStatus {
            CFG_CREATED = 0x01,
            CFG_DELETED = 0x02
        };
        enum PortAdminState {
            ADMIN_DOWN = 0x01,
            ADMIN_UP = 0x02,
            ADMIN_BLOCKED = 0x03
        };

        enum PortOperState {
            OPER_DOWN = 0x01,
            OPER_UP = 0x02
        };
        FeaPortItem() : _config_st(CFG_CREATED), _admin_st(ADMIN_DOWN), _oper_st(OPER_DOWN) {};
        PortConfigStatus getConfStatus() { return _config_st;};
        PortAdminState getAdminStatus() {return _admin_st;};
        PortOperState getOperStatus() {return _oper_st;};

    protected:  

        PortConfigStatus _config_st;
        PortAdminState _admin_st;
        PortOperState _oper_st;
};

class FeaPortTree;

class FeaPort : public FeaPortItem
{
    public:
    typedef set<Mac> MacSet;
    FeaPort(FeaPortTree& port_tree, const string& port_name):_port_tree(port_tree),
    _port_name(port_name){};
    FeaPortTree& port_tree() { return _port_tree;};
    bool enabled() const		{ return _enabled; };
    uint32_t mtu() const		{ return _mtu; };
    void set_mtu(uint32_t mtu)		{ _mtu = mtu; };
    const Mac& mac() const		{ return _mac; };
    void set_mac(const Mac& mac)	{ _mac = mac;};

    MacSet& macs()			{ return _macs; };
    const MacSet& macs() const		{ return _macs; };

    bool no_carrier() const		{ return _no_carrier; };
    void set_no_carrier(bool v)		{ _no_carrier = v;};

    uint64_t baudrate() const		{ return _baudrate; };
    void set_baudrate(uint64_t v)	{ _baudrate = v;};

    bool management() const		{ return _management; };
    void set_management(bool v)		{ _management = v; };
    bool auto_neg() {return _auto_neg;};
    void set_auto_neg(bool v) {_auto_neg = v;};

    protected:
    FeaPortTree& _port_tree;
    string _port_name;
    bool _enabled;
    uint32_t _mtu;
    Mac _mac;
    MacSet _macs;
    bool _no_carrier;
    uint64_t _baudrate;
    bool _management;
    uint32_t _pif_index;
    uint32_t _link_speed;
    bool _auto_neg;
};

class FeaPortTree 
{
    public:
    typedef map<string, FeaPort*> FeaPortMap;
    typedef map<string, FeaPort*>::iterator FeaPortMapIt;

    FeaPortTree(const string& pt_name):_pt_name(pt_name){};

    const string& port_tree_name() { return _pt_name;}

    /**
     * Add a new port to the port map.
     * @param pt_name the name of the port.
     * @return A pointer to an existing port, or a new port that got created.
     */
    FeaPort* add_port(const string& pt_name);
    /**
     * Delete a port from the port map.
     * @param pt_name name of the port to be deleted.
     * @return FeaPort* the port object that was found on the list and was
     * erased fromt the list, or NULL if the port object was not found on
     * the list.
     */
    FeaPort* delete_port(const string& pt_name);

    protected:
    string _pt_name;
    FeaPortMap _port_map;
};
#endif//__FEA_PORT_MGR_HH__
