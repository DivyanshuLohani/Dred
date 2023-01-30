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

#define BIT(x) (1 << x)