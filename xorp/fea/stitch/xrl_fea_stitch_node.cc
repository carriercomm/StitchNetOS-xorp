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


#include "xrl_fea_stitch_node.hh"


XrlFeaStitchNode::XrlFeaStitchNode(EventLoop& eventloop,
            const string& UID,
            const string& finder_hostname,
            const uint16_t finder_port,
            const string& finder_target,
            const string& fea_target ) :
            XrlStdRouter(eventloop, UID.c_str(), finder_hostname.c_str(), finder_port),
            XrlFeastitchTargetBase(&xrl_router()),
             _xrl_fea_io(eventloop, *this, finder_target),
             _fea_stitch_node(eventloop,"stitch_port_tree", "stitch_if_tree", _xrl_fea_io, xrl_router()),
            _finder_target(finder_target),
            _fea_target(fea_target),
            _xrl_fea_stitch_ifconfig(&xrl_router()),
            _xrl_fea_stitch_register(&xrl_router())

{
    this->_UID = UID;
    _status = FEA_STITCH_SHUTDOWN;
}

XrlFeaStitchNode::~XrlFeaStitchNode()
{
}

void XrlFeaStitchNode::fea_stitch_register_cb(const XrlError& xrl_error, const string* UID)
{
    switch(xrl_error.error_code()) {
        case OKAY:
            XLOG_INFO("Stitch LC-FEA registered successfully with FEA.UID:%s", UID->c_str());
            _status = FEA_STITCH_REGISTERED;
            this->_UID = *UID;
            break;
        case COMMAND_FAILED:
            XLOG_INFO("Could not register with FEA.");
            break;
        default:
            XLOG_INFO("FEA returned unkown error.:%d", xrl_error.error_code());
            break;
    }

}


int XrlFeaStitchNode::init(void)
{
    bool success = true;
    IPv4 ip;

    _status = FEA_STITCH_BOOTING;
    XLOG_INFO("Registering with global FEA with UID:%s", this->_UID.c_str());
    success = _xrl_fea_stitch_register.send_register_fea_stitch("fea", ip, this->_UID,
    callback(this, &XrlFeaStitchNode::fea_stitch_register_cb));

    if (!success) {
        XLOG_WARNING("Unable to register with global FEA");
        return XORP_ERROR;
    }

    XLOG_INFO("Successfully sent the registration request to FEA");

    return XORP_OK;
}

/**
 * Start the node. Read the physical ports and build a port map.
 */
int XrlFeaStitchNode::startup(void)
{
    //start the stitch node. This in turn should initialize the data-plane
    //manager.
    _fea_stitch_node.startup();
    return XORP_OK;
}

int XrlFeaStitchNode::shutdown(void)
{
    _status = FEA_STITCH_SHUTDOWN;
    XLOG_INFO("Shutting down XRL interface of FEA stitch node");
    return XORP_OK;
}

bool XrlFeaStitchNode::registered(void)
{
    return (this->_status == FEA_STITCH_REGISTERED);
}


bool XrlFeaStitchNode::is_done(void)
{
    return (this->_status != FEA_STITCH_REGISTERED);
}

XrlCmdError XrlFeaStitchNode::fea_stitch_0_1_enable_fea_stitch( const bool& enable)
{
    XLOG_INFO("Trying to enable:%d fea stitch node", enable);
    return XrlCmdError::OKAY();
}

XrlCmdError XrlFeaStitchNode::fea_stitch_0_1_start_fea_stitch()
{
    return XrlCmdError::OKAY();
}

XrlCmdError XrlFeaStitchNode::fea_stitch_0_1_stop_fea_stitch()
{
    return XrlCmdError::OKAY();
}

XrlCmdError XrlFeaStitchNode::fea_stitch_0_1_print_hello_world( const string&   str)
{
    XLOG_INFO("Received:%s",str.c_str());
    return XrlCmdError::OKAY();
}

XrlCmdError XrlFeaStitchNode::fea_stitch_0_1_enable_log_trace_all( const bool& enable)
{
    XLOG_INFO("FEA stitch log %d", enable);
    return XrlCmdError::OKAY();
}

void XrlFeaStitchNode::upload_port_information_to_fea_cb(const XrlError& xrl_error, const string* ifname, const uint32_t* port_num)
{
    switch(xrl_error.error_code()) {
        case OKAY:
            XLOG_INFO("Port information updated successfully in FEA. Returned port num: %u", *port_num);
			if (*port_num) {
				_fea_stitch_node.insert_port_num_to_intf_name_map(*port_num, *ifname);
			}
            break;
        case COMMAND_FAILED:
            XLOG_INFO("Could not update port information to FEA.");
            break;
        default:
            XLOG_INFO("FEA returned unkown error.:%d", xrl_error.error_code());
            break;
    }
}

int XrlFeaStitchNode::upload_port_information_to_fea(void)
{
    bool success = true;
	//IfTree *iftree = new IfTree("lc-system-config");
	IfTree::IfMap::const_iterator iter;
	unsigned int port_num;

	XLOG_INFO("Uploading port information to CP-FEA");



    for (iter = fea_stitch_node().if_tree().interfaces().begin();
	 	 iter != fea_stitch_node().if_tree().interfaces().end(); ++iter) {

		const IfTreeInterface& iface = *(iter->second);

		// Skip loopback interfaces
		if (strncmp(iface.ifname().c_str(), "lo", 2) == 0) {
			continue;
		}

		port_num = _fea_stitch_node.find_port_num_from_intf_name(iface.ifname());

		success = _xrl_fea_stitch_ifconfig.send_upload_port_information("fea",
						getUID().c_str(), iface.ifname().c_str(), port_num, iface.pif_index(), iface.mac(),
			        	iface.interface_flags(), iface.mtu(), iface.baudrate(), iface.no_carrier(),
			        	callback(this, &XrlFeaStitchNode::upload_port_information_to_fea_cb));

		if (!success) {
	        XLOG_WARNING("Unable to update port information to FEA");
	        return XORP_ERROR;
	    }
	}

    return XORP_OK;
}

XrlCmdError XrlFeaStitchNode::fea_stitch_0_1_add_addr(
	const string&	ifname,
	const string&	vifname,
	const uint32_t&	if_index,
	const IPv4&	addr,
	const uint32_t&	prefix_len,
	const bool&	is_broadcast,
	const IPv4&	broadcast_addr,
	const bool&	is_point_to_point,
	const IPv4&	endpoint_addr,
	// Output values,
	string&	error_msg)
{
	UNUSED(if_index);
	UNUSED(vifname);

	string real_intf_name = fea_stitch_node().port_num_to_intf_map()[atoi(ifname.c_str())];
	XLOG_INFO("FEA stitch add addr intf num %s name %s", ifname.c_str(), real_intf_name.c_str());

	IfTreeInterface *config_iface = fea_stitch_node().if_tree().find_interface(real_intf_name);

	//front=end anyways ensures that the ifname and the vifname are the same
	IfTreeVif *config_vif = fea_stitch_node().if_tree().find_vif(real_intf_name, real_intf_name);

	IfTreeAddr4 *config_addr = new IfTreeAddr4(addr);
	config_addr->set_prefix_len(prefix_len);
	config_addr->set_broadcast(is_broadcast);
	config_addr->set_bcast(broadcast_addr);
	config_addr->set_point_to_point(is_point_to_point);
	config_addr->set_endpoint(endpoint_addr);

	_fea_stitch_node.stitch_dpm_linux()->ifconfig_set()->config_add_address(NULL, NULL, NULL, *config_iface, *config_vif, *config_addr, error_msg);

    return XrlCmdError::OKAY();
}
