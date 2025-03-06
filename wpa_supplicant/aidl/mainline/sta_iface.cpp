/*
 * WPA Supplicant - Station mode interface
 * Copyright (c) 2024, Google Inc. All rights reserved.
 *
 * This software may be distributed under the terms of the BSD license.
 * See README for more details.
 */

#include "sta_iface.h"
#include "usd_utils.h"

extern "C"
{
#include "utils/common.h"
#include "nan_usd.h"
#include "wpa_supplicant_i.h"
}

StaIface::StaIface(struct wpa_global* wpa_global, std::string iface_name)
    : wpa_global_(wpa_global), iface_name_(iface_name) {}

struct wpa_supplicant* StaIface::retrieveIfacePtr() {
    return wpa_supplicant_get_iface(wpa_global_, iface_name_.c_str());
}

::ndk::ScopedAStatus StaIface::registerCallback(
        const std::shared_ptr<IStaInterfaceCallback>& in_callback) {
    return ndk::ScopedAStatus::ok();
}

::ndk::ScopedAStatus StaIface::getUsdCapabilities(UsdCapabilities* _aidl_return) {
    UsdCapabilities capabilities;
    capabilities.isUsdPublisherSupported = kIsUsdPublisherSupported;
    capabilities.isUsdSubscriberSupported = kIsUsdSubscriberSupported;
    capabilities.maxLocalSsiLengthBytes = kMaxUsdLocalSsiLengthBytes;
    capabilities.maxServiceNameLengthBytes = kMaxUsdServiceNameLengthBytes;
    capabilities.maxMatchFilterLengthBytes = kMaxUsdMatchFilterLengthBytes;
    capabilities.maxNumPublishSessions = kMaxNumUsdPublishSessions;
    capabilities.maxNumSubscribeSessions = kMaxNumUsdSubscribeSessions;
    *_aidl_return = capabilities;
    return ndk::ScopedAStatus::ok();
}

::ndk::ScopedAStatus StaIface::startUsdPublish(int32_t in_cmdId,
        const UsdPublishConfig& in_publishConfig) {
    return ndk::ScopedAStatus::ok();
}

::ndk::ScopedAStatus StaIface::startUsdSubscribe(int32_t in_cmdId,
        const UsdSubscribeConfig& in_subscribeConfig) {
    return ndk::ScopedAStatus::ok();
}

::ndk::ScopedAStatus StaIface::updateUsdPublish(int32_t in_publishId,
        const std::vector<uint8_t>& in_serviceSpecificInfo) {
    return ndk::ScopedAStatus::ok();
}

::ndk::ScopedAStatus StaIface::cancelUsdPublish(int32_t publishId) {
    // Status code is returned by the callback
    wpas_nan_usd_cancel_publish(retrieveIfacePtr(), publishId);
    return ndk::ScopedAStatus::ok();
}

::ndk::ScopedAStatus StaIface::cancelUsdSubscribe(int32_t subscribeId) {
    // Status code is returned by the callback
    wpas_nan_usd_cancel_subscribe(retrieveIfacePtr(), subscribeId);
    return ndk::ScopedAStatus::ok();
}

::ndk::ScopedAStatus StaIface::sendUsdMessage(const UsdMessageInfo& in_messageInfo) {
    return ndk::ScopedAStatus::ok();
}
