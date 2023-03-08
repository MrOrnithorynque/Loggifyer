#include "Logger.hpp"

namespace ptp::log
{

    inline LogLevel Logger::getLogLevel()
    {
        LogLevel eRetGlobalLogLevel = m_eGlobalLogLevel;

        return eRetGlobalLogLevel;
    }

    inline void Logger::setLogLevel(LogLevel eLogLevel)
    {
        m_oGlobalLogLevelMutex.lock();
        m_eGlobalLogLevel = eLogLevel;
        m_oGlobalLogLevelMutex.unlock();
    }

    inline void Logger::setWorkspaceDir(const std::string &sWorkspaceDir)
    {
        m_sWorkspaceDir = sWorkspaceDir;
    }

    inline void Logger::enableLog()
    {
        m_bIsLogEnable = true;
    }

    inline void Logger::disableLog()
    {
        m_bIsLogEnable = false;
    }

    inline void Logger::enableComplexFormatting()
    {
        m_bIsComplexFormattingEnable = true;
    }

    inline void Logger::disableComplexFormatting()
    {
        m_bIsComplexFormattingEnable = false;
    }

    inline void Logger::displayFilepath(bool bDisplayFilepath)
    {
        m_bDisplayFilepath = bDisplayFilepath;
    }

    inline bool Logger::isLogEnabled()
    {
        return m_bIsLogEnable;
    }

} // namespace ptp::log
