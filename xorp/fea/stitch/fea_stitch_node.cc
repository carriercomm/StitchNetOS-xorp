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
#include "fea_stitch_node.hh"
#include "fea/data_plane/managers/fea_data_plane_manager_linux.hh"
FeaStitchNode::FeaStitchNode(EventLoop &event_loop, const string& _pt_name,
        const string& _ift_name, FeaIo&_fea_io):FeaNode(event_loop, _fea_io, false),
    _port_tree(_pt_name),
    _if_tree(_ift_name.c_str())
{
    _stitch_dpm_linux = new FeaDataPlaneManagerLinux(*this);
	init_port_num_to_intf_name_map();
}


int FeaStitchNode::startup()
{
    string error_str = "Unable to load the linux plugins for stitch FEA node";
    _stitch_dpm_linux->load_plugins(error_str);
	_stitch_dpm_linux->start_plugins(error_str);
    XLOG_INFO("Stitch FEA Node startup done");
    return XORP_OK;
}


int FeaStitchNode::shutdown()
{
    return FeaNode::shutdown();
}

/* Create the port num to intf name map from file port_map*/
void FeaStitchNode::init_port_num_to_intf_name_map()
{
	int port = 0;
	string intf_name;

    FILE *fp = fopen("/root/port_map", "r");
    if (!fp)
        return;

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

        port = atoi(buf);
        intf_name = sep;

        _port_num_to_intf_map[port] = intf_name;
    }

    if (buf)
        free(buf);

    fclose(fp);
}

void FeaStitchNode::insert_port_num_to_intf_name_map(int port, string intf_name) {
	_port_num_to_intf_map[port] = intf_name;

	FILE *fp = fopen("/root/port_map", "a");
    if (!fp) {
		XLOG_INFO("Not able to open file for writing");
        return;
    }

    fprintf(fp, "%d=%s\n", port, intf_name.c_str());

    fclose(fp);
}

uint32_t FeaStitchNode::find_port_num_from_intf_name(const string intf_name)
{
    map<uint32_t, string>::iterator _port_map_it = _port_num_to_intf_map.begin();

    for (; _port_map_it != _port_num_to_intf_map.end(); _port_map_it++) {
        if (_port_map_it->second == intf_name) {
            return (_port_map_it->first);
        }
    }

    return 0;
}

