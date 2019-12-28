#pragma once

#ifdef TMD_PLATFORM_WINDOWS
	#ifdef TMD_BUILD_DLL
		#define TIMID_API __declspec(dllexport)
	#else
		#define TIMID_API __declspec(dllimport)
	#endif
#else
	#error Timid currently only supports Windows!
#endif