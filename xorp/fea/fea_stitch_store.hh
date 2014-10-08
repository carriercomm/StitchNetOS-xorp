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
#ifndef __FEA_STITCH_STORE_HH__
#define __FEA_STITCH_STORE_HH__
#include "libxorp/eventloop.hh"
#include "libxorp/ipvx.hh"
#include "libxorp/mac.hh"
#include <map>

class FeaStitchInst
{
    public:
        FeaStitchInst(string &UID, int LCId, IPvX &ip);
		unsigned int getNextAvailPortNum();
		void resetNextAvailPortNum();
        string UID() const {return _UID;};
        int LCId() const { return _LCId;};
        IPvX ip() const { return _ip;};
        void set_ip(IPvX i_ip) { _ip = i_ip;};
    private:
        string _UID;
        int _LCId;
        IPvX _ip;
		unsigned int _last_port;
};

typedef map<std::string, FeaStitchInst>::iterator FeaStitchStoreIt;

/*
 * Base class for storing FEA stitch instances.
 * Each FEA stitch instance is allocated a unique ID (UID), which is the time-stamp at
 * which the XRL registration request was being processed by the FEA. Each UID
 * is in turn mapped to a line-card number. Once an FEA stitch instance registers
 * with the FEA, all future references for configuring objects on the FEA stitch
 * instance is perfomed by referring to the line-card number rather than the
 * UID. Apart from the UID and the line-card number we also need to store
 * meta-data about the FEA stitch instance such as the IP address and the MAC
 * address and the protocol family used to talk XRL semantics with the FEA
 * stitch instance.
 */
class FeaStitchStore
{
    public:
       FeaStitchStore(EventLoop& _events);
       FeaStitchInst* find_fea_stitch(const string& UID);
       FeaStitchInst* find_fea_stitch(const int LCId);
       FeaStitchInst* find_fea_stitch(const IPvX& ip);
       /*
        * Get the stitch-fea instance which owns this interface.
        */
       FeaStitchInst* get_intf_inst(const string ifname);
       void add(string &UID, int LCId, IPvX &ip);
       void add(FeaStitchInst& _fea_stitch);
       bool remove(const string &UID);
       bool remove (const int &LCId);
       bool remove (const IPvX &ip);
       void allocUID(string &UID); //Get a new UID and LCId
       int getNextAvailLCId();
	   int init_slot_num_to_uid_map ();
	   void insert_slot_to_uid_mapping (int slot, string uid);
	   map<int, string> fea_stitch_slot_to_uid_map() {return _fea_stitch_slot_to_uid_map;}
	   int find_fea_stitch_slot(const string &UID);
       //TODO: Implement an iterator to be able to iterate through all instances
       //of FEA stitch that were seen.
    private:
        EventLoop& _event_loop;
        map<string, FeaStitchInst> _fea_stitch_store;
		map<int, string> _fea_stitch_slot_to_uid_map;
        int maxLC; //Maximum allocated line-card number.
};
#endif //__FEA_STITCH_TREE_HH__
