#include "pre.h"
#include "Engine/Log.h"
#include "WindowsWindow.h"

namespace Engine{
	
	static bool s_GLFWintialized = false;

	Window* Window::Create(const WindowProps& props) {
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProps& props)
	{
		Init(props);
	}

	void WindowsWindow::Init(const WindowProps& props) {
		m_Data.Title = props.Title;
		m_Data.width = props.Width;
		m_Data.height = props.Height;

		EN_CORE_INFO("Creating Window {0} of ({1}, {2})", props.Title, props.Width, props.Height);

		if (!s_GLFWintialized) {
			int success;
			success = glfwInit();
			EN_CORE_ASSERT(success, "Window not Initalized"); 

			s_GLFWintialized = true;
		}

		m_Window = glfwCreateWindow(m_Data.width, m_Data.height, m_Data.Title.c_str(), NULL, NULL);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVsync(true);
	}

	WindowsWindow::~WindowsWindow() {
		ShutDown();
	}

	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	void WindowsWindow::SetVsync(bool enable)
	{
		if (enable)
		{
			glfwSwapInterval(1);
		}
		else
		{
			glfwSwapInterval(0);
		}

		m_Data.vSync = enable;
	}

	bool WindowsWindow::IsVsync() const
	{
		return m_Data.vSync;
	}

	void WindowsWindow::ShutDown()
	{
		glfwDestroyWindow(m_Window);
	}


}