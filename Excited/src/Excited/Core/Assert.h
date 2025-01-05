// (C) Copyright Kirito 2025

#pragma once

#include "Core.h"
#include "Log.h"

#ifdef EXCITED_PLATFORM_WINDOWS
	#define EXCITED_DEBUG_BREAK() __debugbreak()
#elif defined(EXCITED_COMPILER_CLANG)
	#define EXCITED_DEBUG_BREAK __builtin_debugtrap()
#else
	#define EXCITED_DEBUG_BREAK
#endif

#ifdef EXCITED_DEBUG
	#define EXCITED_ENABLE_ASSERTS
#endif

#ifdef EXCITED_ENABLE_ASSERTS
	#define EXCITED_ASSERT(x, ...) \
		{ \
			if (!(x)) \
			{ \
				EXCITED_ERROR("[Assert] Assertion Failed: {0}", __VA_ARGS__); \
				EXCITED_DEBUG_BREAK(); \
			} \
		}
	#define EXCITED_CORE_ASSERT(x, ...) \
		{ \
			if (!(x)) \
			{ \
				EXCITED_CORE_ERROR("[Assert] Assertion Failed: {0}", __VA_ARGS__); \
				EXCITED_DEBUG_BREAK(); \
			} \
		}
#else
	#define EXCITED_ASSERT(x, ...)
	#define EXCITED_CORE_ASSERT(x, ...)
#endif