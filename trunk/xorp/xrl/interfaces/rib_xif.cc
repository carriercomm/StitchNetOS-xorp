/*
 * Copyright (c) 2001-2003 International Computer Science Institute
 * See LICENSE file for licensing, conditions, and warranties on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by 'clnt-gen'.
 */

#ident "$XORP: xorp/xrl/interfaces/rib_xif.cc,v 1.15 2003/11/18 01:47:34 hodson Exp $"

#include "rib_xif.hh"

bool
XrlRibV0p1Client::send_enable_rib(
	const char*	the_tgt,
	const EnableRibCB&	cb
)
{
    Xrl x(the_tgt, "rib/0.1/enable_rib");
    return _sender->send(x, callback(this, &XrlRibV0p1Client::unmarshall_enable_rib, cb));
}


/* Unmarshall enable_rib */
void
XrlRibV0p1Client::unmarshall_enable_rib(
	const XrlError&	e,
	XrlArgs*	a,
	EnableRibCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlRibV0p1Client::send_disable_rib(
	const char*	the_tgt,
	const DisableRibCB&	cb
)
{
    Xrl x(the_tgt, "rib/0.1/disable_rib");
    return _sender->send(x, callback(this, &XrlRibV0p1Client::unmarshall_disable_rib, cb));
}


/* Unmarshall disable_rib */
void
XrlRibV0p1Client::unmarshall_disable_rib(
	const XrlError&	e,
	XrlArgs*	a,
	DisableRibCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlRibV0p1Client::send_start_rib(
	const char*	the_tgt,
	const StartRibCB&	cb
)
{
    Xrl x(the_tgt, "rib/0.1/start_rib");
    return _sender->send(x, callback(this, &XrlRibV0p1Client::unmarshall_start_rib, cb));
}


/* Unmarshall start_rib */
void
XrlRibV0p1Client::unmarshall_start_rib(
	const XrlError&	e,
	XrlArgs*	a,
	StartRibCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlRibV0p1Client::send_stop_rib(
	const char*	the_tgt,
	const StopRibCB&	cb
)
{
    Xrl x(the_tgt, "rib/0.1/stop_rib");
    return _sender->send(x, callback(this, &XrlRibV0p1Client::unmarshall_stop_rib, cb));
}


/* Unmarshall stop_rib */
void
XrlRibV0p1Client::unmarshall_stop_rib(
	const XrlError&	e,
	XrlArgs*	a,
	StopRibCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlRibV0p1Client::send_add_rib_client4(
	const char*	the_tgt,
	const string&	target_name,
	const bool&	unicast,
	const bool&	multicast,
	const AddRibClient4CB&	cb
)
{
    Xrl x(the_tgt, "rib/0.1/add_rib_client4");
    x.args().add("target_name", target_name);
    x.args().add("unicast", unicast);
    x.args().add("multicast", multicast);
    return _sender->send(x, callback(this, &XrlRibV0p1Client::unmarshall_add_rib_client4, cb));
}


/* Unmarshall add_rib_client4 */
void
XrlRibV0p1Client::unmarshall_add_rib_client4(
	const XrlError&	e,
	XrlArgs*	a,
	AddRibClient4CB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlRibV0p1Client::send_add_rib_client6(
	const char*	the_tgt,
	const string&	target_name,
	const bool&	unicast,
	const bool&	multicast,
	const AddRibClient6CB&	cb
)
{
    Xrl x(the_tgt, "rib/0.1/add_rib_client6");
    x.args().add("target_name", target_name);
    x.args().add("unicast", unicast);
    x.args().add("multicast", multicast);
    return _sender->send(x, callback(this, &XrlRibV0p1Client::unmarshall_add_rib_client6, cb));
}


/* Unmarshall add_rib_client6 */
void
XrlRibV0p1Client::unmarshall_add_rib_client6(
	const XrlError&	e,
	XrlArgs*	a,
	AddRibClient6CB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlRibV0p1Client::send_delete_rib_client4(
	const char*	the_tgt,
	const string&	target_name,
	const bool&	unicast,
	const bool&	multicast,
	const DeleteRibClient4CB&	cb
)
{
    Xrl x(the_tgt, "rib/0.1/delete_rib_client4");
    x.args().add("target_name", target_name);
    x.args().add("unicast", unicast);
    x.args().add("multicast", multicast);
    return _sender->send(x, callback(this, &XrlRibV0p1Client::unmarshall_delete_rib_client4, cb));
}


/* Unmarshall delete_rib_client4 */
void
XrlRibV0p1Client::unmarshall_delete_rib_client4(
	const XrlError&	e,
	XrlArgs*	a,
	DeleteRibClient4CB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlRibV0p1Client::send_delete_rib_client6(
	const char*	the_tgt,
	const string&	target_name,
	const bool&	unicast,
	const bool&	multicast,
	const DeleteRibClient6CB&	cb
)
{
    Xrl x(the_tgt, "rib/0.1/delete_rib_client6");
    x.args().add("target_name", target_name);
    x.args().add("unicast", unicast);
    x.args().add("multicast", multicast);
    return _sender->send(x, callback(this, &XrlRibV0p1Client::unmarshall_delete_rib_client6, cb));
}


/* Unmarshall delete_rib_client6 */
void
XrlRibV0p1Client::unmarshall_delete_rib_client6(
	const XrlError&	e,
	XrlArgs*	a,
	DeleteRibClient6CB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlRibV0p1Client::send_enable_rib_client4(
	const char*	the_tgt,
	const string&	target_name,
	const bool&	unicast,
	const bool&	multicast,
	const EnableRibClient4CB&	cb
)
{
    Xrl x(the_tgt, "rib/0.1/enable_rib_client4");
    x.args().add("target_name", target_name);
    x.args().add("unicast", unicast);
    x.args().add("multicast", multicast);
    return _sender->send(x, callback(this, &XrlRibV0p1Client::unmarshall_enable_rib_client4, cb));
}


/* Unmarshall enable_rib_client4 */
void
XrlRibV0p1Client::unmarshall_enable_rib_client4(
	const XrlError&	e,
	XrlArgs*	a,
	EnableRibClient4CB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlRibV0p1Client::send_enable_rib_client6(
	const char*	the_tgt,
	const string&	target_name,
	const bool&	unicast,
	const bool&	multicast,
	const EnableRibClient6CB&	cb
)
{
    Xrl x(the_tgt, "rib/0.1/enable_rib_client6");
    x.args().add("target_name", target_name);
    x.args().add("unicast", unicast);
    x.args().add("multicast", multicast);
    return _sender->send(x, callback(this, &XrlRibV0p1Client::unmarshall_enable_rib_client6, cb));
}


/* Unmarshall enable_rib_client6 */
void
XrlRibV0p1Client::unmarshall_enable_rib_client6(
	const XrlError&	e,
	XrlArgs*	a,
	EnableRibClient6CB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlRibV0p1Client::send_disable_rib_client4(
	const char*	the_tgt,
	const string&	target_name,
	const bool&	unicast,
	const bool&	multicast,
	const DisableRibClient4CB&	cb
)
{
    Xrl x(the_tgt, "rib/0.1/disable_rib_client4");
    x.args().add("target_name", target_name);
    x.args().add("unicast", unicast);
    x.args().add("multicast", multicast);
    return _sender->send(x, callback(this, &XrlRibV0p1Client::unmarshall_disable_rib_client4, cb));
}


/* Unmarshall disable_rib_client4 */
void
XrlRibV0p1Client::unmarshall_disable_rib_client4(
	const XrlError&	e,
	XrlArgs*	a,
	DisableRibClient4CB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlRibV0p1Client::send_disable_rib_client6(
	const char*	the_tgt,
	const string&	target_name,
	const bool&	unicast,
	const bool&	multicast,
	const DisableRibClient6CB&	cb
)
{
    Xrl x(the_tgt, "rib/0.1/disable_rib_client6");
    x.args().add("target_name", target_name);
    x.args().add("unicast", unicast);
    x.args().add("multicast", multicast);
    return _sender->send(x, callback(this, &XrlRibV0p1Client::unmarshall_disable_rib_client6, cb));
}


/* Unmarshall disable_rib_client6 */
void
XrlRibV0p1Client::unmarshall_disable_rib_client6(
	const XrlError&	e,
	XrlArgs*	a,
	DisableRibClient6CB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlRibV0p1Client::send_no_fea(
	const char*	the_tgt,
	const NoFeaCB&	cb
)
{
    Xrl x(the_tgt, "rib/0.1/no_fea");
    return _sender->send(x, callback(this, &XrlRibV0p1Client::unmarshall_no_fea, cb));
}


/* Unmarshall no_fea */
void
XrlRibV0p1Client::unmarshall_no_fea(
	const XrlError&	e,
	XrlArgs*	a,
	NoFeaCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlRibV0p1Client::send_make_errors_fatal(
	const char*	the_tgt,
	const MakeErrorsFatalCB&	cb
)
{
    Xrl x(the_tgt, "rib/0.1/make_errors_fatal");
    return _sender->send(x, callback(this, &XrlRibV0p1Client::unmarshall_make_errors_fatal, cb));
}


/* Unmarshall make_errors_fatal */
void
XrlRibV0p1Client::unmarshall_make_errors_fatal(
	const XrlError&	e,
	XrlArgs*	a,
	MakeErrorsFatalCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlRibV0p1Client::send_add_igp_table4(
	const char*	the_tgt,
	const string&	protocol,
	const string&	target_class,
	const string&	target_instance,
	const bool&	unicast,
	const bool&	multicast,
	const AddIgpTable4CB&	cb
)
{
    Xrl x(the_tgt, "rib/0.1/add_igp_table4");
    x.args().add("protocol", protocol);
    x.args().add("target_class", target_class);
    x.args().add("target_instance", target_instance);
    x.args().add("unicast", unicast);
    x.args().add("multicast", multicast);
    return _sender->send(x, callback(this, &XrlRibV0p1Client::unmarshall_add_igp_table4, cb));
}


/* Unmarshall add_igp_table4 */
void
XrlRibV0p1Client::unmarshall_add_igp_table4(
	const XrlError&	e,
	XrlArgs*	a,
	AddIgpTable4CB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlRibV0p1Client::send_add_igp_table6(
	const char*	the_tgt,
	const string&	protocol,
	const string&	target_class,
	const string&	target_instance,
	const bool&	unicast,
	const bool&	multicast,
	const AddIgpTable6CB&	cb
)
{
    Xrl x(the_tgt, "rib/0.1/add_igp_table6");
    x.args().add("protocol", protocol);
    x.args().add("target_class", target_class);
    x.args().add("target_instance", target_instance);
    x.args().add("unicast", unicast);
    x.args().add("multicast", multicast);
    return _sender->send(x, callback(this, &XrlRibV0p1Client::unmarshall_add_igp_table6, cb));
}


/* Unmarshall add_igp_table6 */
void
XrlRibV0p1Client::unmarshall_add_igp_table6(
	const XrlError&	e,
	XrlArgs*	a,
	AddIgpTable6CB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlRibV0p1Client::send_delete_igp_table4(
	const char*	the_tgt,
	const string&	protocol,
	const string&	target_class,
	const string&	target_instance,
	const bool&	unicast,
	const bool&	multicast,
	const DeleteIgpTable4CB&	cb
)
{
    Xrl x(the_tgt, "rib/0.1/delete_igp_table4");
    x.args().add("protocol", protocol);
    x.args().add("target_class", target_class);
    x.args().add("target_instance", target_instance);
    x.args().add("unicast", unicast);
    x.args().add("multicast", multicast);
    return _sender->send(x, callback(this, &XrlRibV0p1Client::unmarshall_delete_igp_table4, cb));
}


/* Unmarshall delete_igp_table4 */
void
XrlRibV0p1Client::unmarshall_delete_igp_table4(
	const XrlError&	e,
	XrlArgs*	a,
	DeleteIgpTable4CB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlRibV0p1Client::send_delete_igp_table6(
	const char*	the_tgt,
	const string&	protocol,
	const string&	target_class,
	const string&	target_instance,
	const bool&	unicast,
	const bool&	multicast,
	const DeleteIgpTable6CB&	cb
)
{
    Xrl x(the_tgt, "rib/0.1/delete_igp_table6");
    x.args().add("protocol", protocol);
    x.args().add("target_class", target_class);
    x.args().add("target_instance", target_instance);
    x.args().add("unicast", unicast);
    x.args().add("multicast", multicast);
    return _sender->send(x, callback(this, &XrlRibV0p1Client::unmarshall_delete_igp_table6, cb));
}


/* Unmarshall delete_igp_table6 */
void
XrlRibV0p1Client::unmarshall_delete_igp_table6(
	const XrlError&	e,
	XrlArgs*	a,
	DeleteIgpTable6CB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlRibV0p1Client::send_add_egp_table4(
	const char*	the_tgt,
	const string&	protocol,
	const string&	target_class,
	const string&	target_instance,
	const bool&	unicast,
	const bool&	multicast,
	const AddEgpTable4CB&	cb
)
{
    Xrl x(the_tgt, "rib/0.1/add_egp_table4");
    x.args().add("protocol", protocol);
    x.args().add("target_class", target_class);
    x.args().add("target_instance", target_instance);
    x.args().add("unicast", unicast);
    x.args().add("multicast", multicast);
    return _sender->send(x, callback(this, &XrlRibV0p1Client::unmarshall_add_egp_table4, cb));
}


/* Unmarshall add_egp_table4 */
void
XrlRibV0p1Client::unmarshall_add_egp_table4(
	const XrlError&	e,
	XrlArgs*	a,
	AddEgpTable4CB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlRibV0p1Client::send_add_egp_table6(
	const char*	the_tgt,
	const string&	protocol,
	const string&	target_class,
	const string&	target_instance,
	const bool&	unicast,
	const bool&	multicast,
	const AddEgpTable6CB&	cb
)
{
    Xrl x(the_tgt, "rib/0.1/add_egp_table6");
    x.args().add("protocol", protocol);
    x.args().add("target_class", target_class);
    x.args().add("target_instance", target_instance);
    x.args().add("unicast", unicast);
    x.args().add("multicast", multicast);
    return _sender->send(x, callback(this, &XrlRibV0p1Client::unmarshall_add_egp_table6, cb));
}


/* Unmarshall add_egp_table6 */
void
XrlRibV0p1Client::unmarshall_add_egp_table6(
	const XrlError&	e,
	XrlArgs*	a,
	AddEgpTable6CB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlRibV0p1Client::send_delete_egp_table4(
	const char*	the_tgt,
	const string&	protocol,
	const string&	target_class,
	const string&	target_instance,
	const bool&	unicast,
	const bool&	multicast,
	const DeleteEgpTable4CB&	cb
)
{
    Xrl x(the_tgt, "rib/0.1/delete_egp_table4");
    x.args().add("protocol", protocol);
    x.args().add("target_class", target_class);
    x.args().add("target_instance", target_instance);
    x.args().add("unicast", unicast);
    x.args().add("multicast", multicast);
    return _sender->send(x, callback(this, &XrlRibV0p1Client::unmarshall_delete_egp_table4, cb));
}


/* Unmarshall delete_egp_table4 */
void
XrlRibV0p1Client::unmarshall_delete_egp_table4(
	const XrlError&	e,
	XrlArgs*	a,
	DeleteEgpTable4CB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlRibV0p1Client::send_delete_egp_table6(
	const char*	the_tgt,
	const string&	protocol,
	const string&	target_class,
	const string&	target_instance,
	const bool&	unicast,
	const bool&	multicast,
	const DeleteEgpTable6CB&	cb
)
{
    Xrl x(the_tgt, "rib/0.1/delete_egp_table6");
    x.args().add("protocol", protocol);
    x.args().add("target_class", target_class);
    x.args().add("target_instance", target_instance);
    x.args().add("unicast", unicast);
    x.args().add("multicast", multicast);
    return _sender->send(x, callback(this, &XrlRibV0p1Client::unmarshall_delete_egp_table6, cb));
}


/* Unmarshall delete_egp_table6 */
void
XrlRibV0p1Client::unmarshall_delete_egp_table6(
	const XrlError&	e,
	XrlArgs*	a,
	DeleteEgpTable6CB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlRibV0p1Client::send_add_route4(
	const char*	the_tgt,
	const string&	protocol,
	const bool&	unicast,
	const bool&	multicast,
	const IPv4Net&	network,
	const IPv4&	nexthop,
	const uint32_t&	metric,
	const AddRoute4CB&	cb
)
{
    Xrl x(the_tgt, "rib/0.1/add_route4");
    x.args().add("protocol", protocol);
    x.args().add("unicast", unicast);
    x.args().add("multicast", multicast);
    x.args().add("network", network);
    x.args().add("nexthop", nexthop);
    x.args().add("metric", metric);
    return _sender->send(x, callback(this, &XrlRibV0p1Client::unmarshall_add_route4, cb));
}


/* Unmarshall add_route4 */
void
XrlRibV0p1Client::unmarshall_add_route4(
	const XrlError&	e,
	XrlArgs*	a,
	AddRoute4CB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlRibV0p1Client::send_add_route6(
	const char*	the_tgt,
	const string&	protocol,
	const bool&	unicast,
	const bool&	multicast,
	const IPv6Net&	network,
	const IPv6&	nexthop,
	const uint32_t&	metric,
	const AddRoute6CB&	cb
)
{
    Xrl x(the_tgt, "rib/0.1/add_route6");
    x.args().add("protocol", protocol);
    x.args().add("unicast", unicast);
    x.args().add("multicast", multicast);
    x.args().add("network", network);
    x.args().add("nexthop", nexthop);
    x.args().add("metric", metric);
    return _sender->send(x, callback(this, &XrlRibV0p1Client::unmarshall_add_route6, cb));
}


/* Unmarshall add_route6 */
void
XrlRibV0p1Client::unmarshall_add_route6(
	const XrlError&	e,
	XrlArgs*	a,
	AddRoute6CB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlRibV0p1Client::send_replace_route4(
	const char*	the_tgt,
	const string&	protocol,
	const bool&	unicast,
	const bool&	multicast,
	const IPv4Net&	network,
	const IPv4&	nexthop,
	const uint32_t&	metric,
	const ReplaceRoute4CB&	cb
)
{
    Xrl x(the_tgt, "rib/0.1/replace_route4");
    x.args().add("protocol", protocol);
    x.args().add("unicast", unicast);
    x.args().add("multicast", multicast);
    x.args().add("network", network);
    x.args().add("nexthop", nexthop);
    x.args().add("metric", metric);
    return _sender->send(x, callback(this, &XrlRibV0p1Client::unmarshall_replace_route4, cb));
}


/* Unmarshall replace_route4 */
void
XrlRibV0p1Client::unmarshall_replace_route4(
	const XrlError&	e,
	XrlArgs*	a,
	ReplaceRoute4CB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlRibV0p1Client::send_replace_route6(
	const char*	the_tgt,
	const string&	protocol,
	const bool&	unicast,
	const bool&	multicast,
	const IPv6Net&	network,
	const IPv6&	nexthop,
	const uint32_t&	metric,
	const ReplaceRoute6CB&	cb
)
{
    Xrl x(the_tgt, "rib/0.1/replace_route6");
    x.args().add("protocol", protocol);
    x.args().add("unicast", unicast);
    x.args().add("multicast", multicast);
    x.args().add("network", network);
    x.args().add("nexthop", nexthop);
    x.args().add("metric", metric);
    return _sender->send(x, callback(this, &XrlRibV0p1Client::unmarshall_replace_route6, cb));
}


/* Unmarshall replace_route6 */
void
XrlRibV0p1Client::unmarshall_replace_route6(
	const XrlError&	e,
	XrlArgs*	a,
	ReplaceRoute6CB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlRibV0p1Client::send_delete_route4(
	const char*	the_tgt,
	const string&	protocol,
	const bool&	unicast,
	const bool&	multicast,
	const IPv4Net&	network,
	const DeleteRoute4CB&	cb
)
{
    Xrl x(the_tgt, "rib/0.1/delete_route4");
    x.args().add("protocol", protocol);
    x.args().add("unicast", unicast);
    x.args().add("multicast", multicast);
    x.args().add("network", network);
    return _sender->send(x, callback(this, &XrlRibV0p1Client::unmarshall_delete_route4, cb));
}


/* Unmarshall delete_route4 */
void
XrlRibV0p1Client::unmarshall_delete_route4(
	const XrlError&	e,
	XrlArgs*	a,
	DeleteRoute4CB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlRibV0p1Client::send_delete_route6(
	const char*	the_tgt,
	const string&	protocol,
	const bool&	unicast,
	const bool&	multicast,
	const IPv6Net&	network,
	const DeleteRoute6CB&	cb
)
{
    Xrl x(the_tgt, "rib/0.1/delete_route6");
    x.args().add("protocol", protocol);
    x.args().add("unicast", unicast);
    x.args().add("multicast", multicast);
    x.args().add("network", network);
    return _sender->send(x, callback(this, &XrlRibV0p1Client::unmarshall_delete_route6, cb));
}


/* Unmarshall delete_route6 */
void
XrlRibV0p1Client::unmarshall_delete_route6(
	const XrlError&	e,
	XrlArgs*	a,
	DeleteRoute6CB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlRibV0p1Client::send_lookup_route4(
	const char*	the_tgt,
	const IPv4&	addr,
	const bool&	unicast,
	const bool&	multicast,
	const LookupRoute4CB&	cb
)
{
    Xrl x(the_tgt, "rib/0.1/lookup_route4");
    x.args().add("addr", addr);
    x.args().add("unicast", unicast);
    x.args().add("multicast", multicast);
    return _sender->send(x, callback(this, &XrlRibV0p1Client::unmarshall_lookup_route4, cb));
}


/* Unmarshall lookup_route4 */
void
XrlRibV0p1Client::unmarshall_lookup_route4(
	const XrlError&	e,
	XrlArgs*	a,
	LookupRoute4CB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e, 0);
	return;
    } else if (a && a->size() != 1) {
	XLOG_ERROR("Wrong number of arguments (%u != 1)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    IPv4 nexthop;
    try {
	a->get("nexthop", nexthop);
    } catch (const XrlArgs::XrlAtomNotFound&) {
	XLOG_ERROR("Atom not found");
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    cb->dispatch(e, &nexthop);
}

bool
XrlRibV0p1Client::send_lookup_route6(
	const char*	the_tgt,
	const IPv6&	addr,
	const bool&	unicast,
	const bool&	multicast,
	const LookupRoute6CB&	cb
)
{
    Xrl x(the_tgt, "rib/0.1/lookup_route6");
    x.args().add("addr", addr);
    x.args().add("unicast", unicast);
    x.args().add("multicast", multicast);
    return _sender->send(x, callback(this, &XrlRibV0p1Client::unmarshall_lookup_route6, cb));
}


/* Unmarshall lookup_route6 */
void
XrlRibV0p1Client::unmarshall_lookup_route6(
	const XrlError&	e,
	XrlArgs*	a,
	LookupRoute6CB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e, 0);
	return;
    } else if (a && a->size() != 1) {
	XLOG_ERROR("Wrong number of arguments (%u != 1)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    IPv6 nexthop;
    try {
	a->get("nexthop", nexthop);
    } catch (const XrlArgs::XrlAtomNotFound&) {
	XLOG_ERROR("Atom not found");
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    cb->dispatch(e, &nexthop);
}

bool
XrlRibV0p1Client::send_new_vif(
	const char*	the_tgt,
	const string&	name,
	const NewVifCB&	cb
)
{
    Xrl x(the_tgt, "rib/0.1/new_vif");
    x.args().add("name", name);
    return _sender->send(x, callback(this, &XrlRibV0p1Client::unmarshall_new_vif, cb));
}


/* Unmarshall new_vif */
void
XrlRibV0p1Client::unmarshall_new_vif(
	const XrlError&	e,
	XrlArgs*	a,
	NewVifCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlRibV0p1Client::send_add_vif_addr4(
	const char*	the_tgt,
	const string&	name,
	const IPv4&	addr,
	const IPv4Net&	subnet,
	const AddVifAddr4CB&	cb
)
{
    Xrl x(the_tgt, "rib/0.1/add_vif_addr4");
    x.args().add("name", name);
    x.args().add("addr", addr);
    x.args().add("subnet", subnet);
    return _sender->send(x, callback(this, &XrlRibV0p1Client::unmarshall_add_vif_addr4, cb));
}


/* Unmarshall add_vif_addr4 */
void
XrlRibV0p1Client::unmarshall_add_vif_addr4(
	const XrlError&	e,
	XrlArgs*	a,
	AddVifAddr4CB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlRibV0p1Client::send_add_vif_addr6(
	const char*	the_tgt,
	const string&	name,
	const IPv6&	addr,
	const IPv6Net&	subnet,
	const AddVifAddr6CB&	cb
)
{
    Xrl x(the_tgt, "rib/0.1/add_vif_addr6");
    x.args().add("name", name);
    x.args().add("addr", addr);
    x.args().add("subnet", subnet);
    return _sender->send(x, callback(this, &XrlRibV0p1Client::unmarshall_add_vif_addr6, cb));
}


/* Unmarshall add_vif_addr6 */
void
XrlRibV0p1Client::unmarshall_add_vif_addr6(
	const XrlError&	e,
	XrlArgs*	a,
	AddVifAddr6CB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlRibV0p1Client::send_redist_enable4(
	const char*	the_tgt,
	const string&	from,
	const string&	to,
	const bool&	unicast,
	const bool&	multicast,
	const RedistEnable4CB&	cb
)
{
    Xrl x(the_tgt, "rib/0.1/redist_enable4");
    x.args().add("from", from);
    x.args().add("to", to);
    x.args().add("unicast", unicast);
    x.args().add("multicast", multicast);
    return _sender->send(x, callback(this, &XrlRibV0p1Client::unmarshall_redist_enable4, cb));
}


/* Unmarshall redist_enable4 */
void
XrlRibV0p1Client::unmarshall_redist_enable4(
	const XrlError&	e,
	XrlArgs*	a,
	RedistEnable4CB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlRibV0p1Client::send_redist_enable6(
	const char*	the_tgt,
	const string&	from,
	const string&	to,
	const bool&	unicast,
	const bool&	multicast,
	const RedistEnable6CB&	cb
)
{
    Xrl x(the_tgt, "rib/0.1/redist_enable6");
    x.args().add("from", from);
    x.args().add("to", to);
    x.args().add("unicast", unicast);
    x.args().add("multicast", multicast);
    return _sender->send(x, callback(this, &XrlRibV0p1Client::unmarshall_redist_enable6, cb));
}


/* Unmarshall redist_enable6 */
void
XrlRibV0p1Client::unmarshall_redist_enable6(
	const XrlError&	e,
	XrlArgs*	a,
	RedistEnable6CB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlRibV0p1Client::send_redist_disable4(
	const char*	the_tgt,
	const string&	from,
	const string&	to,
	const bool&	unicast,
	const bool&	multicast,
	const RedistDisable4CB&	cb
)
{
    Xrl x(the_tgt, "rib/0.1/redist_disable4");
    x.args().add("from", from);
    x.args().add("to", to);
    x.args().add("unicast", unicast);
    x.args().add("multicast", multicast);
    return _sender->send(x, callback(this, &XrlRibV0p1Client::unmarshall_redist_disable4, cb));
}


/* Unmarshall redist_disable4 */
void
XrlRibV0p1Client::unmarshall_redist_disable4(
	const XrlError&	e,
	XrlArgs*	a,
	RedistDisable4CB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlRibV0p1Client::send_redist_disable6(
	const char*	the_tgt,
	const string&	from,
	const string&	to,
	const bool&	unicast,
	const bool&	multicast,
	const RedistDisable6CB&	cb
)
{
    Xrl x(the_tgt, "rib/0.1/redist_disable6");
    x.args().add("from", from);
    x.args().add("to", to);
    x.args().add("unicast", unicast);
    x.args().add("multicast", multicast);
    return _sender->send(x, callback(this, &XrlRibV0p1Client::unmarshall_redist_disable6, cb));
}


/* Unmarshall redist_disable6 */
void
XrlRibV0p1Client::unmarshall_redist_disable6(
	const XrlError&	e,
	XrlArgs*	a,
	RedistDisable6CB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlRibV0p1Client::send_register_interest4(
	const char*	the_tgt,
	const string&	target,
	const IPv4&	addr,
	const RegisterInterest4CB&	cb
)
{
    Xrl x(the_tgt, "rib/0.1/register_interest4");
    x.args().add("target", target);
    x.args().add("addr", addr);
    return _sender->send(x, callback(this, &XrlRibV0p1Client::unmarshall_register_interest4, cb));
}


/* Unmarshall register_interest4 */
void
XrlRibV0p1Client::unmarshall_register_interest4(
	const XrlError&	e,
	XrlArgs*	a,
	RegisterInterest4CB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e, 0, 0, 0, 0, 0, 0);
	return;
    } else if (a && a->size() != 6) {
	XLOG_ERROR("Wrong number of arguments (%u != 6)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS(), 0, 0, 0, 0, 0, 0);
	return;
    }
    bool resolves;
    IPv4 base_addr;
    uint32_t prefix_len;
    uint32_t real_prefix_len;
    IPv4 nexthop;
    uint32_t metric;
    try {
	a->get("resolves", resolves);
	a->get("base_addr", base_addr);
	a->get("prefix_len", prefix_len);
	a->get("real_prefix_len", real_prefix_len);
	a->get("nexthop", nexthop);
	a->get("metric", metric);
    } catch (const XrlArgs::XrlAtomNotFound&) {
	XLOG_ERROR("Atom not found");
	cb->dispatch(XrlError::BAD_ARGS(), 0, 0, 0, 0, 0, 0);
	return;
    }
    cb->dispatch(e, &resolves, &base_addr, &prefix_len, &real_prefix_len, &nexthop, &metric);
}

bool
XrlRibV0p1Client::send_deregister_interest4(
	const char*	the_tgt,
	const string&	target,
	const IPv4&	addr,
	const uint32_t&	prefix_len,
	const DeregisterInterest4CB&	cb
)
{
    Xrl x(the_tgt, "rib/0.1/deregister_interest4");
    x.args().add("target", target);
    x.args().add("addr", addr);
    x.args().add("prefix_len", prefix_len);
    return _sender->send(x, callback(this, &XrlRibV0p1Client::unmarshall_deregister_interest4, cb));
}


/* Unmarshall deregister_interest4 */
void
XrlRibV0p1Client::unmarshall_deregister_interest4(
	const XrlError&	e,
	XrlArgs*	a,
	DeregisterInterest4CB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlRibV0p1Client::send_register_interest6(
	const char*	the_tgt,
	const string&	target,
	const IPv6&	addr,
	const RegisterInterest6CB&	cb
)
{
    Xrl x(the_tgt, "rib/0.1/register_interest6");
    x.args().add("target", target);
    x.args().add("addr", addr);
    return _sender->send(x, callback(this, &XrlRibV0p1Client::unmarshall_register_interest6, cb));
}


/* Unmarshall register_interest6 */
void
XrlRibV0p1Client::unmarshall_register_interest6(
	const XrlError&	e,
	XrlArgs*	a,
	RegisterInterest6CB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e, 0, 0, 0, 0, 0, 0);
	return;
    } else if (a && a->size() != 6) {
	XLOG_ERROR("Wrong number of arguments (%u != 6)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS(), 0, 0, 0, 0, 0, 0);
	return;
    }
    bool resolves;
    IPv6 base_addr;
    uint32_t prefix_len;
    uint32_t real_prefix_len;
    IPv6 nexthop;
    uint32_t metric;
    try {
	a->get("resolves", resolves);
	a->get("base_addr", base_addr);
	a->get("prefix_len", prefix_len);
	a->get("real_prefix_len", real_prefix_len);
	a->get("nexthop", nexthop);
	a->get("metric", metric);
    } catch (const XrlArgs::XrlAtomNotFound&) {
	XLOG_ERROR("Atom not found");
	cb->dispatch(XrlError::BAD_ARGS(), 0, 0, 0, 0, 0, 0);
	return;
    }
    cb->dispatch(e, &resolves, &base_addr, &prefix_len, &real_prefix_len, &nexthop, &metric);
}

bool
XrlRibV0p1Client::send_deregister_interest6(
	const char*	the_tgt,
	const string&	target,
	const IPv6&	addr,
	const uint32_t&	prefix_len,
	const DeregisterInterest6CB&	cb
)
{
    Xrl x(the_tgt, "rib/0.1/deregister_interest6");
    x.args().add("target", target);
    x.args().add("addr", addr);
    x.args().add("prefix_len", prefix_len);
    return _sender->send(x, callback(this, &XrlRibV0p1Client::unmarshall_deregister_interest6, cb));
}


/* Unmarshall deregister_interest6 */
void
XrlRibV0p1Client::unmarshall_deregister_interest6(
	const XrlError&	e,
	XrlArgs*	a,
	DeregisterInterest6CB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}
