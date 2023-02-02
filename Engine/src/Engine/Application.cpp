#include "pre.h"
#include "Engine/Application.h"
#include "Engine/Log.h"


namespace Engine {



	Application::Application() 
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
	}
	Application::~Application() {

	}
	void Application::Run() {
		while (running) {

			for (Layer* layer : m_layerStack) {
				layer->OnUpdate();
			}

			m_Window->OnUpdate();
		}
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

		for (auto it = m_layerStack.end(); it != m_layerStack.begin(); ) {
			(*--it)->OnEvent(e);
			if (e.Handled) break;
		}

		EN_CORE_TRACE(e.ToString());
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