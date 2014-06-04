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
// found in the XORP LICENSE.gpl file
//
#include "port_mgr_base.hh"
FeaPort* FeaPortTree::add_port(const string pt_name)
{
    FeaPortMapIt it = _port_map.find(pt_name);
    FeaPort* newPort;
    
    if (it != _port_map.end()) {
        return it->second;
    } else {
        //Need to add a new port
        newPort = new FeaPort(_port_map, pt_name);
        _port_map.insert(std::make_pair(pt_name, newPort));
        return newPort;
    }
}

FeaPort* FeaPortTree::remove_port(const string& pt_name)
{
    FeaPortMapIt it = _port_map.find(pt_name)

    if (it != _port_map.end()) {
        FeaPort* delPort = it->second;
        _port_map.erase(it);
        return delPort;
    } 
    return NULL;
}
