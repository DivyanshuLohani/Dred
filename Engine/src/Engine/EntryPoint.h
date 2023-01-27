#pragma once
#ifdef ENGINE_WINDOWS_BUILD
#include "Application.h"	

extern Engine::Application* application;

void main(int argc, char** argv) {
	auto app = Engine::CreateApplication();
	app->Run();
	delete app;
}
#else
	#error Engine Only supported on windows
#endif	