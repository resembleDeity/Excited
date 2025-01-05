// (C) Copyright Kirito 2024

#pragma once

#include <functional>
#include <memory>

#if !defined(EXCITED_PLATFORM_WINDOWS) && !defined(EXCITED_PLATFORM_LINUX)
	#error Unknown platform.
#endif

#if defined(__GNUC__)
	#if defined(__clang__)
		#define EXCITED_COMPILER_CLANG
	#else
		#define EXCITED_COMPILER_GCC
	#endif
#elif defined(_MSC_VER)
	#define EXCITED_COMPILER_MSVC
#endif

#ifdef EXCITED_COMPILER_MSVC
	#define EXCITED_FORCE_INLINE __forceinline
	#define EXCITED_EXPLICIT_STATIC static
#elif defined(__GNUC__)
	#define EXCITED_FORCE_INLINE __attribute__((always_inline)) inline
	#define EXCITED_EXPLICIT_STATIC
#else
	#define EXCITED_FORCE_INLINE inline
	#define EXCITED_EXPLICIT_STATIC
#endif

#define BIT(x) (1u << x)
#define EXCITED_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)

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