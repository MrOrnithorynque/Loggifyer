#include "Logger.hpp"

namespace ptp::log
{

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
