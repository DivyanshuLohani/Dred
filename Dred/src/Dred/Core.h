#pragma once

#ifdef DRED_WINDOWS_BUILD
	#ifdef DRED_DLL_BUILD
		#define DRED_API __declspec(dllexport)
	#else
		#define DRED_API __declspec(dllimport)
	#endif // ENGINE_DLL_BUILD
#else
	#error Dred is only supported on windows
#endif // ENGINE_WINDOWS_BUILD

#ifdef DRED_ASSERTS
	#define DD_ASSERT(x, ...) { if (!(x)) {DD_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define DD_CORE_ASSERT(x, ...) { if (!(x)) {DD_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define DD_ASSERT(x, ...)
	#define DD_CORE_ASSERT(x, ...) 
#endif // ENGINE_ASSERTS


#define BIT(x) (1 << x)
#define DD_BIND_EVENT(fn) std::bind(&fn, this, std::placeholders::_1)