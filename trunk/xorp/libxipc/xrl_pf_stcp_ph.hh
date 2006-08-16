// -*- c-basic-offset: 4; tab-width: 8; indent-tabs-mode: t -*-

// Copyright (c) 2001-2006 International Computer Science Institute
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

// $XORP: xorp/libxipc/xrl_pf_stcp_ph.hh,v 1.11 2006/08/16 18:45:24 pavlin Exp $

#ifndef __LIBXIPC_XRL_PF_STCP_PH_HH__
#define __LIBXIPC_XRL_PF_STCP_PH_HH__

// major and minor maybe defined on system, undefine them
#ifdef major
#undef major
#endif

#ifdef minor
#undef minor
#endif

// STCP Packet Type enumerations

enum STCPPacketType {
    STCP_PT_HELO	= 0x00,
    STCP_PT_HELO_ACK	= 0x01,
    STCP_PT_REQUEST	= 0x02,
    STCP_PT_RESPONSE	= 0x03
};

// STCP Packet Header.
class STCPPacketHeader {
public:
    STCPPacketHeader(uint8_t* data);

    static const size_t SIZE = 24;	// STCP Packet Header size

    void initialize(uint32_t		seqno,
		    STCPPacketType	type,
		    const XrlError&	err,
		    uint32_t		xrl_data_bytes);

    static const size_t header_size() { return STCPPacketHeader::SIZE; }

    bool is_valid() const;

    uint32_t fourcc() const;

    uint8_t  major() const;

    uint8_t  minor() const;

    STCPPacketType type() const;

    uint32_t seqno() const;

    uint32_t error_code() const;

    uint32_t error_note_bytes() const;

    uint32_t xrl_data_bytes() const;

    uint32_t payload_bytes() const;

    // Sum of header, error note, and payload bytes.
    uint32_t frame_bytes() const;

private:
    //
    // The STCP packet header has the following content:
    //
    // fourcc (4 bytes): fourcc 'S' 'T' 'C' 'P'
    // major  (1 byte):  Major version
    // minor  (1 byte):  Minor version
    // seqno  (4 bytes): Sequence number
    // type   (2 bytes): Type: bits [15:7] set to zero, [0:1] hello/req./resp.
    // error_code (4 bytes): XrlError code
    // error_note_bytes (4 bytes): Length of note (if any) assoc. w/ code
    // xrl_data_bytes (4 bytes): Xrl return args data bytes
    //

    uint8_t* _data;		// The buffer data with the header

    // Pointers to the header fields
    uint8_t* _fourcc;		// fourcc 'S' 'T' 'C' 'P'
    uint8_t* _major;		// Major version
    uint8_t* _minor;		// Minor version
    uint8_t* _seqno;		// Sequence number
    uint8_t* _type;		// [15:7] Set to zero, [0:1] hello/req./resp.
    uint8_t* _error_code;	// XrlError code
    uint8_t* _error_note_bytes;	// Length of note (if any) assoc. w/ code
    uint8_t* _xrl_data_bytes;	// Xrl return args data bytes

    // Sizes of the header fields
    static const size_t _fourcc_sizeof = 4;
    static const size_t _major_sizeof = 1;
    static const size_t _minor_sizeof = 1;
    static const size_t _seqno_sizeof = 4;
    static const size_t _type_sizeof = 2;
    static const size_t _error_code_sizeof = 4;
    static const size_t _error_note_bytes_sizeof = 4;
    static const size_t _xrl_data_bytes_sizeof = 4;

    // Offsets for the header fields
    static const size_t _fourcc_offset = 0;
    static const size_t _major_offset = _fourcc_offset + _fourcc_sizeof;
    static const size_t _minor_offset = _major_offset + _major_sizeof;
    static const size_t _seqno_offset = _minor_offset + _minor_sizeof;
    static const size_t _type_offset = _seqno_offset + _seqno_sizeof;
    static const size_t _error_code_offset = _type_offset + _type_sizeof;
    static const size_t _error_note_bytes_offset = _error_code_offset + _error_code_sizeof;
    static const size_t _xrl_data_bytes_offset = _error_note_bytes_offset + _error_note_bytes_sizeof;
};

#endif // __LIBXIPC_XRL_PF_STCP_PH_HH__
