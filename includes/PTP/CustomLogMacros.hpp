/**
 * @file CustomLogMacros.hpp
 * @author MrOrnithorynque
 * @brief
 * @version 0.1
 * @date 2023-03-08
 *
 * @copyright Copyright (c) 2023
 *
 */

#pragma once

#include "Loggifyer.hpp"

#define PTP_LOG_SERVER_INFO(message, ...) PTP_LOG_CUSTOM("SERVER", ptplog::LogLevel::Info, message, __VA_ARGS__)
#define PTP_LOG_SERVER_DEBUG(message, ...) PTP_LOG_CUSTOM("SERVER", ptplog::LogLevel::Debug, message, __VA_ARGS__)
#define PTP_LOG_SERVER_OK(message, ...) PTP_LOG_CUSTOM("SERVER", ptplog::LogLevel::Ok, message, __VA_ARGS__)
#define PTP_LOG_SERVER_WARNING(message, ...) PTP_LOG_CUSTOM("SERVER", ptplog::LogLevel::Warning, message, __VA_ARGS__)
#define PTP_LOG_SERVER_ERROR(message, ...) PTP_LOG_CUSTOM("SERVER", ptplog::LogLevel::Error, message, __VA_ARGS__)
#define PTP_LOG_SERVER_FATAL(message, ...) PTP_LOG_CUSTOM("SERVER", ptplog::LogLevel::Fatal, message, __VA_ARGS__)

#define PTP_LOG_CLIENT_INFO(message, ...) PTP_LOG_CUSTOM("CLIENT", ptplog::LogLevel::Info, message, __VA_ARGS__)
#define PTP_LOG_CLIENT_DEBUG(message, ...) PTP_LOG_CUSTOM("CLIENT", ptplog::LogLevel::Debug, message, __VA_ARGS__)
#define PTP_LOG_CLIENT_OK(message, ...) PTP_LOG_CUSTOM("CLIENT", ptplog::LogLevel::Ok, message, __VA_ARGS__)
#define PTP_LOG_CLIENT_WARNING(message, ...) PTP_LOG_CUSTOM("CLIENT", ptplog::LogLevel::Warning, message, __VA_ARGS__)
#define PTP_LOG_CLIENT_ERROR(message, ...) PTP_LOG_CUSTOM("CLIENT", ptplog::LogLevel::Error, message, __VA_ARGS__)
#define PTP_LOG_CLIENT_FATAL(message, ...) PTP_LOG_CUSTOM("CLIENT", ptplog::LogLevel::Fatal, message, __VA_ARGS__)

#define PTP_LOG_GAME_ENGINE_INFO(message, ...) PTP_LOG_CUSTOM("GAME_ENGINE", ptplog::LogLevel::Info, message, __VA_ARGS__)
#define PTP_LOG_GAME_ENGINE_DEBUG(message, ...) PTP_LOG_CUSTOM("GAME_ENGINE", ptplog::LogLevel::Debug, message, __VA_ARGS__)
#define PTP_LOG_GAME_ENGINE_OK(message, ...) PTP_LOG_CUSTOM("GAME_ENGINE", ptplog::LogLevel::Ok, message, __VA_ARGS__)
#define PTP_LOG_GAME_ENGINE_WARNING(message, ...) PTP_LOG_CUSTOM("GAME_ENGINE", ptplog::LogLevel::Warning, message, __VA_ARGS__)
#define PTP_LOG_GAME_ENGINE_ERROR(message, ...) PTP_LOG_CUSTOM("GAME_ENGINE", ptplog::LogLevel::Error, message, __VA_ARGS__)
#define PTP_LOG_GAME_ENGINE_FATAL(message, ...) PTP_LOG_CUSTOM("GAME_ENGINE", ptplog::LogLevel::Fatal, message, __VA_ARGS__)
