/*
 * Copyright (c) 2001-2005 International Computer Science Institute
 * See LICENSE file for licensing, conditions, and warranties on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by 'clnt-gen'.
 *
 * $XORP: xorp/xrl/interfaces/fea_ifmgr_xif.hh,v 1.22 2005/03/25 02:54:48 pavlin Exp $
 */

#ifndef __XRL_INTERFACES_FEA_IFMGR_XIF_HH__
#define __XRL_INTERFACES_FEA_IFMGR_XIF_HH__

#undef XORP_LIBRARY_NAME
#define XORP_LIBRARY_NAME "XifFeaIfmgr"

#include "libxorp/xlog.h"
#include "libxorp/callback.hh"

#include "libxipc/xrl.hh"
#include "libxipc/xrl_error.hh"
#include "libxipc/xrl_sender.hh"


class XrlIfmgrV0p1Client {
public:
    XrlIfmgrV0p1Client(XrlSender* s) : _sender(s) {}
    virtual ~XrlIfmgrV0p1Client() {}

    typedef XorpCallback1<void, const XrlError&>::RefPtr SetRestoreOriginalConfigOnShutdownCB;

    bool send_set_restore_original_config_on_shutdown(
	const char*	target_name,
	const bool&	enable,
	const SetRestoreOriginalConfigOnShutdownCB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const XrlAtomList*>::RefPtr GetConfiguredInterfaceNamesCB;

    bool send_get_configured_interface_names(
	const char*	target_name,
	const GetConfiguredInterfaceNamesCB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const XrlAtomList*>::RefPtr GetConfiguredVifNamesCB;

    bool send_get_configured_vif_names(
	const char*	target_name,
	const string&	ifname,
	const GetConfiguredVifNamesCB&	cb
    );

    typedef XorpCallback6<void, const XrlError&, const bool*, const bool*, const bool*, const bool*, const bool*>::RefPtr GetConfiguredVifFlagsCB;

    bool send_get_configured_vif_flags(
	const char*	target_name,
	const string&	ifname,
	const string&	vif,
	const GetConfiguredVifFlagsCB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const uint32_t*>::RefPtr GetConfiguredVifPifIndexCB;

    bool send_get_configured_vif_pif_index(
	const char*	target_name,
	const string&	ifname,
	const string&	vif,
	const GetConfiguredVifPifIndexCB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const XrlAtomList*>::RefPtr GetConfiguredVifAddresses4CB;

    bool send_get_configured_vif_addresses4(
	const char*	target_name,
	const string&	ifname,
	const string&	vif,
	const GetConfiguredVifAddresses4CB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const XrlAtomList*>::RefPtr GetConfiguredVifAddresses6CB;

    bool send_get_configured_vif_addresses6(
	const char*	target_name,
	const string&	ifname,
	const string&	vif,
	const GetConfiguredVifAddresses6CB&	cb
    );

    typedef XorpCallback6<void, const XrlError&, const bool*, const bool*, const bool*, const bool*, const bool*>::RefPtr GetConfiguredAddressFlags4CB;

    bool send_get_configured_address_flags4(
	const char*	target_name,
	const string&	ifname,
	const string&	vif,
	const IPv4&	address,
	const GetConfiguredAddressFlags4CB&	cb
    );

    typedef XorpCallback5<void, const XrlError&, const bool*, const bool*, const bool*, const bool*>::RefPtr GetConfiguredAddressFlags6CB;

    bool send_get_configured_address_flags6(
	const char*	target_name,
	const string&	ifname,
	const string&	vif,
	const IPv6&	address,
	const GetConfiguredAddressFlags6CB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const bool*>::RefPtr GetConfiguredInterfaceEnabledCB;

    bool send_get_configured_interface_enabled(
	const char*	target_name,
	const string&	ifname,
	const GetConfiguredInterfaceEnabledCB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const bool*>::RefPtr GetConfiguredInterfaceDiscardCB;

    bool send_get_configured_interface_discard(
	const char*	target_name,
	const string&	ifname,
	const GetConfiguredInterfaceDiscardCB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const Mac*>::RefPtr GetConfiguredMacCB;

    bool send_get_configured_mac(
	const char*	target_name,
	const string&	ifname,
	const GetConfiguredMacCB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const uint32_t*>::RefPtr GetConfiguredMtuCB;

    bool send_get_configured_mtu(
	const char*	target_name,
	const string&	ifname,
	const GetConfiguredMtuCB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const bool*>::RefPtr GetConfiguredVifEnabledCB;

    bool send_get_configured_vif_enabled(
	const char*	target_name,
	const string&	ifname,
	const string&	vif,
	const GetConfiguredVifEnabledCB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const uint32_t*>::RefPtr GetConfiguredPrefix4CB;

    bool send_get_configured_prefix4(
	const char*	target_name,
	const string&	ifname,
	const string&	vif,
	const IPv4&	address,
	const GetConfiguredPrefix4CB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const IPv4*>::RefPtr GetConfiguredBroadcast4CB;

    bool send_get_configured_broadcast4(
	const char*	target_name,
	const string&	ifname,
	const string&	vif,
	const IPv4&	address,
	const GetConfiguredBroadcast4CB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const IPv4*>::RefPtr GetConfiguredEndpoint4CB;

    bool send_get_configured_endpoint4(
	const char*	target_name,
	const string&	ifname,
	const string&	vif,
	const IPv4&	address,
	const GetConfiguredEndpoint4CB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const uint32_t*>::RefPtr GetConfiguredPrefix6CB;

    bool send_get_configured_prefix6(
	const char*	target_name,
	const string&	ifname,
	const string&	vif,
	const IPv6&	address,
	const GetConfiguredPrefix6CB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const IPv6*>::RefPtr GetConfiguredEndpoint6CB;

    bool send_get_configured_endpoint6(
	const char*	target_name,
	const string&	ifname,
	const string&	vif,
	const IPv6&	address,
	const GetConfiguredEndpoint6CB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const uint32_t*>::RefPtr StartTransactionCB;

    bool send_start_transaction(
	const char*	target_name,
	const StartTransactionCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr CommitTransactionCB;

    bool send_commit_transaction(
	const char*	target_name,
	const uint32_t&	tid,
	const CommitTransactionCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr AbortTransactionCB;

    bool send_abort_transaction(
	const char*	target_name,
	const uint32_t&	tid,
	const AbortTransactionCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr CreateInterfaceCB;

    bool send_create_interface(
	const char*	target_name,
	const uint32_t&	tid,
	const string&	ifname,
	const CreateInterfaceCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr DeleteInterfaceCB;

    bool send_delete_interface(
	const char*	target_name,
	const uint32_t&	tid,
	const string&	ifname,
	const DeleteInterfaceCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr ConfigureInterfaceFromSystemCB;
    /**
     *  Send Xrl intended to:
     *
     *  Implicitly configure an interface within the FEA by using information
     *  from the underlying system.
     *
     *  @param tgt_name Xrl Target name
     *
     *  @param tid the transaction ID.
     *
     *  @param ifname the name of the interface to configure.
     */
    bool send_configure_interface_from_system(
	const char*	target_name,
	const uint32_t&	tid,
	const string&	ifname,
	const ConfigureInterfaceFromSystemCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr SetInterfaceEnabledCB;

    bool send_set_interface_enabled(
	const char*	target_name,
	const uint32_t&	tid,
	const string&	ifname,
	const bool&	enabled,
	const SetInterfaceEnabledCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr SetInterfaceDiscardCB;

    bool send_set_interface_discard(
	const char*	target_name,
	const uint32_t&	tid,
	const string&	ifname,
	const bool&	discard,
	const SetInterfaceDiscardCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr SetMacCB;

    bool send_set_mac(
	const char*	target_name,
	const uint32_t&	tid,
	const string&	ifname,
	const Mac&	mac,
	const SetMacCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr SetMtuCB;

    bool send_set_mtu(
	const char*	target_name,
	const uint32_t&	tid,
	const string&	ifname,
	const uint32_t&	mtu,
	const SetMtuCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr CreateVifCB;
    /**
     *  Send Xrl intended to:
     *
     *  Create a vif
     *
     *  @param tgt_name Xrl Target name
     *
     *  @param ifname the name of the physical interface associated with the
     *  new vif.
     *
     *  @param vif name for new vif, must be unique across all the vifs in the
     *  system.
     */
    bool send_create_vif(
	const char*	target_name,
	const uint32_t&	tid,
	const string&	ifname,
	const string&	vif,
	const CreateVifCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr DeleteVifCB;

    bool send_delete_vif(
	const char*	target_name,
	const uint32_t&	tid,
	const string&	ifname,
	const string&	vif,
	const DeleteVifCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr SetVifEnabledCB;

    bool send_set_vif_enabled(
	const char*	target_name,
	const uint32_t&	tid,
	const string&	ifname,
	const string&	vif,
	const bool&	enabled,
	const SetVifEnabledCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr CreateAddress4CB;

    bool send_create_address4(
	const char*	target_name,
	const uint32_t&	tid,
	const string&	ifname,
	const string&	vif,
	const IPv4&	address,
	const CreateAddress4CB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr DeleteAddress4CB;

    bool send_delete_address4(
	const char*	target_name,
	const uint32_t&	tid,
	const string&	ifname,
	const string&	vif,
	const IPv4&	address,
	const DeleteAddress4CB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr SetAddressEnabled4CB;

    bool send_set_address_enabled4(
	const char*	target_name,
	const uint32_t&	tid,
	const string&	ifname,
	const string&	vif,
	const IPv4&	address,
	const bool&	enabled,
	const SetAddressEnabled4CB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const bool*>::RefPtr GetConfiguredAddressEnabled4CB;

    bool send_get_configured_address_enabled4(
	const char*	target_name,
	const string&	ifname,
	const string&	vif,
	const IPv4&	address,
	const GetConfiguredAddressEnabled4CB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr SetPrefix4CB;

    bool send_set_prefix4(
	const char*	target_name,
	const uint32_t&	tid,
	const string&	ifname,
	const string&	vif,
	const IPv4&	address,
	const uint32_t&	prefix_len,
	const SetPrefix4CB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr SetBroadcast4CB;

    bool send_set_broadcast4(
	const char*	target_name,
	const uint32_t&	tid,
	const string&	ifname,
	const string&	vif,
	const IPv4&	address,
	const IPv4&	broadcast,
	const SetBroadcast4CB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr SetEndpoint4CB;

    bool send_set_endpoint4(
	const char*	target_name,
	const uint32_t&	tid,
	const string&	ifname,
	const string&	vif,
	const IPv4&	address,
	const IPv4&	endpoint,
	const SetEndpoint4CB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr CreateAddress6CB;

    bool send_create_address6(
	const char*	target_name,
	const uint32_t&	tid,
	const string&	ifname,
	const string&	vif,
	const IPv6&	address,
	const CreateAddress6CB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr DeleteAddress6CB;

    bool send_delete_address6(
	const char*	target_name,
	const uint32_t&	tid,
	const string&	ifname,
	const string&	vif,
	const IPv6&	address,
	const DeleteAddress6CB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr SetAddressEnabled6CB;

    bool send_set_address_enabled6(
	const char*	target_name,
	const uint32_t&	tid,
	const string&	ifname,
	const string&	vif,
	const IPv6&	address,
	const bool&	enabled,
	const SetAddressEnabled6CB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const bool*>::RefPtr GetConfiguredAddressEnabled6CB;

    bool send_get_configured_address_enabled6(
	const char*	target_name,
	const string&	ifname,
	const string&	vif,
	const IPv6&	address,
	const GetConfiguredAddressEnabled6CB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr SetPrefix6CB;

    bool send_set_prefix6(
	const char*	target_name,
	const uint32_t&	tid,
	const string&	ifname,
	const string&	vif,
	const IPv6&	address,
	const uint32_t&	prefix_len,
	const SetPrefix6CB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr SetEndpoint6CB;

    bool send_set_endpoint6(
	const char*	target_name,
	const uint32_t&	tid,
	const string&	ifname,
	const string&	vif,
	const IPv6&	address,
	const IPv6&	endpoint,
	const SetEndpoint6CB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr RegisterClientCB;
    /**
     *  Send Xrl intended to:
     *
     *  Register network interface observer for configured interfaces.
     *
     *  @param tgt_name Xrl Target name
     *
     *  @param clientname name of xrl entity supporting fea_ifmgr_client.xif
     *  methods.
     */
    bool send_register_client(
	const char*	target_name,
	const string&	clientname,
	const RegisterClientCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr UnregisterClientCB;
    /**
     *  Send Xrl intended to:
     *
     *  Unregister network interface observer for configured interfaces. This
     *  method is not strictly necessary, the fea will remove the interface
     *  observer from its list of known observers if interface update XRLs
     *  fail.
     *
     *  @param tgt_name Xrl Target name
     */
    bool send_unregister_client(
	const char*	target_name,
	const string&	clientname,
	const UnregisterClientCB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const XrlAtomList*>::RefPtr GetSystemInterfaceNamesCB;

    bool send_get_system_interface_names(
	const char*	target_name,
	const GetSystemInterfaceNamesCB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const XrlAtomList*>::RefPtr GetSystemVifNamesCB;

    bool send_get_system_vif_names(
	const char*	target_name,
	const string&	ifname,
	const GetSystemVifNamesCB&	cb
    );

    typedef XorpCallback6<void, const XrlError&, const bool*, const bool*, const bool*, const bool*, const bool*>::RefPtr GetSystemVifFlagsCB;

    bool send_get_system_vif_flags(
	const char*	target_name,
	const string&	ifname,
	const string&	vif,
	const GetSystemVifFlagsCB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const uint32_t*>::RefPtr GetSystemVifPifIndexCB;

    bool send_get_system_vif_pif_index(
	const char*	target_name,
	const string&	ifname,
	const string&	vif,
	const GetSystemVifPifIndexCB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const XrlAtomList*>::RefPtr GetSystemVifAddresses4CB;

    bool send_get_system_vif_addresses4(
	const char*	target_name,
	const string&	ifname,
	const string&	vif,
	const GetSystemVifAddresses4CB&	cb
    );

    typedef XorpCallback6<void, const XrlError&, const bool*, const bool*, const bool*, const bool*, const bool*>::RefPtr GetSystemAddressFlags4CB;

    bool send_get_system_address_flags4(
	const char*	target_name,
	const string&	ifname,
	const string&	vif,
	const IPv4&	address,
	const GetSystemAddressFlags4CB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const XrlAtomList*>::RefPtr GetSystemVifAddresses6CB;

    bool send_get_system_vif_addresses6(
	const char*	target_name,
	const string&	ifname,
	const string&	vif,
	const GetSystemVifAddresses6CB&	cb
    );

    typedef XorpCallback5<void, const XrlError&, const bool*, const bool*, const bool*, const bool*>::RefPtr GetSystemAddressFlags6CB;

    bool send_get_system_address_flags6(
	const char*	target_name,
	const string&	ifname,
	const string&	vif,
	const IPv6&	address,
	const GetSystemAddressFlags6CB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const bool*>::RefPtr GetSystemInterfaceEnabledCB;

    bool send_get_system_interface_enabled(
	const char*	target_name,
	const string&	ifname,
	const GetSystemInterfaceEnabledCB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const bool*>::RefPtr GetSystemInterfaceDiscardCB;

    bool send_get_system_interface_discard(
	const char*	target_name,
	const string&	ifname,
	const GetSystemInterfaceDiscardCB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const Mac*>::RefPtr GetSystemMacCB;

    bool send_get_system_mac(
	const char*	target_name,
	const string&	ifname,
	const GetSystemMacCB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const uint32_t*>::RefPtr GetSystemMtuCB;

    bool send_get_system_mtu(
	const char*	target_name,
	const string&	ifname,
	const GetSystemMtuCB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const bool*>::RefPtr GetSystemVifEnabledCB;

    bool send_get_system_vif_enabled(
	const char*	target_name,
	const string&	ifname,
	const string&	vif,
	const GetSystemVifEnabledCB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const uint32_t*>::RefPtr GetSystemPrefix4CB;

    bool send_get_system_prefix4(
	const char*	target_name,
	const string&	ifname,
	const string&	vif,
	const IPv4&	address,
	const GetSystemPrefix4CB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const IPv4*>::RefPtr GetSystemBroadcast4CB;

    bool send_get_system_broadcast4(
	const char*	target_name,
	const string&	ifname,
	const string&	vif,
	const IPv4&	address,
	const GetSystemBroadcast4CB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const IPv4*>::RefPtr GetSystemEndpoint4CB;

    bool send_get_system_endpoint4(
	const char*	target_name,
	const string&	ifname,
	const string&	vif,
	const IPv4&	address,
	const GetSystemEndpoint4CB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const uint32_t*>::RefPtr GetSystemPrefix6CB;

    bool send_get_system_prefix6(
	const char*	target_name,
	const string&	ifname,
	const string&	vif,
	const IPv6&	address,
	const GetSystemPrefix6CB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const IPv6*>::RefPtr GetSystemEndpoint6CB;

    bool send_get_system_endpoint6(
	const char*	target_name,
	const string&	ifname,
	const string&	vif,
	const IPv6&	address,
	const GetSystemEndpoint6CB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const bool*>::RefPtr GetSystemAddressEnabled4CB;

    bool send_get_system_address_enabled4(
	const char*	target_name,
	const string&	ifname,
	const string&	vif,
	const IPv4&	address,
	const GetSystemAddressEnabled4CB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const bool*>::RefPtr GetSystemAddressEnabled6CB;

    bool send_get_system_address_enabled6(
	const char*	target_name,
	const string&	ifname,
	const string&	vif,
	const IPv6&	address,
	const GetSystemAddressEnabled6CB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr RegisterSystemInterfacesClientCB;
    /**
     *  Send Xrl intended to:
     *
     *  Register network interface observer for all system interfaces.
     *
     *  @param tgt_name Xrl Target name
     *
     *  @param clientname name of xrl entity supporting fea_ifmgr_client.xif
     *  methods.
     */
    bool send_register_system_interfaces_client(
	const char*	target_name,
	const string&	clientname,
	const RegisterSystemInterfacesClientCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr UnregisterSystemInterfacesClientCB;
    /**
     *  Send Xrl intended to:
     *
     *  Unregister network interface observer for all system interfaces. This
     *  method is not strictly necessary, the fea will remove the interface
     *  observer from its list of known observers if interface update XRLs
     *  fail.
     *
     *  @param tgt_name Xrl Target name
     */
    bool send_unregister_system_interfaces_client(
	const char*	target_name,
	const string&	clientname,
	const UnregisterSystemInterfacesClientCB&	cb
    );

protected:
    XrlSender* _sender;

private:
    void unmarshall_set_restore_original_config_on_shutdown(
	const XrlError&	e,
	XrlArgs*	a,
	SetRestoreOriginalConfigOnShutdownCB		cb
    );

    void unmarshall_get_configured_interface_names(
	const XrlError&	e,
	XrlArgs*	a,
	GetConfiguredInterfaceNamesCB		cb
    );

    void unmarshall_get_configured_vif_names(
	const XrlError&	e,
	XrlArgs*	a,
	GetConfiguredVifNamesCB		cb
    );

    void unmarshall_get_configured_vif_flags(
	const XrlError&	e,
	XrlArgs*	a,
	GetConfiguredVifFlagsCB		cb
    );

    void unmarshall_get_configured_vif_pif_index(
	const XrlError&	e,
	XrlArgs*	a,
	GetConfiguredVifPifIndexCB		cb
    );

    void unmarshall_get_configured_vif_addresses4(
	const XrlError&	e,
	XrlArgs*	a,
	GetConfiguredVifAddresses4CB		cb
    );

    void unmarshall_get_configured_vif_addresses6(
	const XrlError&	e,
	XrlArgs*	a,
	GetConfiguredVifAddresses6CB		cb
    );

    void unmarshall_get_configured_address_flags4(
	const XrlError&	e,
	XrlArgs*	a,
	GetConfiguredAddressFlags4CB		cb
    );

    void unmarshall_get_configured_address_flags6(
	const XrlError&	e,
	XrlArgs*	a,
	GetConfiguredAddressFlags6CB		cb
    );

    void unmarshall_get_configured_interface_enabled(
	const XrlError&	e,
	XrlArgs*	a,
	GetConfiguredInterfaceEnabledCB		cb
    );

    void unmarshall_get_configured_interface_discard(
	const XrlError&	e,
	XrlArgs*	a,
	GetConfiguredInterfaceDiscardCB		cb
    );

    void unmarshall_get_configured_mac(
	const XrlError&	e,
	XrlArgs*	a,
	GetConfiguredMacCB		cb
    );

    void unmarshall_get_configured_mtu(
	const XrlError&	e,
	XrlArgs*	a,
	GetConfiguredMtuCB		cb
    );

    void unmarshall_get_configured_vif_enabled(
	const XrlError&	e,
	XrlArgs*	a,
	GetConfiguredVifEnabledCB		cb
    );

    void unmarshall_get_configured_prefix4(
	const XrlError&	e,
	XrlArgs*	a,
	GetConfiguredPrefix4CB		cb
    );

    void unmarshall_get_configured_broadcast4(
	const XrlError&	e,
	XrlArgs*	a,
	GetConfiguredBroadcast4CB		cb
    );

    void unmarshall_get_configured_endpoint4(
	const XrlError&	e,
	XrlArgs*	a,
	GetConfiguredEndpoint4CB		cb
    );

    void unmarshall_get_configured_prefix6(
	const XrlError&	e,
	XrlArgs*	a,
	GetConfiguredPrefix6CB		cb
    );

    void unmarshall_get_configured_endpoint6(
	const XrlError&	e,
	XrlArgs*	a,
	GetConfiguredEndpoint6CB		cb
    );

    void unmarshall_start_transaction(
	const XrlError&	e,
	XrlArgs*	a,
	StartTransactionCB		cb
    );

    void unmarshall_commit_transaction(
	const XrlError&	e,
	XrlArgs*	a,
	CommitTransactionCB		cb
    );

    void unmarshall_abort_transaction(
	const XrlError&	e,
	XrlArgs*	a,
	AbortTransactionCB		cb
    );

    void unmarshall_create_interface(
	const XrlError&	e,
	XrlArgs*	a,
	CreateInterfaceCB		cb
    );

    void unmarshall_delete_interface(
	const XrlError&	e,
	XrlArgs*	a,
	DeleteInterfaceCB		cb
    );

    void unmarshall_configure_interface_from_system(
	const XrlError&	e,
	XrlArgs*	a,
	ConfigureInterfaceFromSystemCB		cb
    );

    void unmarshall_set_interface_enabled(
	const XrlError&	e,
	XrlArgs*	a,
	SetInterfaceEnabledCB		cb
    );

    void unmarshall_set_interface_discard(
	const XrlError&	e,
	XrlArgs*	a,
	SetInterfaceDiscardCB		cb
    );

    void unmarshall_set_mac(
	const XrlError&	e,
	XrlArgs*	a,
	SetMacCB		cb
    );

    void unmarshall_set_mtu(
	const XrlError&	e,
	XrlArgs*	a,
	SetMtuCB		cb
    );

    void unmarshall_create_vif(
	const XrlError&	e,
	XrlArgs*	a,
	CreateVifCB		cb
    );

    void unmarshall_delete_vif(
	const XrlError&	e,
	XrlArgs*	a,
	DeleteVifCB		cb
    );

    void unmarshall_set_vif_enabled(
	const XrlError&	e,
	XrlArgs*	a,
	SetVifEnabledCB		cb
    );

    void unmarshall_create_address4(
	const XrlError&	e,
	XrlArgs*	a,
	CreateAddress4CB		cb
    );

    void unmarshall_delete_address4(
	const XrlError&	e,
	XrlArgs*	a,
	DeleteAddress4CB		cb
    );

    void unmarshall_set_address_enabled4(
	const XrlError&	e,
	XrlArgs*	a,
	SetAddressEnabled4CB		cb
    );

    void unmarshall_get_configured_address_enabled4(
	const XrlError&	e,
	XrlArgs*	a,
	GetConfiguredAddressEnabled4CB		cb
    );

    void unmarshall_set_prefix4(
	const XrlError&	e,
	XrlArgs*	a,
	SetPrefix4CB		cb
    );

    void unmarshall_set_broadcast4(
	const XrlError&	e,
	XrlArgs*	a,
	SetBroadcast4CB		cb
    );

    void unmarshall_set_endpoint4(
	const XrlError&	e,
	XrlArgs*	a,
	SetEndpoint4CB		cb
    );

    void unmarshall_create_address6(
	const XrlError&	e,
	XrlArgs*	a,
	CreateAddress6CB		cb
    );

    void unmarshall_delete_address6(
	const XrlError&	e,
	XrlArgs*	a,
	DeleteAddress6CB		cb
    );

    void unmarshall_set_address_enabled6(
	const XrlError&	e,
	XrlArgs*	a,
	SetAddressEnabled6CB		cb
    );

    void unmarshall_get_configured_address_enabled6(
	const XrlError&	e,
	XrlArgs*	a,
	GetConfiguredAddressEnabled6CB		cb
    );

    void unmarshall_set_prefix6(
	const XrlError&	e,
	XrlArgs*	a,
	SetPrefix6CB		cb
    );

    void unmarshall_set_endpoint6(
	const XrlError&	e,
	XrlArgs*	a,
	SetEndpoint6CB		cb
    );

    void unmarshall_register_client(
	const XrlError&	e,
	XrlArgs*	a,
	RegisterClientCB		cb
    );

    void unmarshall_unregister_client(
	const XrlError&	e,
	XrlArgs*	a,
	UnregisterClientCB		cb
    );

    void unmarshall_get_system_interface_names(
	const XrlError&	e,
	XrlArgs*	a,
	GetSystemInterfaceNamesCB		cb
    );

    void unmarshall_get_system_vif_names(
	const XrlError&	e,
	XrlArgs*	a,
	GetSystemVifNamesCB		cb
    );

    void unmarshall_get_system_vif_flags(
	const XrlError&	e,
	XrlArgs*	a,
	GetSystemVifFlagsCB		cb
    );

    void unmarshall_get_system_vif_pif_index(
	const XrlError&	e,
	XrlArgs*	a,
	GetSystemVifPifIndexCB		cb
    );

    void unmarshall_get_system_vif_addresses4(
	const XrlError&	e,
	XrlArgs*	a,
	GetSystemVifAddresses4CB		cb
    );

    void unmarshall_get_system_address_flags4(
	const XrlError&	e,
	XrlArgs*	a,
	GetSystemAddressFlags4CB		cb
    );

    void unmarshall_get_system_vif_addresses6(
	const XrlError&	e,
	XrlArgs*	a,
	GetSystemVifAddresses6CB		cb
    );

    void unmarshall_get_system_address_flags6(
	const XrlError&	e,
	XrlArgs*	a,
	GetSystemAddressFlags6CB		cb
    );

    void unmarshall_get_system_interface_enabled(
	const XrlError&	e,
	XrlArgs*	a,
	GetSystemInterfaceEnabledCB		cb
    );

    void unmarshall_get_system_interface_discard(
	const XrlError&	e,
	XrlArgs*	a,
	GetSystemInterfaceDiscardCB		cb
    );

    void unmarshall_get_system_mac(
	const XrlError&	e,
	XrlArgs*	a,
	GetSystemMacCB		cb
    );

    void unmarshall_get_system_mtu(
	const XrlError&	e,
	XrlArgs*	a,
	GetSystemMtuCB		cb
    );

    void unmarshall_get_system_vif_enabled(
	const XrlError&	e,
	XrlArgs*	a,
	GetSystemVifEnabledCB		cb
    );

    void unmarshall_get_system_prefix4(
	const XrlError&	e,
	XrlArgs*	a,
	GetSystemPrefix4CB		cb
    );

    void unmarshall_get_system_broadcast4(
	const XrlError&	e,
	XrlArgs*	a,
	GetSystemBroadcast4CB		cb
    );

    void unmarshall_get_system_endpoint4(
	const XrlError&	e,
	XrlArgs*	a,
	GetSystemEndpoint4CB		cb
    );

    void unmarshall_get_system_prefix6(
	const XrlError&	e,
	XrlArgs*	a,
	GetSystemPrefix6CB		cb
    );

    void unmarshall_get_system_endpoint6(
	const XrlError&	e,
	XrlArgs*	a,
	GetSystemEndpoint6CB		cb
    );

    void unmarshall_get_system_address_enabled4(
	const XrlError&	e,
	XrlArgs*	a,
	GetSystemAddressEnabled4CB		cb
    );

    void unmarshall_get_system_address_enabled6(
	const XrlError&	e,
	XrlArgs*	a,
	GetSystemAddressEnabled6CB		cb
    );

    void unmarshall_register_system_interfaces_client(
	const XrlError&	e,
	XrlArgs*	a,
	RegisterSystemInterfacesClientCB		cb
    );

    void unmarshall_unregister_system_interfaces_client(
	const XrlError&	e,
	XrlArgs*	a,
	UnregisterSystemInterfacesClientCB		cb
    );

};

#endif /* __XRL_INTERFACES_FEA_IFMGR_XIF_HH__ */
