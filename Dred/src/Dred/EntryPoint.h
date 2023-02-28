#pragma once
#ifdef DRED_WINDOWS_BUILD
#include "Application.h"	
#include "Log.h"	

extern Dred::Application* application;
/// <summary>
/// Should not write the main function in the application this handles it all
/// </summary>
/// <param name="argc"></param>
/// <param name="argv"></param>
void main(int argc, char** argv) {
	Dred::Log::Init();
	DD_CORE_WARN("Initialize Core Logger");
	DD_INFO("Initialize Client Logger");
	auto app = Dred::CreateApplication();
	app->Run();
	delete app;
}
#else
	#error Engine Only supported on windows
#endif	