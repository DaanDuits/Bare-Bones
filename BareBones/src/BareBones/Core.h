#pragma once

#ifdef BB_PLATFORM_WINDOWS
	#ifdef BB_BUILD_DLL
		#define BB_API __declspec(dllexport)
	#else
		#define BB_API __declspec(dllimport)
	#endif
#else
	#error Bare Bones only supports Windows!
#endif

#ifdef BB_ENABLE_ASSERTS
	#define BB_ASSERT(x, ...) { if(!(x)) { BB_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define BB_CORE_ASSERT(x, ...) { if(!(x)) { BB_CORE_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define BB_ASSERT(x, ...)
	#define BB_CORE_ASSERT(x, ...)
#endif 


#define BIT(x) (1 << x)