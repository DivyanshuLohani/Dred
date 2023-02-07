#pragma once
#include "Core.h";
#include "Window.h";
#include "Engine/Events/ApplicationEvents.h";
#include "Engine/Layers/LayerStack.h";

namespace Engine {



	class ENGINE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
		void OnEvent(Event& e);
		
		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline static Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; };
	private:
		std::unique_ptr<Window> m_Window;
		bool running = true;
		bool OnWindowClose(WindowCloseEvent& e);
		LayerStack m_layerStack;

	private:
		static Application* s_Instance;
	};

	Application* CreateApplication();
};

