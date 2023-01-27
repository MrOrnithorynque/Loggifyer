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
 * @note with complex formatting :
 * @note [log type] 0000-00-00 00:00:00.000 : Matrix A =
 * @note                                          {{0, 0, 0, 0},
 * @note                                           {0, 0, 0, 0},
 * @note                                           {0, 0, 0, 0},
 * @note                                           {0, 0, 0, 0}}
 *
 * @note Without complex formatting :
 * @note [log type] 0000-00-00 00:00:00.000 : Matrix A =
 * @note {{0, 0, 0, 0},
 * @note  {0, 0, 0, 0},
 * @note  {0, 0, 0, 0},
 * @note  {0, 0, 0, 0}}
 */
#define PTP_LOG_COMPLEX_FORMATTING(bEnableComplexFormatting)    \
    if (bEnableComplexFormatting == true)                       \
        ptplog::Logger::getInstance().enableComplexFormatting();\
    else                                                        \
        ptplog::Logger::getInstance().disableComplexFormatting();

#define PTP_LOG_ENABLE_COMPLEX_FORMATTING   \
    PTP_LOG_COMPLEX_FORMATTING(true)

#if defined _WIN32

    #define PTP_LOG(LogLevel, message, ...) { std::ostringstream stream; stream << message;                         \
        if (PTP_IS_LOG_ENABLE && LogLevel >= PTP_GET_LOG_LEVEL)                                    \
            ptplog::Logger::getInstance().log(LogLevel, __FILE__, __LINE__, stream, __VA_ARGS__); }\

    /**
     * @brief Macro print message log message.
     *
     * @note It used printf or cpp stream format style.
     * @note If you want to use printf format style : PTP_LOG_MESSAGE("message %d", 1);
     * @note If you want to use cpp stream format style : PTP_LOG_MESSAGE("message " << 1);
     * @note But not both.
     */
    #define PTP_LOG_MESSAGE(message, ...) { std::ostringstream stream; stream << message;                           \
        if (PTP_IS_LOG_ENABLE && ptplog::LogLevel::Message >= PTP_GET_LOG_LEVEL)                                    \
            ptplog::Logger::getInstance().log(ptplog::LogLevel::Message, __FILE__, __LINE__, stream, __VA_ARGS__); }\

    /**
     * @brief Macro print info log message.
     *
     * @note It used printf or cpp stream format style.
     * @note If you want to use printf format style : PTP_LOG_INFO("message %d", 1);
     * @note If you want to use cpp stream format style : PTP_LOG_INFO("message " << 1);
     * @note But not both.
     */
    #define PTP_LOG_INFO(message, ...) { std::ostringstream stream; stream << message;                              \
        if (PTP_IS_LOG_ENABLE && ptplog::LogLevel::Info >= PTP_GET_LOG_LEVEL)                                       \
            ptplog::Logger::getInstance().log(ptplog::LogLevel::Info, __FILE__, __LINE__, stream, __VA_ARGS__); }   \

    /**
     * @brief Macro print ok log message.
     *
     * @note It used printf or cpp stream format style.
     * @note If you want to use printf format style : PTP_LOG_OK("message %d", 1);
     * @note If you want to use cpp stream format style : PTP_LOG_OK("message " << 1);
     * @note But not both.
     */
    #define PTP_LOG_OK(message, ...) { std::ostringstream stream; stream << message;                            \
        if (PTP_IS_LOG_ENABLE && ptplog::LogLevel::Ok >= PTP_GET_LOG_LEVEL)                                     \
            ptplog::Logger::getInstance().log(ptplog::LogLevel::Ok, __FILE__, __LINE__, stream, __VA_ARGS__); } \

    /**
     * @brief Macro print warning log message.
     *
     * @note It used printf or cpp stream format style.
     * @note If you want to use printf format style : PTP_LOG_WARNING("message %d", 1);
     * @note If you want to use cpp stream format style : PTP_LOG_WARNING("message " << 1);
     * @note But not both.
     */
    #define PTP_LOG_WARNING(message, ...) { std::ostringstream stream; stream << message;                           \
        if (PTP_IS_LOG_ENABLE && ptplog::LogLevel::Warning >= PTP_GET_LOG_LEVEL)                                    \
            ptplog::Logger::getInstance().log(ptplog::LogLevel::Warning, __FILE__, __LINE__, stream, __VA_ARGS__); }\

    /**
     * @brief Macro print error log message.
     *
     * @note It used printf or cpp stream format style.
     * @note If you want to use printf format style : PTP_LOG_ERROR("message %d", 1);
     * @note If you want to use cpp stream format style : PTP_LOG_ERROR("message " << 1);
     * @note But not both.
     */
    #define PTP_LOG_ERROR(message, ...) { std::ostringstream stream; stream << message;                             \
        if (PTP_IS_LOG_ENABLE && ptplog::LogLevel::Error >= PTP_GET_LOG_LEVEL)                                      \
            ptplog::Logger::getInstance().log(ptplog::LogLevel::Error, __FILE__, __LINE__, stream, __VA_ARGS__); }  \

    /**
     * @brief Macro print error log message.
     *
     * @note It used printf or cpp stream format style.
     * @note If you want to use printf format style : PTP_LOG_FATAL("message %d", 1);
     * @note If you want to use cpp stream format style : PTP_LOG_FATAL("message " << 1);
     * @note But not both.
     */
    #define PTP_LOG_FATAL(message, ...) { std::ostringstream stream; stream << message;                             \
        if (PTP_IS_LOG_ENABLE && ptplog::LogLevel::Fatal >= PTP_GET_LOG_LEVEL)                                      \
            ptplog::Logger::getInstance().log(ptplog::LogLevel::Fatal, __FILE__, __LINE__, stream, __VA_ARGS__); }  \

