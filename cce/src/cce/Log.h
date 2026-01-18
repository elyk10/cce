#pragma once


#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Cce
{
	class CCE_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& getCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& getClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};
}

// core log macros
#define CCE_CORE_ERROR(...) ::Cce::Log::getCoreLogger()->error(__VA_ARGS__)
#define CCE_CORE_WARN(...) ::Cce::Log::getCoreLogger()->warn(__VA_ARGS__)
#define CCE_CORE_INFO(...) ::Cce::Log::getCoreLogger()->info(__VA_ARGS__)
#define CCE_CORE_TRACE(...) ::Cce::Log::getCoreLogger()->trace(__VA_ARGS__)
#define CCE_CORE_FATAL(...) ::Cce::Log::getCoreLogger()->fatal(__VA_ARGS__)

// client log macros
#define CCE_ERROR(...) ::Cce::Log::getClientLogger()->error(__VA_ARGS__)
#define CCE_WARN(...) ::Cce::Log::getClientLogger()->warn(__VA_ARGS__)
#define CCE_INFO(...) ::Cce::Log::getClientLogger()->info(__VA_ARGS__)
#define CCE_TRACE(...) ::Cce::Log::getClientLogger()->trace(__VA_ARGS__)
#define CCE_FATAL(...) ::Cce::Log::getClientLogger()->fatal(__VA_ARGS__)


