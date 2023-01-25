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
        va_start(args, sMessage);

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
        std::string color;
    
        std::string levelString;
        std::ostringstream out;

        switch (eLevel)
            {
                case LogLevel::Message: levelString = "[Message]"; break;
                case LogLevel::Warning: levelString = "[Warning]"; break;
                case LogLevel::Error:   levelString = "[Error]"; break;
                case LogLevel::Ok:      levelString = "[Ok]"; break;
                case LogLevel::Info:    levelString = "[Info]"; break;
                default:                levelString = "[Message]"; break;
            }
        
        #if defined __linux__ || defined __APPLE__

            // set the color
            switch (eLevel)
            {
                case LogLevel::Message: color = WHITE; 
                case LogLevel::Warning: color = YELLOW;
                case LogLevel::Error:   color = RED;   
                case LogLevel::Ok:      color = GREEN; 
                case LogLevel::Info:    color = WHITE; 
                default:                color = WHITE; 
            }

            std::cout << file << "(" << line << ") "
                << color
                    << levelString
                << WHITE
                << " "
                << getTimestampFormat()
                << " : "
                << (m_bIsComplexFormattingEnable ? formatMessage(message) : message)
            << std::endl;

        #elif defined _WIN32

            std::cout << file << "(" << line << ") ";
        
            // set the color
            switch (eLevel)
            {
                case LogLevel::Message: WHITE; break;
                case LogLevel::Warning: YELLOW; break;
                case LogLevel::Error:   RED; break;
                case LogLevel::Ok:      GREEN; break;
                case LogLevel::Info:    WHITE; break;
                default:                WHITE; break;
            }
        
            std::cout << levelString;

            WHITE; // set the color back to white

            std::cout << " "
                << getTimestampFormat()
                << " : "
                << (m_bIsComplexFormattingEnable ? formatMessage(message) : message)
            << std::endl;

        #endif
    }

} // namespace ptp::log
