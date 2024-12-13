// (C) Copyright Kirito 2024

#include "excitedpch.h"
#include "Log.h"

#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>

namespace Excited
{
	std::shared_ptr<spdlog::logger> FLog::CoreLogger;
	std::shared_ptr<spdlog::logger> FLog::ClientLogger;

	void FLog::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");

		CoreLogger = spdlog::stdout_color_mt("EXCITED");
		CoreLogger->set_level(spdlog::level::trace);

		ClientLogger = spdlog::stdout_color_mt("APP");
		ClientLogger->set_level(spdlog::level::trace);
	}
}