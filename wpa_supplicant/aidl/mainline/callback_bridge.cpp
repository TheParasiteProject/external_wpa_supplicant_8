/*
 * WPA Supplicant - Interface to receive callbacks from the core supplicant
 * Copyright (c) 2025, Google Inc. All rights reserved.
 *
 * This software may be distributed under the terms of the BSD license.
 * See README for more details.
 */

#include "utils.h"
#include "usd_utils.h"

extern "C"
{
#include "callback_bridge.h"
}

void mainline_aidl_notify_usd_service_discovered(struct wpa_supplicant *wpa_s,
        enum nan_service_protocol_type srv_proto_type,
        int subscribe_id, int peer_publish_id, const u8 *peer_addr,
        bool fsd, const u8 *ssi, size_t ssi_len) {
    if (!wpa_s || !peer_addr)
        return;

    auto callback = getStaIfaceCallback(wpa_s->ifname);
    if (!callback)
        return;

    wpa_printf(MSG_DEBUG, "Notifying USD service discovered");
    auto serviceDiscoveryInfo = createUsdServiceDiscoveryInfo(
        srv_proto_type, subscribe_id, peer_publish_id, peer_addr, fsd, ssi, ssi_len);
    callback->onUsdServiceDiscovered(serviceDiscoveryInfo);
}
