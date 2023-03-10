#include "pre.h"
#include "Log.h"
#include <spdlog/sinks/stdout_color_sinks.h>

namespace Dred
{
	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	void Log::Init()
	{

		// Intialize the looger
		// Set Pattern " [00:00:00][INFO][ENGINE]  message log "
		spdlog::set_pattern("%^[%H:%M:%S] [%l]%$ %n: %v");
		s_CoreLogger = spdlog::stdout_color_mt("DRED");
		s_CoreLogger->set_level(spdlog::level::trace);

		s_ClientLogger = spdlog::stdout_color_mt("APP");
		s_ClientLogger->set_level(spdlog::level::trace);


	}
}