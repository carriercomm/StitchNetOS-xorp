// -*- c-basic-offset: 4; tab-width: 8; indent-tabs-mode: t -*-

// Copyright (c) 2001-2003 International Computer Science Institute
//
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software")
// to deal in the Software without restriction, subject to the conditions
// listed in the XORP LICENSE file. These conditions include: you must
// preserve this copyright notice, and you cannot mention the copyright
// holders in advertising related to the Software without their permission.
// The Software is provided WITHOUT ANY WARRANTY, EXPRESS OR IMPLIED. This
// notice is a summary of the XORP LICENSE file; the license in that file is
// legally binding.

// $XORP: xorp/fib2mrib/fib2mrib_node.hh,v 1.2 2004/03/18 13:17:21 pavlin Exp $

#ifndef __FIB2MRIB_FIB2MRIB_NODE_HH__
#define __FIB2MRIB_FIB2MRIB_NODE_HH__


//
// Fib2mrib node definition.
//

#include <map>

#include "libxorp/service.hh"
#include "libxorp/status_codes.h"

#include "libfeaclient/ifmgr_xrl_mirror.hh"


class EventLoop;

/**
 * @short A Fib2mrib helper class.
 * 
 * This class is used to store a routing entry.
 */
class Fib2mribRoute {
public:
    /**
     * Constructor for a given IPv4 route.
     * 
     * @param network the network address prefix this route applies to.
     * @param nexthop the address of the next-hop router for this route.
     * @param ifname the name of the physical interface toward the
     * destination.
     * @param vifname the name of the virtual interface toward the
     * destination.
     * @param metric the routing metric for this route.
     * @param admin_distance the administratively defined distance for this
     * route.
     * @param protocol_origin the name of the protocol that originated this
     * route.
     * @param xorp_route true if this route was installed by XORP.
     */
    Fib2mribRoute(const IPv4Net& network, const IPv4& nexthop,
		  const string& ifname, const string& vifname,
		  uint32_t metric, uint32_t admin_distance,
		  const string& protocol_origin, bool xorp_route)
	: _network(network), _nexthop(nexthop),
	  _ifname(ifname), _vifname(vifname),
	  _metric(metric), _admin_distance(admin_distance),
	  _protocol_origin(protocol_origin), _xorp_route(xorp_route) {}

    /**
     * Constructor for a given IPv6 route.
     * 
     * @param network the network address prefix this route applies to.
     * @param nexthop the address of the next-hop router for this route.
     * @param ifname the name of the physical interface toward the
     * destination.
     * @param vifname the name of the virtual interface toward the
     * destination.
     * @param metric the routing metric for this route.
     * @param admin_distance the administratively defined distance for this
     * route.
     * @param protocol_origin the name of the protocol that originated this
     * route.
     * @param xorp_route true if this route was installed by XORP.
     */
    Fib2mribRoute(const IPv6Net& network, const IPv6& nexthop,
		  const string& ifname, const string& vifname,
		  uint32_t metric, uint32_t admin_distance,
		  const string& protocol_origin, bool xorp_route)
	: _network(network), _nexthop(nexthop),
	  _ifname(ifname), _vifname(vifname),
	  _metric(metric), _admin_distance(admin_distance),
	  _protocol_origin(protocol_origin), _xorp_route(xorp_route) {}

    /**
     * Test if this is an IPv4 route.
     * 
     * @return true if this is an IPv4 route, otherwise false.
     */
    bool is_ipv4() const { return _network.is_ipv4(); }

    /**
     * Test if this is an IPv6 route.
     * 
     * @return true if this is an IPv6 route, otherwise false.
     */
    bool is_ipv6() const { return _network.is_ipv6(); }

    /**
     * Get the network address prefix this route applies to.
     * 
     * @return the network address prefix this route appies to.
     */
    const IPvXNet& network() const { return _network; }

    /**
     * Get the address of the next-hop router for this route.
     * 
     * @return the address of the next-hop router for this route.
     */
    const IPvX& nexthop() const { return _nexthop; }

    /**
     * Get the name of the physical interface toward the destination.
     * 
     * @return the name of the physical interface toward the destination.
     */
    const string& ifname() const { return _ifname; }

