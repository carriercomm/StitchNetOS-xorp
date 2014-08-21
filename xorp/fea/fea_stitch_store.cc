
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
#include "fea_stitch_store.hh"
#include "fea_module.h"
#include "libxorp/xlog.h"

FeaStitchInst::FeaStitchInst(string &UID, int LCId, IPvX &ip)
{
    this->UID = UID;
    this->LCId = LCId;
    this->ip = ip;
	this->last_port = 0;
}

unsigned int FeaStitchInst::getNextAvailPortNum()
{
	return ++last_port;
}

void FeaStitchInst::resetNextAvailPortNum()
{
	this->last_port = 0;
}

/* Create the slot to uid map from the file uid_map */
int FeaStitchStore::init_slot_num_to_uid_map ()
{
	int slot = 0;
	string uid;

	FILE *fp = fopen("/root/uid_map", "r");
	if (!fp)
		return 0;

	char *buf = 0;
	size_t buflen = 0;

	while(getline(&buf, &buflen, fp) > 0) {
		char *nl = strchr(buf, '\n');
		if (nl == NULL)
			continue;
		*nl = 0;

		char *sep = strchr(buf, '=');
		if (sep == NULL)
			continue;
		*sep = 0;
		sep++;

		slot = atoi(buf);
		uid = sep;

		_fea_stitch_slot_to_uid_map[slot] = uid;
	}

	if (buf) {
		 free(buf);
	}

	fclose(fp);

	 return slot;
}

FeaStitchStore::FeaStitchStore(EventLoop &events):_event_loop(events)
{
	this->maxLC = 0;
    this->maxLC = init_slot_num_to_uid_map();
}

int FeaStitchStore::getNextAvailLCId()
{
    return ++(this->maxLC);
}

int FeaStitchStore::find_fea_stitch_slot(const string &UID)
{
	map<int, string>::iterator _fea_stitch_it = _fea_stitch_slot_to_uid_map.begin();

    for (; _fea_stitch_it != _fea_stitch_slot_to_uid_map.end(); _fea_stitch_it++) {
		if (_fea_stitch_it->second == UID) {
			return (_fea_stitch_it->first);
		}
    }

    return -1;
}

/*
 *  FeaStitchStore::find_fea_stitch
 *  @param UID search fea stitch instance stored in the store matching this UID.
 *  @return FeaStitchInst returns an instance of fea stitch.
 *
 */
FeaStitchInst* FeaStitchStore::find_fea_stitch(const string& UID)
{
    map<std::string, FeaStitchInst>::iterator _fea_stitch_it = _fea_stitch_store.find(UID);
    if (_fea_stitch_it != _fea_stitch_store.end()) {
        return (FeaStitchInst*)(&_fea_stitch_it->second);
    }

    return NULL;

}

FeaStitchInst* FeaStitchStore::find_fea_stitch(const int LCId)
{
    map<std::string, FeaStitchInst>::iterator _fea_stitch_it = _fea_stitch_store.begin();

    for (; _fea_stitch_it != _fea_stitch_store.end(); _fea_stitch_it++) {
        if (_fea_stitch_it->second.LCId == LCId) {
            return (FeaStitchInst*)(&_fea_stitch_it->second);
        }
    }

    return NULL;

}

FeaStitchInst* FeaStitchStore::find_fea_stitch(const IPvX &ip)
{
    FeaStitchStoreIt _fea_stitch_it = _fea_stitch_store.begin();

    for (; _fea_stitch_it != _fea_stitch_store.end(); _fea_stitch_it++) {
        if (_fea_stitch_it->second.ip == ip) {
            return (FeaStitchInst*)(&_fea_stitch_it->second);
        }
    }

    return NULL;

}


void FeaStitchStore::add(string &UID, int LCId, IPvX &ip)
{
    _fea_stitch_store.insert(std::make_pair(UID, FeaStitchInst(UID, LCId, ip)));
}

void FeaStitchStore::add(FeaStitchInst& _fea_stitch)
{
    _fea_stitch_store.insert(std::make_pair(_fea_stitch.UID, _fea_stitch));

}

bool FeaStitchStore::remove(const string &UID)
{
    FeaStitchStoreIt it = _fea_stitch_store.find(UID);
    if (it == _fea_stitch_store.end()) {
        return false;
    } else {
        _fea_stitch_store.erase(it);
    }
    return true;
}

bool FeaStitchStore::remove(const int &LCId)
{
    FeaStitchStoreIt it = _fea_stitch_store.begin();
    for (; it != _fea_stitch_store.end(); it++) {
       if (it->second.LCId == LCId) {
        _fea_stitch_store.erase(it);
        return true;

       }
    }
    return false;
}

bool FeaStitchStore::remove(const IPvX &ip)
{
    FeaStitchStoreIt it = _fea_stitch_store.begin();
    for (; it != _fea_stitch_store.end(); it++) {
       if (it->second.ip == ip) {
        _fea_stitch_store.erase(it);
        return true;

       }
    }
    return false;
}

void FeaStitchStore::allocUID(string& UID)
{
    TimeVal curr_time;
    _event_loop.current_time(curr_time);
    UID = curr_time.str();
}

void FeaStitchStore::insert_slot_to_uid_mapping (int slot, string uid)
{
	_fea_stitch_slot_to_uid_map[slot] = uid;

	FILE *fp = fopen("/root/uid_map", "a");
    if (!fp) {
		XLOG_INFO("Not able to open file for writing");
        return;
    }

    fprintf(fp, "%d=%s\n", slot, uid.c_str());

    fclose(fp);
}
