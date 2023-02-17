#pragma once
#include "Core.h";
#include "Window.h";
#include "Dred/Events/ApplicationEvents.h";
#include "Dred/Layers/LayerStack.h";
#include "Dred/ImGui/ImGuiLayer.h";

namespace Dred {



	class DRED_API Application
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
		static Application* s_Instance;
	
		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_imGuiLayer;
		bool running = true;
		LayerStack m_layerStack;


	private:
		bool OnWindowClose(WindowCloseEvent& e);

	
	};

	Application* CreateApplication();
};

