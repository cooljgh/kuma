/* Copyright (c) 2014, Fengping Bao <jamol@live.com>
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef __h2defs_H__
#define __h2defs_H__

KUMA_NS_BEGIN

const uint32_t H2_MAX_STREAM_ID = 0x7FFFFFFF;
const uint32_t H2_FRAME_HEADER_SIZE = 9;

const uint8_t H2_FRAME_FLAG_END_STREAM = 0x1;
const uint8_t H2_FRAME_FLAG_ACK = 0x1;
const uint8_t H2_FRAME_FLAG_END_HEADERS = 0x4;
const uint8_t H2_FRAME_FLAG_PADDED = 0x8;
const uint8_t H2_FRAME_FLAG_PRIORITY = 0x20;

#define H2_PING_FRAME_DATA_LENGTH 8

enum H2FrameType : uint8_t {
    DATA            = 0,
    HEADERS         = 1,
    PRIORITY        = 2,
    RST_STREAM      = 3,
    SETTINGS        = 4,
    PUSH_PROMISE    = 5,
    PING            = 6,
    GOAWAY          = 7,
    WINDOW_UPDATE   = 8,
    CONTINUATION    = 9
};

enum class H2SettingsId : uint16_t {
    HEADER_TABLE_SIZE       = 1,
    ENABLE_PUSH             = 2,
    MAX_CONCURRENT_STREAMS  = 3,
    INITIAL_WINDOW_SIZE     = 4,
    MAX_FRAME_SIZE          = 5,
    MAX_HEADER_LIST_SIZE    = 6
};

enum class H2Error : int32_t {
    NO_ERROR                = 0x0,
    PROTOCOL_ERROR          = 0x1,
    INTERNAL_ERROR          = 0x2,
    FLOW_CONTROL_ERROR      = 0x3,
    SETTINGS_TIMEOUT        = 0x4,
    STREAM_CLOSED           = 0x5,
    FRAME_SIZE_ERROR        = 0x6,
    REFUSED_STREAM          = 0x7,
    CANCEL                  = 0x8,
    COMPRESSION_ERROR       = 0x9,
    CONNECT_ERROR           = 0xa,
    ENHANCE_YOUR_CALM       = 0xb,
    INADEQUATE_SECURITY     = 0xc,
    HTTP_1_1_REQUIRED       = 0xd
};

KUMA_NS_END

#endif
