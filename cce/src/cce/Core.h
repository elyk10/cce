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

#ifdef CCE_ENABLE_ASSERTS
	#define CCE_ASSERT(x, ...) { if(!(x)) {CCE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define CCE_CORE_ASSERT(x, ...) { if(!(x)) {CCE_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define CCE_ASSERT(x, ...)
	#define CCE_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)