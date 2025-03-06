/*
 * WPA Supplicant - Helper functions for USD
 * Copyright (c) 2025, Google Inc. All rights reserved.
 *
 * This software may be distributed under the terms of the BSD license.
 * See README for more details.
 */

#ifndef MAINLINE_SUPPLICANT_USD_UTILS_H
#define MAINLINE_SUPPLICANT_USD_UTILS_H

extern "C"
{
#include "utils/common.h"
#include "src/common/nan_de.h"
}

constexpr bool kIsUsdPublisherSupported = true;
constexpr bool kIsUsdSubscriberSupported = true;
constexpr int32_t kMaxUsdLocalSsiLengthBytes = 1400;
constexpr int32_t kMaxUsdServiceNameLengthBytes = 255;
constexpr int32_t kMaxUsdMatchFilterLengthBytes = 0;
constexpr int32_t kMaxNumUsdPublishSessions = NAN_DE_MAX_SERVICE;
constexpr int32_t kMaxNumUsdSubscribeSessions = NAN_DE_MAX_SERVICE;

// TODO: Add helper functions here

#endif // MAINLINE_SUPPLICANT_USD_UTILS_H
