// (C) Copyright Kirito 2024

#pragma once

#include <memory>

#ifdef _WIN32
	#ifdef _WIN64
		#define EXCITED_PLATFORM_WINDOWS
	#else
		#error "x86 Builds are not supported!"
	#endif
#elif defined(__ANDROID__)
	#define EXCITED_PLATFORM_ANDROID
	#error "Android is not supported!"
#elif defined(__Linux__)
	#define EXCITED_PLATFORM_LINUX
	#error "Linux is not supported!"
#elif defined(__APPLE__) || defined(__MACH__)
	#include <TargetConditionals.h>				// Apple 有很多种形式，我们需要确定对应的平台，并进行对应的定义
	#if TARGET_IPHONE_SIMULATOR == 1
		#error "IOS Simulator is not supported!"
	#elif TARGET_OS_IPHONE == 1
		#define EXCITED_PLATFORM_IOS
		#error "IOS is not supported!"
	#elif TARGET_OS_MAC
		#define EXCITED_PLATFORM_MACOS
		#error "MacOS is not supported!"
	#else
		#error "Unknown Apple platform!"
	#endif
#else
	#error "Unknown platform!"
#endif

// #ifdef EXCITED_PLATFORM_WINDOWS
//     #ifdef EXCITED_BUILD_DLL
//         #define EXCITED_API _declspec(dllexport)
//     #else
//         #define EXCITED_API _declspec(dllimport)
//     #endif
// #else
//     #error Excited only supports Windows! 
// #endif

#ifdef EXCITED_DEBUG
	#define EXCITED_ENABLE_ASSERTS

	#ifdef EXCITED_PLATFORM_WINDOWS
		#define EXCITED_DEBUGBREAK() __debugbreak()
	#elif EXCITED_PLATFORM_LINUX
		#include <signal.h>
		#define EXCITED_DEBUGBREAK() raise(SIGTRAP)
	#else
		#error	"Platform doesn't support debugbreak yet! "
	#endif
#else
	#define EXCITED_DEBUGBREAK()
#endif

#ifdef EXCITED_ENABLE_ASSERTS
	#define EXCITED_ASSERT(x, ...) \
		{ \
			if (!(x)) \
			{ \
				EXCITED_ERROR("[Assert] Assertion Failed: {0}", __VA_ARGS__); \
				EXCITED_DEBUGBREAK(); \
			} \
		}
	#define EXCITED_CORE_ASSERT(x, ...) \
		{ \
			if (!(x)) \
			{ \
				EXCITED_CORE_ERROR("[Assert] Assertion Failed: {0}", __VA_ARGS__); \
				EXCITED_DEBUGBREAK(); \
			} \
		}
#else
	#define EXCITED_ASSERT(x, ...)
	#define EXCITED_CORE_ASSERT(x, ...)
#endif

#define Bit(x) (1 << x)

#define BIND_EVENT_FN(x) (std::bind(&x, this, std::placeholders::_1))

namespace Excited
{
	template <typename T>
	using TRef = std::shared_ptr<T>;
	template <typename T, typename... Args>
	constexpr TRef<T> CreateRef(Args&&... InArgs)
	{
		return std::make_shared<T>(std::forward<Args>(InArgs)...);
	}

	template <typename T>
	using TScope = std::unique_ptr<T>;
	template <typename T, typename... Args>
	constexpr TScope<T> CreateScope(Args&&... InArgs)
	{
		return std::make_unique<T>(std::forward<Args>(InArgs)...);
	}
}