#pragma once

#include <iostream>
#include <stdarg.h>
#include <iomanip>
#include <sstream>
#include <chrono>
#include <ctime>
#include <mutex>

#ifdef _WIN32

    // Windows
    #include <windows.h>

    #define RED SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY)
    #define YELLOW SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY)
    #define GREEN SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY)
    #define BLUE SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_INTENSITY)
    #define ORANGE SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY)
    #define WHITE SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY)

#else

    // Linux or Mac
    #define RED "\033[31m"
    #define YELLOW "\033[33m"
    #define GREEN "\033[32m"
    #define BLUE "\033[34m"
    #define ORANGE "\033[91m"
    #define WHITE "\033[0m"

#endif

namespace ptp::log
{
    enum class LogLevel
    {
        All     = -1,
        Message = 0,
        Info,
        Ok,
        Warning,
        Error,
        None,
    };

    /**
     * @brief Singleton class Logger. Use the PTP_LOG_INIT macro to initialize the logger.
     */
    class Logger
    {
    public:

        Logger() = default;

        Logger(Logger &) = delete;

        void operator=(const Logger &) = delete;

        static Logger& getInstance();

        void log(LogLevel eLevel, const char* file, int line, std::ostringstream& message, ...);

        inline std::string getTimestampFormat() const;

        inline LogLevel getLogLevel();

        inline void setLogLevel(LogLevel eLogLevel);

        inline void enableLog();

        inline void disableLog();

        inline void enableComplexFormatting();

        inline void disableComplexFormatting();

        inline bool isLogEnabled();

    private:

        std::string formatMessage(const char* sMessage);

        void writeMessage(LogLevel eLevel, const char* message, const char* file, int line);

        std::mutex      m_oMutex;

        std::mutex      m_oEnableLogsMutex;

        std::mutex      m_oTimestampMutex;

        std::mutex      m_oGlobalLogLevelMutex;

        std::mutex      m_oComplexFormattingMutex;

        LogLevel        m_eGlobalLogLevel               = LogLevel::Message;

        bool            m_bIsLogEnable                  = true;

        bool            m_bIsComplexFormattingEnable    = false;

    };

} // namespace ptp::log

// Includes for inline functions
#include "Logger.inl"
