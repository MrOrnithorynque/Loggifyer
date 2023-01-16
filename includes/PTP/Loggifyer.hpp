#pragma once

#include "Loggifyer/Logger.hpp"

namespace ptplog = ptp::log;

/**
 * @brief Macro to initialize the logger.
 */
// #define PTP_INIT_LOGGIFYER              ptp::log::Logger* ptp::log::Logger::oSingletonLogger = nullptr;

/**
 * @brief Macro to set the log level.
 * @param eLogLevel The log level to set.
 */
#define PTP_SET_LOG_LEVEL(eLogLevel)    ptplog::Logger::getInstance().setLogLevel(eLogLevel)

/**
 * @brief Macro to get the log level.
 */
#define PTP_GET_LOG_LEVEL               ptplog::Logger::getInstance().getLogLevel()

/**
 * @brief Macro to get the current formatted timestamp.
 */
#define PTP_GET_TIMESTAMP_FORMAT        ptplog::Logger::getInstance().getTimestampFormat()

/**
 * @brief Macro to enable the logs.
 */
#define PTP_ENABLE_LOGS                 ptplog::Logger::getInstance().enableLog();

/**
 * @brief Macro to disable the logs.
 */
#define PTP_DISABLE_LOGS                ptplog::Logger::getInstance().disableLog();

/**
 * @brief Macro check if the logs are enable.
 */
#define PTP_IS_LOG_ENABLE               ptplog::Logger::getInstance().ptplog::Logger::isLogEnabled()

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
    if (bEnableComplexFormatting == true)                       \
        ptplog::Logger::getInstance().enableComplexFormatting();         \
    else                                                        \
        ptplog::Logger::getInstance().disableComplexFormatting();

#define PTP_LOG_ENABLE_COMPLEX_FORMATTING   \
    PTP_LOG_COMPLEX_FORMATTING(true)

#if defined __GNUC__

    /**
     * @brief Macro print message log message.
     *
     * @note It used printf format style.
     */
    #define PTP_LOG_MESSAGE(message, ...)                                                   \
        if (PTP_IS_LOG_ENABLE && ptplog::LogLevel::Message >= PTP_GET_LOG_LEVEL)          \
            ptplog::Logger::getInstance().log(ptplog::LogLevel::Message, __FILE__, __LINE__, message __VA_OPT__(,) __VA_ARGS__);

    /**
     * @brief Macro print info log message.
     *
     * @note It used printf format style.
     */
    #define PTP_LOG_INFO(message, ...)                                                  \
        if (PTP_IS_LOG_ENABLE && ptplog::LogLevel::Info >= PTP_GET_LOG_LEVEL)         \
            ptplog::Logger::getInstance().log(ptplog::LogLevel::Info, __FILE__, __LINE__, message __VA_OPT__(,) __VA_ARGS__);

    /**
     * @brief Macro print ok log message.
     *
     * @note It used printf format style.
     */
    #define PTP_LOG_OK(message, ...)                                                        \
        if (PTP_IS_LOG_ENABLE && ptplog::LogLevel::Ok >= PTP_GET_LOG_LEVEL)                 \
            ptplog::Logger::getInstance().log(ptplog::LogLevel::Ok, __FILE__, __LINE__, message __VA_OPT__(,) __VA_ARGS__);

    /**
     * @brief Macro print warning log message.
     *
     * @note It used printf format style.
     */
    #define PTP_LOG_WARNING(message, ...)                                                   \
        if (PTP_IS_LOG_ENABLE && ptplog::LogLevel::Warning >= PTP_GET_LOG_LEVEL)            \
            ptplog::Logger::getInstance().log(ptplog::LogLevel::Warning, __FILE__, __LINE__, message __VA_OPT__(,) __VA_ARGS__);

    /**
     * @brief Macro print error log message.
     *
     * @note It used printf format style.
     */
    #define PTP_LOG_ERROR(message, ...)                                                     \
        if (PTP_IS_LOG_ENABLE && ptplog::LogLevel::Error >= PTP_GET_LOG_LEVEL)              \
            ptplog::Logger::getInstance().log(ptplog::LogLevel::Error, __FILE__, __LINE__, message __VA_OPT__(,) __VA_ARGS__);

#endif // __GNUC__

#if defined __clang__ || defined _MSC_VER

    /**
     * @brief Macro print message log message.
     *
     * @note It used printf format style.
     */
    #define PTP_LOG_MESSAGE(message, ...)                                                   \
        if (PTP_IS_LOG_ENABLE && ptplog::LogLevel::Message >= PTP_GET_LOG_LEVEL)          \
            ptplog::Logger::getInstance().log(ptplog::LogLevel::Message, __FILE__, __LINE__, message __VA_OPT__(,) __VA_ARGS__);

    /**
     * @brief Macro print info log message.
     *
     * @note It used printf format style.
     */
    #define PTP_LOG_INFO(message, ...)                                                  \
        if (PTP_IS_LOG_ENABLE && ptplog::LogLevel::Info >= PTP_GET_LOG_LEVEL)         \
            _Pragma("clang diagnostic push") \
            _Pragma("clang diagnostic ignored \"-Wgnu-zero-variadic-macro-arguments\"") \
            ptplog::Logger::getInstance().log(ptplog::LogLevel::Info, __FILE__, __LINE__, message __VA_OPT__(,) __VA_ARGS__); \
            _Pragma("clang diagnostic pop")\

    /**
     * @brief Macro print ok log message.
     *
     * @note It used printf format style.
     */
    #define PTP_LOG_OK(message, ...)                                                        \
        if (PTP_IS_LOG_ENABLE && ptplog::LogLevel::Ok >= PTP_GET_LOG_LEVEL)                 \
            ptplog::Logger::getInstance().log(ptplog::LogLevel::Ok, __FILE__, __LINE__, message __VA_OPT__(,) __VA_ARGS__);

    /**
     * @brief Macro print warning log message.
     *
     * @note It used printf format style.
     */
    #define PTP_LOG_WARNING(message, ...)                                                   \
        if (PTP_IS_LOG_ENABLE && ptplog::LogLevel::Warning >= PTP_GET_LOG_LEVEL)            \
            ptplog::Logger::getInstance().log(ptplog::LogLevel::Warning, __FILE__, __LINE__, message __VA_OPT__(,) __VA_ARGS__);

    /**
     * @brief Macro print error log message.
     *
     * @note It used printf format style.
     */
    #define PTP_LOG_ERROR(message, ...)                                                     \
        if (PTP_IS_LOG_ENABLE && ptplog::LogLevel::Error >= PTP_GET_LOG_LEVEL)              \
            ptplog::Logger::getInstance().log(ptplog::LogLevel::Error, __FILE__, __LINE__, message __VA_OPT__(,) __VA_ARGS__);

    #ifdef __clang__
    #pragma clang diagnostic pop
    #endif

    #ifdef _MSC_VER
    #pragma warning(pop)
    #endif

#endif // __clang__ || _MSC_VER
