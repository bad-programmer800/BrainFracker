#pragma once

#include "Brain/Core/Base.h"

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

namespace Brain {

	class Log
	{
	public:
		static void Init();

		static Ref<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		static Ref<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static Ref<spdlog::logger> s_CoreLogger;
		static Ref<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define BR_CORE_TRACE(...)    ::Brain::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define BR_CORE_INFO(...)     ::Brain::Log::GetCoreLogger()->info(__VA_ARGS__)
#define BR_CORE_WARN(...)     ::Brain::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define BR_CORE_ERROR(...)    ::Brain::Log::GetCoreLogger()->error(__VA_ARGS__)
#define BR_CORE_CRITICAL(...) ::Brain::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define BR_TRACE(...)         ::Brain::Log::GetClientLogger()->trace(__VA_ARGS__)
#define BR_INFO(...)          ::Brain::Log::GetClientLogger()->info(__VA_ARGS__)
#define BR_WARN(...)          ::Brain::Log::GetClientLogger()->warn(__VA_ARGS__)
#define BR_ERROR(...)         ::Brain::Log::GetClientLogger()->error(__VA_ARGS__)
#define BR_CRITICAL(...)      ::Brain::Log::GetClientLogger()->critical(__VA_ARGS__)