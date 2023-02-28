#include "pre.h"
#include "Dred/Application.h"
#include "Dred/Log.h"
#include <glad/glad.h>


namespace Dred {

	Application* Application::s_Instance = nullptr;

	Application::Application() 
	{
		/// <summary>
		///  Singleton pattern is used to make this 
		/// Application class because we don't need 
		/// another application class
		/// </summary>

		DD_ASSERT(s_Instance == null, "Assertion failed window already creadted");
		s_Instance = this;


		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(DD_BIND_EVENT(Application::OnEvent));

		m_imGuiLayer = new ImGuiLayer();
		PushOverlay(m_imGuiLayer);
	}
	Application::~Application() {

	}
	void Application::Run() {
		/// Main application loop here
		while (m_running) {
			glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			for (Layer* layer : m_layerStack) {
				layer->OnUpdate();
			}

			m_imGuiLayer->Begin();
			for (Layer* layer : m_layerStack) {
				layer->OnImGuiRender();
			}
			m_imGuiLayer->End();

			m_Window->OnUpdate();
			
		}
	}

	void Application::OnEvent(Event& e)
	{
		// Events dispatching for the winow
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(DD_BIND_EVENT(Application::OnWindowClose));

		for (auto it = m_layerStack.end(); it != m_layerStack.begin(); ) {
			(*--it)->OnEvent(e);
			if (e.Handled) break;
		}
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
		m_running = false;
		return true;
	}
	
}