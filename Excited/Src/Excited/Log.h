#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"



namespace Excited
{
	class EXCITED_API KLog
	{
	public:

		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return ClientLogger; }

	private:

		static std::shared_ptr<spdlog::logger> CoreLogger;
		static std::shared_ptr<spdlog::logger> ClientLogger;

	};
}



// Core Log macros
#define EXCITED_CORE_TRACE(...)		::Excited::KLog::GetCoreLogger()->trace(__VA_ARGS__)
#define EXCITED_CORE_INFO(...)		::Excited::KLog::GetCoreLogger()->info(__VA_ARGS__)
#define EXCITED_CORE_WARN(...)		::Excited::KLog::GetCoreLogger()->warn(__VA_ARGS__)
#define EXCITED_CORE_ERROE(...)		::Excited::KLog::GetCoreLogger()->error(__VA_ARGS__)
#define EXCITED_CORE_FATAL(...)		::Excited::KLog::GetCoreLogger()->critical(__VA_ARGS__)

// Client Log macros
#define EXCITED_TRACE(...)			::Excited::KLog::GetClientLogger()->trace(__VA_ARGS__)
#define EXCITED_INFO(...)			::Excited::KLog::GetClientLogger()->info(__VA_ARGS__)
#define EXCITED_WARN(...)			::Excited::KLog::GetClientLogger()->warn(__VA_ARGS__)
#define EXCITED_ERROE(...)			::Excited::KLog::GetClientLogger()->error(__VA_ARGS__)
#define EXCITED_FATAL(...)			::Excited::KLog::GetClientLogger()->critical(__VA_ARGS__)
 