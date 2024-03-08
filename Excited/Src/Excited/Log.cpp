#include "Log.h"

#include "spdlog/sinks/stdout_color_sinks.h"



namespace Excited
{
	std::shared_ptr<spdlog::logger> KLog::CoreLogger;
	std::shared_ptr<spdlog::logger> KLog::ClientLogger;
	
	void KLog::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");
		CoreLogger = spdlog::stdout_color_mt("EXCITED");
		CoreLogger->set_level(spdlog::level::trace);

		ClientLogger = spdlog::stdout_color_mt("APPLICATION");
		ClientLogger->set_level(spdlog::level::trace);
	}
}