/**
 * @file TestLoggifyer.cpp
 * @author MrOrnithorynque
 * @brief
 * @version 0.1
 * @date 2023-03-07
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <gtest/gtest.h>

#include "PTP/Loggifyer.hpp"

TEST(EVENT_REGISTRY, testLoggifyer) {
    PTP_LOG_DISPLAY_FILEPATH(false);
    PTP_LOG_INFO("TEST");
}
