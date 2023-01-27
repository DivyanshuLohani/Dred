#pragma once
#ifdef ENGINE_WINDOWS_BUILD
#include "Application.h"	
#include "Log.h"	

extern Engine::Application* application;

void main(int argc, char** argv) {
	Engine::Log::Init();
	EN_CORE_WARN("Initialize Core Logger");
	EN_INFO("Initialize Client Logger");
	auto app = Engine::CreateApplication();
	app->Run();
	delete app;
}
#else
	#error Engine Only supported on windows
#endif	