// (C) Copyright Kirito 2024

#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Excited
{
	class FLog
	{
	public:

		static void Init();

		static inline std::shared_ptr<spdlog::logger>& GetCoreLogger() { return CoreLogger; }
		static inline std::shared_ptr<spdlog::logger>& GetClientLogger() { return ClientLogger; }

	private:

		static std::shared_ptr<spdlog::logger> CoreLogger;
		static std::shared_ptr<spdlog::logger> ClientLogger;
	};
}

// Core Log Macros
#define EXCITED_CORE_TRACE(...)		::Excited::FLog::GetCoreLogger()->trace(__VA_ARGS__)
#define EXCITED_CORE_INFO(...)		::Excited::FLog::GetCoreLogger()->info(__VA_ARGS__)
#define EXCITED_CORE_WARN(...)		::Excited::FLog::GetCoreLogger()->warn(__VA_ARGS__)
#define EXCITED_CORE_ERROR(...)		::Excited::FLog::GetCoreLogger()->error(__VA_ARGS__)
#define EXCITED_CORE_CRITICAL(...)	::Excited::FLog::GetCoreLogger()->critical(__VA_ARGS__)

// Client Log Macros
#define EXCITED_TRACE(...)			::Excited::FLog::GetClientLogger()->trace(__VA_ARGS__)
#define EXCITED_INFO(...)			::Excited::FLog::GetClientLogger()->info(__VA_ARGS__)
#define EXCITED_WARN(...)			::Excited::FLog::GetClientLogger()->warn(__VA_ARGS__)
#define EXCITED_ERROR(...)			::Excited::FLog::GetClientLogger()->error(__VA_ARGS__)
#define EXCITED_CRITICAL(...)		::Excited::FLog::GetClientLogger()->critical(__VA_ARGS__)