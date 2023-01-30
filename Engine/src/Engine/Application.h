#pragma once
#include "Core.h";
#include "Window.h";

namespace Engine {

	class ENGINE_API Application
	{
	public:
		Application();
		void Run();
		virtual ~Application();

	private:
		std::unique_ptr<Window> m_Window;
		bool running = true;
	};

	Application* CreateApplication();
};

