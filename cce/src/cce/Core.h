#pragma once

#ifdef CCE_PLATFORM_WINDOWS
	#ifdef CCE_BUILD_DLL
		#define CCE_API __declspec(dllexport)
	#else
		#define CCE_API __declspec(dllimport)
	#endif
#else
	#error Only supports Windows
#endif