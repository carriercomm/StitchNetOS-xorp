/*
 * Copyright (c) 2001-2005 International Computer Science Institute
 * See LICENSE file for licensing, conditions, and warranties on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by 'clnt-gen'.
 *
 * $XORP: xorp/xrl/interfaces/mld6igmp_xif.hh,v 1.16 2005/06/01 00:37:00 pavlin Exp $
 */

#ifndef __XRL_INTERFACES_MLD6IGMP_XIF_HH__
#define __XRL_INTERFACES_MLD6IGMP_XIF_HH__

#undef XORP_LIBRARY_NAME
#define XORP_LIBRARY_NAME "XifMld6igmp"

#include "libxorp/xlog.h"
#include "libxorp/callback.hh"

#include "libxipc/xrl.hh"
#include "libxipc/xrl_error.hh"
#include "libxipc/xrl_sender.hh"


class XrlMld6igmpV0p1Client {
public:
    XrlMld6igmpV0p1Client(XrlSender* s) : _sender(s) {}
    virtual ~XrlMld6igmpV0p1Client() {}

    typedef XorpCallback1<void, const XrlError&>::RefPtr EnableVifCB;
    /**
     *  Send Xrl intended to:
     *
     *  Enable/disable/start/stop a MLD6IGMP vif interface.
     *
     *  @param tgt_name Xrl Target name
     *
     *  @param vif_name the name of the vif to enable/disable/start/stop.
     *
     *  @param enable if true, then enable the vif, otherwise disable it.
     */
    bool send_enable_vif(
	const char*	target_name,
	const string&	vif_name,
	const bool&	enable,
	const EnableVifCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr StartVifCB;

    bool send_start_vif(
	const char*	target_name,
	const string&	vif_name,
	const StartVifCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr StopVifCB;

    bool send_stop_vif(
	const char*	target_name,
	const string&	vif_name,
	const StopVifCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr EnableAllVifsCB;
    /**
     *  Send Xrl intended to:
     *
     *  Enable/disable/start/stop all MLD6IGMP vif interfaces.
     *
     *  @param tgt_name Xrl Target name
     *
     *  @param enable if true, then enable the vifs, otherwise disable them.
     */
    bool send_enable_all_vifs(
	const char*	target_name,
	const bool&	enable,
	const EnableAllVifsCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr StartAllVifsCB;

    bool send_start_all_vifs(
	const char*	target_name,
	const StartAllVifsCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr StopAllVifsCB;

    bool send_stop_all_vifs(
	const char*	target_name,
	const StopAllVifsCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr EnableMld6IgmpCB;
    /**
     *  Send Xrl intended to:
     *
     *  Enable/disable/start/stop the MLD6IGMP protocol.
     *
     *  @param tgt_name Xrl Target name
     *
     *  @param enable if true, then enable the MLD6IGMP protocol, otherwise
     *  disable it.
     */
    bool send_enable_mld6igmp(
	const char*	target_name,
	const bool&	enable,
	const EnableMld6IgmpCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr StartMld6IgmpCB;

    bool send_start_mld6igmp(
	const char*	target_name,
	const StartMld6IgmpCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr StopMld6IgmpCB;

    bool send_stop_mld6igmp(
	const char*	target_name,
	const StopMld6IgmpCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr EnableCliCB;
    /**
     *  Send Xrl intended to:
     *
     *  Enable/disable/start/stop the MLD6IGMP CLI access.
     *
     *  @param tgt_name Xrl Target name
     *
     *  @param enable if true, then enable the MLD6IGMP CLI access, otherwise
     *  disable it.
     */
    bool send_enable_cli(
	const char*	target_name,
	const bool&	enable,
	const EnableCliCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr StartCliCB;

    bool send_start_cli(
	const char*	target_name,
	const StartCliCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr StopCliCB;

    bool send_stop_cli(
	const char*	target_name,
	const StopCliCB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const uint32_t*>::RefPtr GetVifProtoVersionCB;
    /**
     *  Send Xrl intended to:
     *
     *  Get the configured protocol version per interface.
     *
     *  @param tgt_name Xrl Target name
     *
     *  @param vif_name the name of the vif to apply to.
     */
    bool send_get_vif_proto_version(
	const char*	target_name,
	const string&	vif_name,
	const GetVifProtoVersionCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr SetVifProtoVersionCB;
    /**
     *  Send Xrl intended to:
     *
     *  Set the protocol version per interface.
     *
     *  @param tgt_name Xrl Target name
     *
     *  @param vif_name the name of the vif to apply to.
     *
     *  @param proto_version the protocol version.
     */
    bool send_set_vif_proto_version(
	const char*	target_name,
	const string&	vif_name,
	const uint32_t&	proto_version,
	const SetVifProtoVersionCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr ResetVifProtoVersionCB;
    /**
     *  Send Xrl intended to:
     *
     *  Reset the protocol version per interface to its default value.
     *
     *  @param tgt_name Xrl Target name
     *
     *  @param vif_name the name of the vif to apply to.
     */
    bool send_reset_vif_proto_version(
	const char*	target_name,
	const string&	vif_name,
	const ResetVifProtoVersionCB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const bool*>::RefPtr GetVifIpRouterAlertOptionCheckCB;
    /**
     *  Send Xrl intended to:
     *
     *  Get the IP Router Alert option check per interface for received
     *  packets.
     *
     *  @param tgt_name Xrl Target name
     *
     *  @param vif_name the name of the vif to apply to.
     */
    bool send_get_vif_ip_router_alert_option_check(
	const char*	target_name,
	const string&	vif_name,
	const GetVifIpRouterAlertOptionCheckCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr SetVifIpRouterAlertOptionCheckCB;
    /**
     *  Send Xrl intended to:
     *
     *  Set the IP Router Alert option check per interface for received
     *  packets.
     *
     *  @param tgt_name Xrl Target name
     *
     *  @param vif_name the name of the vif to apply to.
     *
     *  @param enable if true, then enable the IP Router Alert option check,
     *  otherwise disable it.
     */
    bool send_set_vif_ip_router_alert_option_check(
	const char*	target_name,
	const string&	vif_name,
	const bool&	enable,
	const SetVifIpRouterAlertOptionCheckCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr ResetVifIpRouterAlertOptionCheckCB;
    /**
     *  Send Xrl intended to:
     *
     *  Reset the IP Router Alert option check for received packets per per
     *  interface to its default value.
     *
     *  @param tgt_name Xrl Target name
     *
     *  @param vif_name the name of the vif to apply to.
     */
    bool send_reset_vif_ip_router_alert_option_check(
	const char*	target_name,
	const string&	vif_name,
	const ResetVifIpRouterAlertOptionCheckCB&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const uint32_t*, const uint32_t*>::RefPtr GetVifQueryIntervalCB;
    /**
     *  Send Xrl intended to:
     *
     *  Get the Query Interval per interface.
     *
     *  @param tgt_name Xrl Target name
     *
     *  @param vif_name the name of the vif to apply to.
     */
    bool send_get_vif_query_interval(
	const char*	target_name,
	const string&	vif_name,
	const GetVifQueryIntervalCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr SetVifQueryIntervalCB;
    /**
     *  Send Xrl intended to:
     *
     *  Set the Query Interval per interface.
     *
     *  @param tgt_name Xrl Target name
     *
     *  @param vif_name the name of the vif to apply to.
     *
     *  @param interval_sec the number of seconds in the interval.
     *
     *  @param interval_usec the number of microseconds (in addition to
     *  interval_sec) in the interval.
     */
    bool send_set_vif_query_interval(
	const char*	target_name,
	const string&	vif_name,
	const uint32_t&	interval_sec,
	const uint32_t&	interval_usec,
	const SetVifQueryIntervalCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr ResetVifQueryIntervalCB;
    /**
     *  Send Xrl intended to:
     *
     *  Reset the Query Interval per interface to its default value.
     *
     *  @param tgt_name Xrl Target name
     *
     *  @param vif_name the name of the vif to apply to.
     */
    bool send_reset_vif_query_interval(
	const char*	target_name,
	const string&	vif_name,
	const ResetVifQueryIntervalCB&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const uint32_t*, const uint32_t*>::RefPtr GetVifQueryLastMemberIntervalCB;
    /**
     *  Send Xrl intended to:
     *
     *  Get the Last Member Query Interval per interface.
     *
     *  @param tgt_name Xrl Target name
     *
     *  @param vif_name the name of the vif to apply to.
     */
    bool send_get_vif_query_last_member_interval(
	const char*	target_name,
	const string&	vif_name,
	const GetVifQueryLastMemberIntervalCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr SetVifQueryLastMemberIntervalCB;
    /**
     *  Send Xrl intended to:
     *
     *  Set the Last Member Query Interval per interface.
     *
     *  @param tgt_name Xrl Target name
     *
     *  @param vif_name the name of the vif to apply to.
     *
     *  @param interval_sec the number of seconds in the interval.
     *
     *  @param interval_usec the number of microseconds (in addition to
     *  interval_sec) in the interval.
     */
    bool send_set_vif_query_last_member_interval(
	const char*	target_name,
	const string&	vif_name,
	const uint32_t&	interval_sec,
	const uint32_t&	interval_usec,
	const SetVifQueryLastMemberIntervalCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr ResetVifQueryLastMemberIntervalCB;
    /**
     *  Send Xrl intended to:
     *
     *  Reset the Last Member Query Interval per interface to its default
     *  value.
     *
     *  @param tgt_name Xrl Target name
     *
     *  @param vif_name the name of the vif to apply to.
     */
    bool send_reset_vif_query_last_member_interval(
	const char*	target_name,
	const string&	vif_name,
	const ResetVifQueryLastMemberIntervalCB&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const uint32_t*, const uint32_t*>::RefPtr GetVifQueryResponseIntervalCB;
    /**
     *  Send Xrl intended to:
     *
     *  Get the Query Response Interval per interface.
     *
     *  @param tgt_name Xrl Target name
     *
     *  @param vif_name the name of the vif to apply to.
     */
    bool send_get_vif_query_response_interval(
	const char*	target_name,
	const string&	vif_name,
	const GetVifQueryResponseIntervalCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr SetVifQueryResponseIntervalCB;
    /**
     *  Send Xrl intended to:
     *
     *  Set the Query Response Interval per interface.
     *
     *  @param tgt_name Xrl Target name
     *
     *  @param vif_name the name of the vif to apply to.
     *
     *  @param interval_sec the number of seconds in the interval.
     *
     *  @param interval_usec the number of microseconds (in addition to
     *  interval_sec) in the interval.
     */
    bool send_set_vif_query_response_interval(
	const char*	target_name,
	const string&	vif_name,
	const uint32_t&	interval_sec,
	const uint32_t&	interval_usec,
	const SetVifQueryResponseIntervalCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr ResetVifQueryResponseIntervalCB;
    /**
     *  Send Xrl intended to:
     *
     *  Reset the Query Response Interval per interface to its default value.
     *
     *  @param tgt_name Xrl Target name
     *
     *  @param vif_name the name of the vif to apply to.
     */
    bool send_reset_vif_query_response_interval(
	const char*	target_name,
	const string&	vif_name,
	const ResetVifQueryResponseIntervalCB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const uint32_t*>::RefPtr GetVifRobustCountCB;
    /**
     *  Send Xrl intended to:
     *
     *  Get the Robustness Variable count per interface.
     *
     *  @param tgt_name Xrl Target name
     *
     *  @param vif_name the name of the vif to apply to.
     */
    bool send_get_vif_robust_count(
	const char*	target_name,
	const string&	vif_name,
	const GetVifRobustCountCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr SetVifRobustCountCB;
    /**
     *  Send Xrl intended to:
     *
     *  Set the Robustness Variable count per interface.
     *
     *  @param tgt_name Xrl Target name
     *
     *  @param vif_name the name of the vif to apply to.
     *
     *  @param robust_count the count value.
     */
    bool send_set_vif_robust_count(
	const char*	target_name,
	const string&	vif_name,
	const uint32_t&	robust_count,
	const SetVifRobustCountCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr ResetVifRobustCountCB;
    /**
     *  Send Xrl intended to:
     *
     *  Reset the Robustness Variable count per interface to its default value.
     *
     *  @param tgt_name Xrl Target name
     *
     *  @param vif_name the name of the vif to apply to.
     */
    bool send_reset_vif_robust_count(
	const char*	target_name,
	const string&	vif_name,
	const ResetVifRobustCountCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr LogTraceAllCB;
    /**
     *  Send Xrl intended to:
     *
     *  Enable/disable the MLD6IGMP trace log for all operations.
     *
     *  @param tgt_name Xrl Target name
     *
     *  @param enable if true, then enable the trace log, otherwise disable it.
     */
    bool send_log_trace_all(
	const char*	target_name,
	const bool&	enable,
	const LogTraceAllCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr AddProtocol4CB;
    /**
     *  Send Xrl intended to:
     *
     *  Add/delete a client protocol in the MLD/IGMP protocol.
     *
     *  @param tgt_name Xrl Target name
     *
     *  @param xrl_sender_name the XRL name of the originator of this XRL.
     *
     *  @param protocol_name the name of the protocol to add/delete.
     *
     *  @param protocol_id the ID of the protocol to add/delete (both sides
     *  must agree on the particular values).
     *
     *  @param vif_name the name of the vif the protocol add/delete to apply
     *  to.
     *
     *  @param vif_index the index of the vif the protocol add/delete to apply
     *  to. The added protocol will receive Join/Leave membership information
     *  about same-LAN members for the particular vif.
     */
    bool send_add_protocol4(
	const char*	target_name,
	const string&	xrl_sender_name,
	const string&	protocol_name,
	const uint32_t&	protocol_id,
	const string&	vif_name,
	const uint32_t&	vif_index,
	const AddProtocol4CB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr AddProtocol6CB;

    bool send_add_protocol6(
	const char*	target_name,
	const string&	xrl_sender_name,
	const string&	protocol_name,
	const uint32_t&	protocol_id,
	const string&	vif_name,
	const uint32_t&	vif_index,
	const AddProtocol6CB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr DeleteProtocol4CB;

    bool send_delete_protocol4(
	const char*	target_name,
	const string&	xrl_sender_name,
	const string&	protocol_name,
	const uint32_t&	protocol_id,
	const string&	vif_name,
	const uint32_t&	vif_index,
	const DeleteProtocol4CB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr DeleteProtocol6CB;

    bool send_delete_protocol6(
	const char*	target_name,
	const string&	xrl_sender_name,
	const string&	protocol_name,
	const uint32_t&	protocol_id,
	const string&	vif_name,
	const uint32_t&	vif_index,
	const DeleteProtocol6CB&	cb
    );

protected:
    XrlSender* _sender;

private:
    void unmarshall_enable_vif(
	const XrlError&	e,
	XrlArgs*	a,
	EnableVifCB		cb
    );

    void unmarshall_start_vif(
	const XrlError&	e,
	XrlArgs*	a,
	StartVifCB		cb
    );

    void unmarshall_stop_vif(
	const XrlError&	e,
	XrlArgs*	a,
	StopVifCB		cb
    );

    void unmarshall_enable_all_vifs(
	const XrlError&	e,
	XrlArgs*	a,
	EnableAllVifsCB		cb
    );

    void unmarshall_start_all_vifs(
	const XrlError&	e,
	XrlArgs*	a,
	StartAllVifsCB		cb
    );

    void unmarshall_stop_all_vifs(
	const XrlError&	e,
	XrlArgs*	a,
	StopAllVifsCB		cb
    );

    void unmarshall_enable_mld6igmp(
	const XrlError&	e,
	XrlArgs*	a,
	EnableMld6IgmpCB		cb
    );

    void unmarshall_start_mld6igmp(
	const XrlError&	e,
	XrlArgs*	a,
	StartMld6IgmpCB		cb
    );

    void unmarshall_stop_mld6igmp(
	const XrlError&	e,
	XrlArgs*	a,
	StopMld6IgmpCB		cb
    );

    void unmarshall_enable_cli(
	const XrlError&	e,
	XrlArgs*	a,
	EnableCliCB		cb
    );

    void unmarshall_start_cli(
	const XrlError&	e,
	XrlArgs*	a,
	StartCliCB		cb
    );

    void unmarshall_stop_cli(
	const XrlError&	e,
	XrlArgs*	a,
	StopCliCB		cb
    );

    void unmarshall_get_vif_proto_version(
	const XrlError&	e,
	XrlArgs*	a,
	GetVifProtoVersionCB		cb
    );

    void unmarshall_set_vif_proto_version(
	const XrlError&	e,
	XrlArgs*	a,
	SetVifProtoVersionCB		cb
    );

    void unmarshall_reset_vif_proto_version(
	const XrlError&	e,
	XrlArgs*	a,
	ResetVifProtoVersionCB		cb
    );

    void unmarshall_get_vif_ip_router_alert_option_check(
	const XrlError&	e,
	XrlArgs*	a,
	GetVifIpRouterAlertOptionCheckCB		cb
    );

    void unmarshall_set_vif_ip_router_alert_option_check(
	const XrlError&	e,
	XrlArgs*	a,
	SetVifIpRouterAlertOptionCheckCB		cb
    );

    void unmarshall_reset_vif_ip_router_alert_option_check(
	const XrlError&	e,
	XrlArgs*	a,
	ResetVifIpRouterAlertOptionCheckCB		cb
    );

    void unmarshall_get_vif_query_interval(
	const XrlError&	e,
	XrlArgs*	a,
	GetVifQueryIntervalCB		cb
    );

    void unmarshall_set_vif_query_interval(
	const XrlError&	e,
	XrlArgs*	a,
	SetVifQueryIntervalCB		cb
    );

    void unmarshall_reset_vif_query_interval(
	const XrlError&	e,
	XrlArgs*	a,
	ResetVifQueryIntervalCB		cb
    );

    void unmarshall_get_vif_query_last_member_interval(
	const XrlError&	e,
	XrlArgs*	a,
	GetVifQueryLastMemberIntervalCB		cb
    );

    void unmarshall_set_vif_query_last_member_interval(
	const XrlError&	e,
	XrlArgs*	a,
	SetVifQueryLastMemberIntervalCB		cb
    );

    void unmarshall_reset_vif_query_last_member_interval(
	const XrlError&	e,
	XrlArgs*	a,
	ResetVifQueryLastMemberIntervalCB		cb
    );

    void unmarshall_get_vif_query_response_interval(
	const XrlError&	e,
	XrlArgs*	a,
	GetVifQueryResponseIntervalCB		cb
    );

    void unmarshall_set_vif_query_response_interval(
	const XrlError&	e,
	XrlArgs*	a,
	SetVifQueryResponseIntervalCB		cb
    );

    void unmarshall_reset_vif_query_response_interval(
	const XrlError&	e,
	XrlArgs*	a,
	ResetVifQueryResponseIntervalCB		cb
    );

    void unmarshall_get_vif_robust_count(
	const XrlError&	e,
	XrlArgs*	a,
	GetVifRobustCountCB		cb
    );

    void unmarshall_set_vif_robust_count(
	const XrlError&	e,
	XrlArgs*	a,
	SetVifRobustCountCB		cb
    );

    void unmarshall_reset_vif_robust_count(
	const XrlError&	e,
	XrlArgs*	a,
	ResetVifRobustCountCB		cb
    );

    void unmarshall_log_trace_all(
	const XrlError&	e,
	XrlArgs*	a,
	LogTraceAllCB		cb
    );

    void unmarshall_add_protocol4(
	const XrlError&	e,
	XrlArgs*	a,
	AddProtocol4CB		cb
    );

    void unmarshall_add_protocol6(
	const XrlError&	e,
	XrlArgs*	a,
	AddProtocol6CB		cb
    );

    void unmarshall_delete_protocol4(
	const XrlError&	e,
	XrlArgs*	a,
	DeleteProtocol4CB		cb
    );

    void unmarshall_delete_protocol6(
	const XrlError&	e,
	XrlArgs*	a,
	DeleteProtocol6CB		cb
    );

};

#endif /* __XRL_INTERFACES_MLD6IGMP_XIF_HH__ */