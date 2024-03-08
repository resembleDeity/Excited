#pragma once

#ifdef EXCITED_PLATFORM_WINDOWS
	#ifdef EXCITED_BUILD_DLL
		#define EXCITED_API __declspec(dllexport)
	#else
		#define EXCITED_API __declspec(dllimport)
	#endif
#else
	#error Excited only support Windows!
#endif