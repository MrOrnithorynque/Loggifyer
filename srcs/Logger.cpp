#include <string.h>

#include "PTP/Loggifyer/Logger.hpp"

namespace ptp::log
{
// public methods

    Logger& Logger::getInstance()
    {
        static Logger oSingletonLogger;

        return oSingletonLogger;
    }

    void Logger::log(LogLevel eLevel, const char* file, int line, std::ostringstream& message, ...)
    {
        char buffer[1024];

        std::string sMessage = message.str();

        va_list args;
        va_start(args, message);

        #if defined __linux__ || defined __APPLE__

            vsnprintf(buffer, sizeof(buffer), sMessage.c_str(), args);

        #elif defined _WIN32

            vsprintf_s(buffer, sizeof(buffer), sMessage.c_str(), args);

        #else // unknown platform

            writeMessage(LogLevel::Error, "Unknown platform.", file, line);
            va_end(args);
            return;

        #endif

        va_end(args);

        writeMessage(eLevel, buffer, file, line);
    }

    std::string Logger::getTimestampFormat() const
    {
        auto now = std::chrono::system_clock::now();

        std::time_t t = std::chrono::system_clock::to_time_t(now);

        std::tm tm = *std::localtime(&t);

        std::stringstream timestamp;

        auto elapsed        = now.time_since_epoch();

        auto milliseconds   = std::chrono::duration_cast<std::chrono::milliseconds>(elapsed).count() % 1000;

        timestamp << std::put_time(&tm, "%Y-%m-%d %H:%M:%S") << "." << std::setw(3) << std::setfill('0') << milliseconds;

        return timestamp.str();
    }

    void Logger::setOutput(std::ostream& output)
    {
        m_output = &output;
    }

// private methods

    std::string Logger::formatMessage(const char* sMessage)
    {
        uint16_t            iFormattingSpaceLength = 37;
        std::stringstream   sFormattedMessage;

        for (uint64_t i = 0; sMessage[i] != '\0'; ++i)
        {
            sFormattedMessage << sMessage[i];

            if (sMessage[i] == '\n')
            {
                for (uint16_t j = 1; j < iFormattingSpaceLength; ++j)
                {
                    sFormattedMessage << " ";
                }
            }
        }

        return sFormattedMessage.str();
    }

    void Logger::writeMessage(LogLevel eLevel, const char* message, const char* file, int line)
    {
        std::string sColor;
        std::string sFilepath(file);
        std::string sLevelString;

        filepathWithoutWorkspaceDir(sFilepath);

        switch (eLevel)
        {
            case LogLevel::Fatal:   sLevelString = "[Fatal  ]"; break;
            case LogLevel::Message: sLevelString = "[Message]"; break;
            case LogLevel::Warning: sLevelString = "[Warning]"; break;
            case LogLevel::Error:   sLevelString = "[Error  ]"; break;
            case LogLevel::Ok:      sLevelString = "[Ok     ]"; break;
            case LogLevel::Info:    sLevelString = "[Info   ]"; break;
            default:                sLevelString = "[Message]"; break;
        }

        #if defined __linux__ || defined __APPLE__

            switch (eLevel)
            {
                case LogLevel::Fatal:   sColor = FATAL_RED; break;
                case LogLevel::Message: sColor = WHITE; break;
                case LogLevel::Warning: sColor = YELLOW; break;
                case LogLevel::Error:   sColor = RED; break;
                case LogLevel::Ok:      sColor = GREEN; break;
                case LogLevel::Info:    sColor = BOLD; break;
                default:                sColor = WHITE; break;
            }

            m_oMutex.lock();
            (m_bDisplayFilepath ? ((*m_output) << sFilepath << ":" << line << ": ") : (*m_output) << "");
            (*m_output) << sColor
                    << sLevelString
                << WHITE
                << " "
                << getTimestampFormat()
                << " : "
                << (m_bIsComplexFormattingEnable ? formatMessage(message) : message)
            << std::endl;
            m_oMutex.unlock();

        #elif defined _WIN32

            (m_bDisplayFilepath ? ((*m_output) << file << "(" << line << ") ") : (*m_output) << "");

            // set the color
            switch (eLevel)
            {
                case LogLevel::Fatal:   FATAL_RED; break;
                case LogLevel::Message: WHITE; break;
                case LogLevel::Warning: YELLOW; break;
                case LogLevel::Error:   RED; break;
                case LogLevel::Ok:      GREEN; break;
                case LogLevel::Info:    BOLD; break;
                default:                WHITE; break;
            }

            (*m_output) << sLevelString;

            WHITE; // set the color back to white

            (*m_output) << " "
                << getTimestampFormat()
                << " : "
                << (m_bIsComplexFormattingEnable ? formatMessage(message) : message)
            << std::endl;

        #endif
    }

    void Logger::filepathWithoutWorkspaceDir(std::string& sFilepath)
    {
        if (sFilepath.find(m_sWorkspaceDir) == 0)
        {
            sFilepath.erase(0, m_sWorkspaceDir.length());
        }
    }

} // namespace ptp::log