    /**
     * Get the name of the virtual interface toward the destination.
     * 
     * @return the name of the virtual interface toward the destination.
     */
    const string& vifname() const { return _vifname; }

    /**
     * Get the the administratively defined distance for this route.
     * 
     * @return the administratively defined distance for this route.
     */
    uint32_t admin_distance() const { return _admin_distance; }

    /**
     * Get the metric distance for this route.
     * 
     * @return the metric distance for this route.
     */
    uint32_t metric() const { return _metric; }

    /**
     * Get the name of the protocol that originated this route.
     * 
     * @return the name of the protocol that originated this route.
     */
    const string& protocol_origin() const { return _protocol_origin; }

    /**
     * Test if this route was installed by XORP.
     * 
     * @return true if this route was installed by XORP.
     */
    bool xorp_route() const { return _xorp_route; }

    /**
     * Test if this is a route to add.
     * 
     * @return true if this is a route to add, otherwise false.
     */
    bool is_add_route() const { return (_route_type == ADD_ROUTE); }

    /**
     * Test if this is a replacement route.
     * 
     * @return true if this is a replacement route, otherwise false.
     */
    bool is_replace_route() const { return (_route_type == REPLACE_ROUTE); }

    /**
     * Test if this is a route to delete.
     * 
     * @return true if this is a route to delete, otherwise false.
     */
    bool is_delete_route() const { return (_route_type == DELETE_ROUTE); }

    /**
     * Set the type of this route to "a route to add".
     */
    void set_add_route() { _route_type = ADD_ROUTE; }

    /**
     * Set the type of this route to "a replacement route".
     */
    void set_replace_route() { _route_type = REPLACE_ROUTE; }

    /**
     * Set the type of this route to "a route to delete".
     */
    void set_delete_route() { _route_type = DELETE_ROUTE; }

    /**
     * Test if the route is interface-specific (e.g., if the interface
     * is explicitly specified).
     * 
     * @return true if the route is interface-specific, otherwise false.
     */
    bool is_interface_route() const { return ! (_ifname.empty()
						&& _vifname.empty()); }

    /**
     * Check whether the route entry is valid.
     * 
     * @param error_msg the error message (if error).
     * @return true if the route entry is valid, otherwise false.
     */
    bool is_valid_entry(string& error_msg) const;

private:
    IPvXNet	_network;
    IPvX	_nexthop;
    string	_ifname;
    string	_vifname;
    uint32_t	_metric;
    uint32_t	_admin_distance;
    string	_protocol_origin;
    bool	_xorp_route;
    enum RouteType { ADD_ROUTE, REPLACE_ROUTE, DELETE_ROUTE };
    RouteType	_route_type;
};


/**
 * @short The Fib2mrib node class.
 * 
 * There should be one node per Fib2mrib instance.
 */
class Fib2mribNode : public IfMgrHintObserver, public ServiceBase {
public:
    /**
     * Constructor for a given event loop.
     * 
     * @param eventloop the event loop to use.
     */
    Fib2mribNode(EventLoop& eventloop);

    /**
     * Destructor
     */
    virtual ~Fib2mribNode();

    /**
     * Get the event loop this node is added to.
     * 
     * @return the event loop this node is added to.
     */
    EventLoop&	eventloop()	{ return _eventloop; }

    /**
     * Get the protocol name.
     * 
     * @return a string with the protocol name.
     */
    const string& protocol_name() const { return _protocol_name; }

    /**
     * Start the node operation.
     */
    void	startup();

    /**
     * Shutdown the node operation.
     */
    void	shutdown();

    /**
     * Get the node status (see @ref ProcessStatus).
     * 
     * @param reason_msg return-by-reference string that contains
     * human-readable information about the status.
     * @return the node status (see @ref ProcessStatus).
     */
    ProcessStatus	node_status(string& reason_msg);

    /**
     * Test if the node processing is done.
     * 
     * @return true if the node processing is done, otherwise false.
     */
    bool	is_done() const { return (_node_status == PROC_DONE); }

