#pragma once

// Version
#define AE_CURRENT_VERSION 0x000001
#define AE_CURRENT_VERSION_MAJOR 0x00
#define AE_CURRENT_VERSION_MINOR 0x00
#define AE_CURRENT_VERSION_PATCH 0x01


// Platforms
#if defined(_WIN32)
	#define AE_WINDOWS
#elif defined(__APPLE__)
	#define AE_APPLE
#elif defined(ANDROID) || defined(__ANDROID__)
	#define AE_ANDROID
#elif defined(__linux__)
	#define AE_LINUX
#else
	#define AE_UNKNOWN
#endif

#ifdef AE_WINDOWS
	#define AE_DEPRECATED __declspec(deprecated)
	#define AE_UNSAFE AE_DEPRECATED
#else
	#define AE_DEPRECATED  __attribute__((deprecated))
	#define AE_UNSAFE __attribute__((deprecated))
#endif

#include <assert.h>

#define AE_ENSURE(value) assert(value);
#define AE_ENSURE_NOT(value) assert(!value);