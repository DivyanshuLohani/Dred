#include "pre.h"
#include "Application.h"

namespace Engine {
	Application::Application() 
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}
	Application::~Application() {

	}
	void Application::Run() {
		while (running) {
			m_Window->OnUpdate();
		}
	}
}