#elif defined __linux__ || __APPLE__

    /**
     * @brief Macro print log message.
     * @param LogLevel log level.
     * @param message log message.
     */
    #define PTP_LOG(LogLevel, message, ...) { std::ostringstream stream; stream << message;                         \
        if (PTP_IS_LOG_ENABLE && LogLevel >= PTP_GET_LOG_LEVEL)                                                     \
            ptplog::Logger::getInstance().log(LogLevel, __FILE__, __LINE__, stream __VA_OPT__(,) __VA_ARGS__); }    \

    /**
     * @brief Macro print message log message.
     *
     * @note It used printf or cpp stream format style.
     * @note If you want to use printf format style : PTP_LOG_MESSAGE("message %d", 1);
     * @note If you want to use cpp stream format style : PTP_LOG_MESSAGE("message " << 1);
     * @note But not both.
     */
    #define PTP_LOG_MESSAGE(message, ...) PTP_LOG(ptplog::LogLevel::Message, message, __VA_ARGS__)

    /**
     * @brief Macro print info log message.
     *
     * @note It used printf or cpp stream format style.
     * @note If you want to use printf format style : PTP_LOG_INFO("message %d", 1);
     * @note If you want to use cpp stream format style : PTP_LOG_INFO("message " << 1);
     * @note But not both.
     */
    #define PTP_LOG_INFO(message, ...) PTP_LOG(ptplog::LogLevel::Info, message, __VA_ARGS__)

    /**
     * @brief Macro print ok log message.
     *
     * @note It used printf or cpp stream format style.
     * @note If you want to use printf format style : PTP_LOG_OK("message %d", 1);
     * @note If you want to use cpp stream format style : PTP_LOG_OK("message " << 1);
     * @note But not both.
     */
    #define PTP_LOG_OK(message, ...) PTP_LOG(ptplog::LogLevel::Ok, message, __VA_ARGS__)

    /**
     * @brief Macro print warning log message.
     *
     * @note It used printf or cpp stream format style.
     * @note If you want to use printf format style : PTP_LOG_WARNING("message %d", 1);
     * @note If you want to use cpp stream format style : PTP_LOG_WARNING("message " << 1);
     * @note But not both.
     */
    #define PTP_LOG_WARNING(message, ...) PTP_LOG(ptplog::LogLevel::Warning, message, __VA_ARGS__)

    /**
     * @brief Macro print error log message.
     *
     * @note It used printf or cpp stream format style.
     * @note If you want to use printf format style : PTP_LOG_ERROR("message %d", 1);
     * @note If you want to use cpp stream format style : PTP_LOG_ERROR("message " << 1);
     * @note But not both.
     */
    #define PTP_LOG_ERROR(message, ...) PTP_LOG(ptplog::LogLevel::Error, message, __VA_ARGS__)

    /**
     * @brief Macro print fatal log message.
     *
     * @note It used printf or cpp stream format style.
     * @note If you want to use printf format style : PTP_LOG_FATAL("message %d", 1);
     * @note If you want to use cpp stream format style : PTP_LOG_FATAL("message " << 1);
     * @note But not both.
     */
    #define PTP_LOG_FATAL(message, ...) PTP_LOG(ptplog::LogLevel::Fatal, message, __VA_ARGS__)

#endif
