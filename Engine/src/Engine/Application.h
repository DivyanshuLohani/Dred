#pragma once
#include "Core.h";
#include "Window.h";
#include "Engine/Events/ApplicationEvents.h";

namespace Engine {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	class ENGINE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
		void OnEvent(Event& e);

	private:
		std::unique_ptr<Window> m_Window;
		bool running = true;
		bool OnWindowClose(WindowCloseEvent& e);
	};

	Application* CreateApplication();
};

