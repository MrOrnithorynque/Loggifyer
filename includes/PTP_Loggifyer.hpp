#pragma once

#include "Logger.hpp"

/**
 * @brief Macro to initialize the logger.
 */
// #define PTP_INIT_LOGGIFYER              ptp::log::Logger* ptp::log::Logger::oSingletonLogger = nullptr;

/**
 * @brief Macro to get the instance of the logger.
 */
#define PTP_GET_LOG_INSTANCE            ptp::log::Logger::getInstance()

/**
 * @brief Macro to set the log level.
 * @param eLogLevel The log level to set.
 */
#define PTP_SET_LOG_LEVEL(eLogLevel)    PTP_GET_LOG_INSTANCE.setLogLevel(eLogLevel)

/**
 * @brief Macro to get the log level.
 */
#define PTP_GET_LOG_LEVEL               PTP_GET_LOG_INSTANCE.getLogLevel()

/**
 * @brief Macro to get the current formatted timestamp.
 */
#define PTP_GET_TIMESTAMP_FORMAT        PTP_GET_LOG_INSTANCE.getTimestampFormat()

/**
 * @brief Macro to enable the logs.
 */
#define PTP_ENABLE_LOGS                 PTP_GET_LOG_INSTANCE.enableLog();

/**
 * @brief Macro to disable the logs.
 */
#define PTP_DISABLE_LOGS                PTP_GET_LOG_INSTANCE.disableLog();

/**
 * @brief Macro check if the logs are enable.
 */
#define PTP_IS_LOG_ENABLE               PTP_GET_LOG_INSTANCE.ptp::log::Logger::isLogEnabled()

/**
 * Macro to enable complex formatting on logs.
 *
 * with complex formatting :
 * [log type] 0000-00-00 00:00:00.000 : Matrix A =
 *                                          {{0, 0, 0, 0},
 *                                           {0, 0, 0, 0},
 *                                           {0, 0, 0, 0},
 *                                           {0, 0, 0, 0}}
 *
 * Without complex formatting :
 * [log type] 0000-00-00 00:00:00.000 : Matrix A =
 * {{0, 0, 0, 0},
 *  {0, 0, 0, 0},
 *  {0, 0, 0, 0},
 *  {0, 0, 0, 0}}
 */
#define PTP_LOG_COMPLEX_FORMATTING(bEnableComplexFormatting)    \
    do {                                                        \
        if (bEnableComplexFormatting == true)                   \
            PTP_GET_LOG_INSTANCE.enableComplexFormatting();     \
        else                                                    \
            PTP_GET_LOG_INSTANCE.disableComplexFormatting();    \
    } while (false)                                             \

/**
 * @brief Macro print message log message.
 *
 * @note It used printf format style.
 */
#define PTP_LOG_MESSAGE(message, ...)                                                           \
    do {                                                                                        \
        if (PTP_IS_LOG_ENABLE && ptp::log::LogLevel::Message >= PTP_GET_LOG_LEVEL)        \
            PTP_GET_LOG_INSTANCE.log(ptp::log::LogLevel::Message, message, ##__VA_ARGS__);\
    } while (false)

/**
 * @brief Macro print info log message.
 *
 * @note It used printf format style.
 */
#define PTP_LOG_INFO(message, ...)                                                              \
    do {                                                                                        \
        if (PTP_IS_LOG_ENABLE && ptp::log::LogLevel::Info >= PTP_GET_LOG_LEVEL)           \
            PTP_GET_LOG_INSTANCE.log(ptp::log::LogLevel::Info, message, ##__VA_ARGS__);   \
    } while (false)

/**
 * @brief Macro print ok log message.
 *
 * @note It used printf format style.
 */
#define PTP_LOG_OK(message, ...)                                                            \
    do {                                                                                    \
        if (PTP_IS_LOG_ENABLE && ptp::log::LogLevel::Ok >= PTP_GET_LOG_LEVEL)         \
            PTP_GET_LOG_INSTANCE.log(ptp::log::LogLevel::Ok, message, ##__VA_ARGS__); \
    } while (false)

/**
 * @brief Macro print warning log message.
 *
 * @note It used printf format style.
 */
#define PTP_LOG_WARNING(message, ...)                                                           \
    do {                                                                                        \
        if (PTP_IS_LOG_ENABLE && ptp::log::LogLevel::Warning >= PTP_GET_LOG_LEVEL)        \
            PTP_GET_LOG_INSTANCE.log(ptp::log::LogLevel::Warning, message, ##__VA_ARGS__);\
    } while (false)

/**
 * @brief Macro print error log message.
 *
 * @note It used printf format style.
 */
#define PTP_LOG_ERROR(message, ...)                                                             \
    do {                                                                                        \
        if (PTP_IS_LOG_ENABLE && ptp::log::LogLevel::Error >= PTP_GET_LOG_LEVEL)          \
            PTP_GET_LOG_INSTANCE.log(ptp::log::LogLevel::Error, message, ##__VA_ARGS__);  \
    } while (false)
