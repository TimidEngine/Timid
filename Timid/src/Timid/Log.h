#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Timid {
	class TIMID_API Log
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

//Core Log Macros
#define TMD_CORE_TRACE(...)   ::Timid::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define TMD_CORE_INFO(...)    ::Timid::Log::GetCoreLogger()->info(__VA_ARGS__)
#define TMD_CORE_WARN(...)    ::Timid::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define TMD_CORE_ERROR(...)   ::Timid::Log::GetCoreLogger()->error(__VA_ARGS__)
#define TMD_CORE_FATAL(...)   ::Timid::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client Log Macros
#define TMD_TRACE(...)        ::Timid::Log::GetClientLogger()->trace(__VA_ARGS__)
#define TMD_INFO(...)         ::Timid::Log::GetClientLogger()->info(__VA_ARGS__)
#define TMD_WARN(...)         ::Timid::Log::GetClientLogger()->warn(__VA_ARGS__)
#define TMD_ERROR(...)        ::Timid::Log::GetClientLogger()->error(__VA_ARGS__)
#define TMD_FATAL(...)        ::Timid::Log::GetClientLogger()->fatal(__VA_ARGS__)
