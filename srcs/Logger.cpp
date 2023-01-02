#include <string.h>

#include "Logger.hpp"

namespace ptp::Loggifyer
{
// public methods

    Logger& Logger::getInstance()
    {
        static Logger oSingletonLogger;

        return oSingletonLogger;
    }

    void Logger::log(LogLevel eLevel, const char* message, ...)
    {
        m_oMutex.lock();

        char buffer[1024];

        va_list args;
        va_start(args, message);
        vsnprintf(buffer, sizeof(buffer), message, args);
        va_end(args);

        writeMessage(eLevel, buffer);

        m_oMutex.unlock();
    }

    std::string Logger::getTimestampFormat() const
    {
        auto now = std::chrono::system_clock::now();

        std::time_t t = std::chrono::system_clock::to_time_t(now);

        std::tm tm = *std::localtime(&t);

        std::stringstream timestamp;

        #ifdef MILLISECONDS

            auto elapsed        = now.time_since_epoch();

            auto milliseconds   = std::chrono::duration_cast<std::chrono::milliseconds>(elapsed).count() % 1000;

            timestamp << std::put_time(&tm, "%Y-%m-%d %H:%M:%S") << "." << std::setw(3) << std::setfill('0') << milliseconds;

        #else

            timestamp << std::put_time(&tm, "%Y-%m-%d %H:%M:%S") << " ";

        #endif

        return timestamp.str();
    }

// private methods

    std::string Logger::formatMessage(const char* sMessage)
    {
        uint16_t    iFormattingSpaceLength = 37;
        std::stringstream sFormattedMessage;

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

    void Logger::writeMessage(LogLevel eLevel, const char* message)
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
            << color
                << levelString
                << " "
                << getTimestampFormat()
                << " : "
                << (m_bIsComplexFormattingEnable ? formatMessage(message) : message)
            << WHITE
        << std::endl;
    }

} // namespace ptp::Loggifyer
