#pragma once
#ifdef DRED_WINDOWS_BUILD
#include "Application.h"	
#include "Log.h"	

extern Dred::Application* application;

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