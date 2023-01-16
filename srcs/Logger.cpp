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

    void Logger::log(LogLevel eLevel, const char* file, int line, const char* message, ...)
    {
        char buffer[1024];

        va_list args;
        va_start(args, message);

        #if defined __linux__

            vsnprintf(buffer, sizeof(buffer), message, args);

        #elif defined _WIN32

            vsprintf_s(buffer, sizeof(buffer), message, args);

        #else // unknown platform

            writeMessage(LogLevel::Error, "Unknown platform.", file, line);
            va_end(args);
            return;

        #endif

        va_end(args);

        writeMessage(eLevel, buffer, file, line);
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
        std::string color = (eLevel == LogLevel::Message)
            ? WHITE : (eLevel == LogLevel::Warning)
                ? YELLOW : (eLevel == LogLevel::Error)
                    ? RED : (eLevel == LogLevel::Ok)
                        ? GREEN : WHITE;

        std::string levelString = (eLevel == LogLevel::Message)
            ? "[Message]" : (eLevel == LogLevel::Warning)
                ? "[Warning]" : (eLevel == LogLevel::Error)
                    ? "[Error  ]" : (eLevel == LogLevel::Ok)
                        ? "[Ok     ]" : "[Info   ]";

        std::cerr
            << file << "(" << line << ")\t"
            << color
                << levelString
            << WHITE
            << " "
            << getTimestampFormat()
            << " : "
            << (m_bIsComplexFormattingEnable ? formatMessage(message) : message)
        << std::endl;
    }

} // namespace ptp::log
