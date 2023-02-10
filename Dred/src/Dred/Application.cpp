#include "pre.h"
#include "Dred/Application.h"
#include "Dred/Log.h"
#include <glad/glad.h>


namespace Dred {

	Application* Application::s_Instance = nullptr;

	Application::Application() 
	{
		s_Instance = this;

		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(DD_BIND_EVENT(Application::OnEvent));

	}
	Application::~Application() {

	}
	void Application::Run() {
		while (running) {
			glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			for (Layer* layer : m_layerStack) {
				layer->OnUpdate();
			}

			m_Window->OnUpdate();
			
		}
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(DD_BIND_EVENT(Application::OnWindowClose));

		for (auto it = m_layerStack.end(); it != m_layerStack.begin(); ) {
			(*--it)->OnEvent(e);
			if (e.Handled) break;
		}

		//EN_CORE_TRACE(e.ToString());
	}

	void Application::PushLayer(Layer* layer)
	{
		m_layerStack.PushLayer(layer);
	}
	
	void Application::PushOverlay(Layer* layer)
	{
		m_layerStack.PushOverlay(layer);
	}

	bool Application::OnWindowClose(WindowCloseEvent& e) 
	{
		running = false;
		return true;
	}
	
}