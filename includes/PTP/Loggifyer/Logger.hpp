#pragma once

#include <iostream>
#include <stdarg.h>
#include <iomanip>
#include <sstream>
#include <chrono>
#include <ctime>
#include <mutex>

#ifdef _WIN32

    #include <windows.h>

    #define BOLD        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY)
    #define WHITE       SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED     | FOREGROUND_GREEN      | FOREGROUND_BLUE | FOREGROUND_INTENSITY)
    #define FATAL_RED   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED     | FOREGROUND_INTENSITY  | FOREGROUND_INTENSITY)
    #define ORANGE      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED     | FOREGROUND_GREEN      | FOREGROUND_INTENSITY)
    #define YELLOW      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED     | FOREGROUND_GREEN      | FOREGROUND_INTENSITY)
    #define RED         SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED     | FOREGROUND_INTENSITY)
    #define BLUE        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE    | FOREGROUND_INTENSITY)
    #define GREEN       SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN   | FOREGROUND_INTENSITY)

#else // Linux or Mac

    #define BOLD        "\033[1m"
    #define RED         "\033[1;31m"
    #define YELLOW      "\033[1;33m"
    #define GREEN       "\033[1;32m"
    #define BLUE        "\033[1;34m"
    #define ORANGE      "\033[1;91m"
    #define WHITE       "\033[0m"
    #define FATAL_RED   "\033[1;41;30m"

#endif

namespace ptp::log
{
    enum class LogLevel
    {
        All     = -1,   /// @brief All log levels.
        Message = 0,    /// @brief Message log level.
        Info,           /// @brief Info log level.
        Ok,             /// @brief Ok log level.
        Warning,        /// @brief Warning log level.
        Error,          /// @brief Error log level.
        Fatal,          /// @brief Fatal log level.
        None,           /// @brief No log level.
    };

    /**
     * @class Logger
     * @brief Logging class that handles log message generation and output.
     *
     * @note The Logger class is a singleton that provides a centralized logging mechanism for the Loggifyer library.
     * It allows users to output log messages at different levels of severity, and provides methods for
     * enabling and disabling logging, as well as setting the format of the log messages.
     */
    class Logger
    {
    public:

        /**
         * @brief Default constructor.
         *
         * The default constructor sets the log level to "debug" and enables logging.
         */
        Logger() = default;


        Logger(Logger &) = delete;

        void operator=(const Logger &) = delete;

        /**
         * @brief Gets the singleton instance of the Logger class.
         *
         * @return Logger& A reference to the singleton instance of the Logger class.
         */
        static Logger& getInstance();

        /**
         * @brief Logs a message at a specific level of severity.
         *
         * @param eLevel The severity level of the log message.
         * @param file The file name where the log message was generated.
         * @param line The line number where the log message was generated.
         * @param message The message to be logged.
         * @param ... Additional parameters to be included in the log message.
         */
        void log(LogLevel eLevel, const char* file, int line, const std::ostringstream& message, ...);

        /**
         * @brief Gets the format of the timestamp included in the log messages.
         *
         * @return std::string The format of the timestamp.
         */
        std::string getTimestampFormat() const;

        /**
         * @brief Sets the output stream for the log messages.
         *
         * @param output The output stream for the log messages.
         *
         * @note The output can be a file, or just the standard output.
         * @warning When threaded it can be dangerous to use the same output stream for multiple threads.
         */
        void setOutput(std::ostream& output);

        /**
         * @brief Gets the current log level.
         *
         * @return LogLevel The current log level.
         */
        inline LogLevel getLogLevel();

        /**
         * @brief Sets the log level.
         *
         * @param eLogLevel The new log level.
         */
        inline void setLogLevel(LogLevel eLogLevel);

        inline void setWorkspaceDir(const std::string &sWorkspaceDir)
        {
            m_sWorkspaceDir = sWorkspaceDir;
        }

        /**
         * @brief Enables logging.
         */
        inline void enableLog();

        /**
         * @brief Disables logging.
         */
        inline void disableLog();

        /**
         * @brief Enables complex formatting of log messages.
         */
        inline void enableComplexFormatting();

        /**
         * @brief Disables complex formatting of log messages.
         */
        inline void disableComplexFormatting();

        /**
         * @brief
         *
         * @param bDisplayFilepath
         */
        inline void displayFilepath(bool bDisplayFilepath);

        /**
         * @brief Indicates whether logging is currently enabled.
         *
         * @return bool True if logging is enabled, false otherwise.
         */
        inline bool isLogEnabled();

    private:

        /**
         * @brief Formats the log message by prepending timestamp and log level information.
         * @param sMessage The log message to be formatted
         * @return The formatted log message
         */
        std::string formatMessage(const char* sMessage);

        /**
         * Writes the log message to the console or file.
         * @param eLevel The log level of the message
         * @param message The log message to be written
         * @param file The source file where the log call was made
         * @param line The line number in the source file where the log call was made
         */
        void writeMessage(LogLevel eLevel, const char* message, const char* file, int line);

        void filepathWithoutWorkspaceDir(std::string& sFilepath);

        std::mutex      m_oMutex;

        std::mutex      m_oEnableLogsMutex;

        std::mutex      m_oTimestampMutex;

        std::mutex      m_oGlobalLogLevelMutex;

        std::mutex      m_oComplexFormattingMutex;

        LogLevel        m_eGlobalLogLevel               = LogLevel::Message;

        bool            m_bIsLogEnable                  = true;

        bool            m_bIsComplexFormattingEnable    = false;

        bool            m_bDisplayFilepath              = true;

        std::ostream*   m_output                       = &std::cout;

        std::string     m_sWorkspaceDir                = "";

    };

} // namespace ptp::log

// Includes for inline functions
#include "Logger.inl"
