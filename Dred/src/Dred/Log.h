#pragma once

#include "pre.h"
#include "Core.h"
#include <spdlog/spdlog.h>

namespace Dred {

	class DRED_API Log
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; };
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; };


	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};
}

#define DD_CORE_TRACE(...)   Dred::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define DD_CORE_INFO(...)    Dred::Log::GetCoreLogger()->info(__VA_ARGS__)
#define DD_CORE_WARN(...)    Dred::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define DD_CORE_ERROR(...)   Dred::Log::GetCoreLogger()->error(__VA_ARGS__)
//#define EN_CORE_FATAL(...)   Dred::Log::GetCoreLogger()->fatal(__VA_ARGS__)

#define DD_ERROR(...)        Dred::Log::GetClientLogger()->error(__VA_ARGS__)
#define DD_WARN(...)         Dred::Log::GetClientLogger()->warn(__VA_ARGS__)
#define DD_INFO(...)         Dred::Log::GetClientLogger()->info(__VA_ARGS__)
#define DD_TRACE(...)        Dred::Log::GetClientLogger()->trace(__VA_ARGS__)
//#define EN_FATAL(...)        Dred::Log::GetClientLogger()->fatal(__VA_ARGS__)