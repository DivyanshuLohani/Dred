#pragma once

#ifdef ENGINE_WINDOWS_BUILD
	#ifdef ENGINE_DLL_BUILD
		#define ENGINE_API __declspec(dllexport)
	#else
		#define ENGINE_API __declspec(dllimport)
	#endif // ENGINE_DLL_BUILD
#else
	#error Engine Only supported on windows
#endif // ENGINE_WINDOWS_BUILD

#ifdef ENGINE_ASSERTS
	#define EN_ASSERT(x, ...) { if (!(x)) {EN_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define EN_CORE_ASSERT(x, ...) { if (!(x)) {EN_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define EN_ASSERT(x, ...)
	#define EN_CORE_ASSERT(x, ...) 
#endif // ENGINE_ASSERTS


#define BIT(x) (1 << x)