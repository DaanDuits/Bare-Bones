#pragma once

#include"Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace BareBones {
	class BB_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core log macros
#define BB_CORE_TRACE(...) ::BareBones::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define BB_CORE_INFO(...) ::BareBones::Log::GetCoreLogger()->info(__VA_ARGS__)
#define BB_CORE_WARN(...) ::BareBones::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define BB_CORE_ERROR(...) ::BareBones::Log::GetCoreLogger()->error(__VA_ARGS__)
#define BB_CORE_FATAL(...) ::BareBones::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define BB_TRACE(...) ::BareBones::Log::GetClientLogger()->trace(__VA_ARGS__)
#define BB_INFO(...) ::BareBones::Log::GetClientLogger()->info(__VA_ARGS__)
#define BB_WARN(...) ::BareBones::Log::GetClientLogger()->warn(__VA_ARGS__)
#define BB_ERROR(...) ::BareBones::Log::GetClientLogger()->error(__VA_ARGS__)
#define BB_FATAL(...) ::BareBones::Log::GetClientLogger()->critical(__VA_ARGS__)