    /**
     * Add an IPv4 route.
     *
     * @param network the network address prefix this route applies to.
     * @param nexthop the address of the next-hop router for this route.
     * @param ifname the name of the physical interface toward the
     * destination.
     * @param vifname the name of the virtual interface toward the
     * destination.
     * @param metric the routing metric for this route.
     * @param admin_distance the administratively defined distance for this
     * route.
     * @param protocol_origin the name of the protocol that originated this
     * route.
     * @param xorp_route true if this route was installed by XORP.
     * @param error_msg the error message (if error).
     * @return XORP_OK on success, otherwise XORP_ERROR.
     */
    int add_route4(const IPv4Net& network, const IPv4& nexthop,
		   const string& ifname, const string& vifname,
		   uint32_t metric, uint32_t admin_distance,
		   const string& protocol_origin, bool xorp_route,
		   string& error_msg);

    /**
     * Add an IPv6 route.
     *
     * @param network the network address prefix this route applies to.
     * @param nexthop the address of the next-hop router for this route.
     * @param ifname the name of the physical interface toward the
     * destination.
     * @param vifname the name of the virtual interface toward the
     * destination.
     * @param metric the routing metric for this route.
     * @param admin_distance the administratively defined distance for this
     * route.
     * @param protocol_origin the name of the protocol that originated this
     * route.
     * @param xorp_route true if this route was installed by XORP.
     * @param error_msg the error message (if error).
     * @return XORP_OK on success, otherwise XORP_ERROR.
     */
    int add_route6(const IPv6Net& network, const IPv6& nexthop,
		   const string& ifname, const string& vifname,
		   uint32_t metric, uint32_t admin_distance,
		   const string& protocol_origin, bool xorp_route,
		   string& error_msg);

    /**
     * Replace an IPv4 route.
     *
     * @param network the network address prefix this route applies to.
     * @param nexthop the address of the next-hop router for this route.
     * @param ifname the name of the physical interface toward the
     * destination.
     * @param vifname the name of the virtual interface toward the
     * destination.
     * @param metric the routing metric for this route.
     * @param admin_distance the administratively defined distance for this
     * route.
     * @param protocol_origin the name of the protocol that originated this
     * route.
     * @param xorp_route true if this route was installed by XORP.
     * @param error_msg the error message (if error).
     * @return XORP_OK on success, otherwise XORP_ERROR.
     */
    int replace_route4(const IPv4Net& network, const IPv4& nexthop,
		       const string& ifname, const string& vifname,
		       uint32_t metric, uint32_t admin_distance,
		       const string& protocol_origin, bool xorp_route,
		       string& error_msg);

    /**
     * Replace an IPv6 route.
     *
     * @param network the network address prefix this route applies to.
     * @param nexthop the address of the next-hop router for this route.
     * @param ifname the name of the physical interface toward the
     * destination.
     * @param vifname the name of the virtual interface toward the
     * destination.
     * @param metric the routing metric for this route.
     * @param admin_distance the administratively defined distance for this
     * route.
     * @param protocol_origin the name of the protocol that originated this
     * route.
     * @param xorp_route true if this route was installed by XORP.
     * @param error_msg the error message (if error).
     * @return XORP_OK on success, otherwise XORP_ERROR.
     */
    int replace_route6(const IPv6Net& network, const IPv6& nexthop,
		       const string& ifname, const string& vifname,
		       uint32_t metric, uint32_t admin_distance,
		       const string& protocol_origin, bool xorp_route,
		       string& error_msg);

    /**
     * Delete an IPv4 route.
     *
     * @param network the network address prefix this route applies to.
     * @param ifname the name of the physical interface toward the
     * destination.
     * @param vifname the name of the virtual interface toward the
     * destination.
     * @param error_msg the error message (if error).
     * @return XORP_OK on success, otherwise XORP_ERROR.
     */
    int delete_route4(const IPv4Net& network, const string& ifname,
		      const string& vifname, string& error_msg);

    /**
     * Delete an IPv6 route.
     *
     * @param network the network address prefix this route applies to.
     * @param ifname the name of the physical interface toward the
     * destination.
     * @param vifname the name of the virtual interface toward the
     * destination.
     * @param error_msg the error message (if error).
     * @return XORP_OK on success, otherwise XORP_ERROR.
     */
    int delete_route6(const IPv6Net& network, const string& ifname,
		      const string& vifname, string& error_msg);

