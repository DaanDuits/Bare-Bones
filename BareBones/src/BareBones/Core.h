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