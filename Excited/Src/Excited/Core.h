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

#ifdef EXCITED_ENABLE_ASSERTS
	#define EXCITED_ASSERT(x, ...) { if (!(x)) { EXCITED_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define EXCITED_CORE_ASSERT(x, ...) { if (!(x)) { EXCITED_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define EXCITED_ASSERT(x, ...)
	#define EXCITED_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)