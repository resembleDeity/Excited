// (C) Copyright Kirito 2024

#pragma once

#ifdef EXCITED_PLATFORM_WINDOWS
	#ifdef EXCITED_BUILD_DLL
		#define EXCITED_API _declspec(dllexport)
	#else
		#define EXCITED_API _declspec(dllimport)
	#endif
#else
	#error Excited only supports Windows! 
#endif