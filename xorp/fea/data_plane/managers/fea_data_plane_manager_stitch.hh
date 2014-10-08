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
#ifndef __FEA_DATA_PLANE_MANAGERS_FEA_DATA_PLANE_MANAGER_STITCH_HH__
#define __FEA_DATA_PLANE_MANAGERS_FEA_DATA_PLANE_MANAGER_STITCH_HH__
#include "libxipc/xrl_std_router.hh"
#include "fea/fea_data_plane_manager.hh"

#include "xrl/interfaces/fea_stitch_xif.hh"

class FeaDataPlaneManagerStitch : public FeaDataPlaneManager {

    public:
        /**
         * Constructor.
         * @param finder the XRL router for XORP.
         */
        FeaDataPlaneManagerStitch(FeaNode& fea_node, XrlRouter& _xrl_router);
		/**
	     * Load the plugins.
	     *
	     * @param error_msg the error message (if error).
	     * @return XORP_OK on success, otherwise XORP_ERROR.
	     */
	    int load_plugins(string& error_msg);

	    /**
	     * Unload the plugins.
	     *
	     * @param error_msg the error message (if error).
	     * @return XORP_OK on success, otherwise XORP_ERROR.
	     */
	    int unload_plugins(string& error_msg);

	    /**
	     * Register the plugins.
	     *
	     * @param error_msg the error message (if error).
	     * @return XORP_OK on success, otherwise XORP_ERROR.
	     */
	    int register_plugins(string& error_msg);

	    /**
	     * Allocate IoLink plugin instance.
	     *
	     * @param iftree the interface tree to use.
	     * @param if_name the interface name.
	     * @param vif_name the vif name.
	     * @param ether_type the EtherType protocol number. If it is 0 then
	     * it is unused.
	     * @param filter_program the option filter program to be applied on the
	     * received packets. The program uses tcpdump(1) style expression.
	     * @return a new instance of @ref IoLink plugin on success, otherwise NULL.
	     */
	    IoLink* allocate_io_link(const IfTree& iftree,
				     const string& if_name,
				     const string& vif_name,
				     uint16_t ether_type,
				     const string& filter_program);

	    /**
	     * Allocate IoIp plugin instance.
	     *
	     * @param iftree the interface tree to use.
	     * @param family the address family (AF_INET or AF_INET6 for IPv4 and IPv6
	     * respectively).
	     * @param ip_protocol the IP protocol number (IPPROTO_*).
	     * @return a new instance of @ref IoIp plugin on success, otherwise NULL.
	     */
	    IoIp* allocate_io_ip(const IfTree& iftree, int family,
				 uint8_t ip_protocol);

	    /**
	     * Allocate IoTcpUdp plugin instance.
	     *
	     * @param iftree the interface tree to use.
	     * @param family the address family (AF_INET or AF_INET6 for IPv4 and IPv6
	     * respectively).
	     * @param is_tcp if true allocate a TCP entry, otherwise UDP.
	     * @return a new instance of @ref IoTcpUdp plugin on success,
	     * otherwise NULL.
	     */
	    IoTcpUdp* allocate_io_tcpudp(const IfTree& iftree, int family,
					 bool is_tcp);

		void print_lc_message(string& lc_message);
		XrlFeaStitchV0p1Client &stitch_lc_fea() {return _stitch_lc_fea;}

    private:
		XrlFeaStitchV0p1Client _stitch_lc_fea; //XRL interface to stitch LC FEA

};

#endif //STITCH
