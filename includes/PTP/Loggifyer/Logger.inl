#include "Logger.hpp"

namespace ptp::log
{
    inline std::string Logger::getTimestampFormat() const
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

    inline LogLevel Logger::getLogLevel()
    {
        m_oGlobalLogLevelMutex.lock();
        LogLevel eRetGlobalLogLevel = m_eGlobalLogLevel;
        m_oGlobalLogLevelMutex.unlock();

        return eRetGlobalLogLevel;
    }

    inline void Logger::setLogLevel(LogLevel eLogLevel)
    {
        m_oGlobalLogLevelMutex.lock();
        m_eGlobalLogLevel = eLogLevel;
        m_oGlobalLogLevelMutex.unlock();
    }

    inline void Logger::enableLog()
    {
        m_oEnableLogsMutex.lock();
        m_bIsLogEnable = true;
        m_oEnableLogsMutex.unlock();
    }

    inline void Logger::disableLog()
    {
        m_oEnableLogsMutex.lock();
        m_bIsLogEnable = false;
        m_oEnableLogsMutex.unlock();
    }

    inline void Logger::enableComplexFormatting()
    {
        m_oComplexFormattingMutex.lock();
        m_bIsComplexFormattingEnable = true;
        m_oComplexFormattingMutex.unlock();
    }

    inline void Logger::disableComplexFormatting()
    {
        m_oComplexFormattingMutex.lock();
        m_bIsComplexFormattingEnable = false;
        m_oComplexFormattingMutex.unlock();
    }

    inline bool Logger::isLogEnabled()
    {
        m_oEnableLogsMutex.lock();
        bool bRetIsLogEnable = m_bIsLogEnable;
        m_oEnableLogsMutex.unlock();

        return bRetIsLogEnable;
    }

} // namespace ptp::log