    //
    // Debug-related methods
    //
    
    /**
     * Test if trace log is enabled.
     * 
     * This method is used to test whether to output trace log debug messges.
     * 
     * @return true if trace log is enabled, otherwise false.
     */
    bool	is_log_trace() const { return (_is_log_trace); }
    
    /**
     * Enable/disable trace log.
     * 
     * This method is used to enable/disable trace log debug messages output.
     * 
     * @param is_enabled if true, trace log is enabled, otherwise is disabled.
     */
    void	set_log_trace(bool is_enabled) { _is_log_trace = is_enabled; }

protected:
    //
    // IfMgrHintObserver methods
    //
    void tree_complete();
    void updates_made();

    void incr_startup_requests_n();
    void decr_startup_requests_n();
    void incr_shutdown_requests_n();
    void decr_shutdown_requests_n();
    void update_status();

private:
    /**
     * Initiate startup of the interface manager.
     * 
     * This is a pure virtual function, and it must be implemented
     * by the communication-wrapper class that inherits this base class.
     */
    virtual void ifmgr_startup() = 0;

    /**
     * Initiate shutdown of the interface manager.
     * 
     * This is a pure virtual function, and it must be implemented
     * by the communication-wrapper class that inherits this base class.
     */
    virtual void ifmgr_shutdown() = 0;

    /**
     * Initiate registration as an FEA FIB client.
     * 
     * This is a pure virtual function, and it must be implemented
     * by the communication-wrapper class that inherits this base class.
     */
    virtual void fea_fib_client_register_startup() = 0;

    /**
     * Initiate de-registration as an FEA FIB client.
     * 
     * This is a pure virtual function, and it must be implemented
     * by the communication-wrapper class that inherits this base class.
     */
    virtual void fea_fib_client_register_shutdown() = 0;

    /**
     * Initiate registration with the RIB.
     * 
     * This is a pure virtual function, and it must be implemented
     * by the communication-wrapper class that inherits this base class.
     */
    virtual void rib_register_startup() = 0;

    /**
     * Initiate de-registration with the RIB.
     * 
     * This is a pure virtual function, and it must be implemented
     * by the communication-wrapper class that inherits this base class.
     */
    virtual void rib_register_shutdown() = 0;

    /**
     * Add an IPvX route.
     *
     * @param fib2mrib_route the route to add.
     * @see Fib2mribRoute
     * @param error_msg the error message (if error).
     * @return XORP_OK on success, otherwise XORP_ERROR.
     */
    int add_route(const Fib2mribRoute& fib2mrib_route, string& error_msg);

    /**
     * Replace a Fib2mrib IPvX route.
     *
     * @param fib2mrib_route the replacement route.
     * @see Fib2mribRoute
     * @param error_msg the error message (if error).
     * @return XORP_OK on success, otherwise XORP_ERROR.
     */
    int replace_route(const Fib2mribRoute& fib2mrib_route, string& error_msg);

    /**
     * Delete a Fib2mrib IPvX route.
     *
     * @param fib2mrib_route the route to delete.
     * @see Fib2mribRoute
     * @param error_msg the error message (if error).
     * @return XORP_OK on success, otherwise XORP_ERROR.
     */
    int delete_route(const Fib2mribRoute& fib2mrib_route, string& error_msg);

    /**
     * Inform the RIB about a route change.
     *
     * This is a pure virtual function, and it must be implemented
     * by the communication-wrapper class that inherits this base class.
     *
     * @param fib2mrib_route the route with the information about the change.
     */
    virtual void inform_rib_route_change(const Fib2mribRoute& fib2mrib_route) = 0;

    virtual const IfMgrIfTree&	iftree() const = 0;

    EventLoop&		_eventloop;		// The event loop
    ProcessStatus	_node_status;		// The node/process status
    const string	_protocol_name;		// The protocol name

    list<Fib2mribRoute>	_fib2mrib_routes;

    size_t		_startup_requests_n;
    size_t		_shutdown_requests_n;

    //
    // Debug and test-related state
    //
    bool	_is_log_trace;		// If true, enable XLOG_TRACE()
};

#endif // __FIB2MRIB_FIB2MRIB_NODE_HH__
