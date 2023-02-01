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
			m_Window->OnUpdate();
		}
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

		EN_CORE_INFO(e.ToString());
	}
	
	bool Application::OnWindowClose(WindowCloseEvent& e) 
	{
		running = false;
		return true;
	}
	
}