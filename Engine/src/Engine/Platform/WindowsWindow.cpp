#include "pre.h"
#include "Engine/Log.h"
#include "Engine/Platform/WindowsWindow.h"
#include "Engine/Events/ApplicationEvents.h"
#include "Engine/Events/KeyEvent.h"
#include "Engine/Events/MouseEvent.h"
#include "Engine/Input.h"

#include <glad/glad.h>

namespace Engine{
	
	static bool s_GLFWintialized = false;

	static void GLFWErrorCallback(int error, const char* description) 
	{
		EN_CORE_ERROR("GLFW Error: ({0}): {1}", error, description);
	}

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
			glfwSetErrorCallback(GLFWErrorCallback);
			s_GLFWintialized = true;
		}

		m_Window = glfwCreateWindow(m_Data.width, m_Data.height, m_Data.Title.c_str(), NULL, NULL);
		glfwMakeContextCurrent(m_Window);

		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		EN_ASSERT(status, "GLAD Failed to initialize")

		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVsync(true);

		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			data.width = width;
			data.height = height;

			WindowResizeEvent event(width, height);
			data.EventCallback(event);
		});

		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window) 
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			

			WindowCloseEvent event;
			data.EventCallback(event);

		});

		// ----------------- Keybaord Callbacks ------------------------ // 
		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {

			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			switch (action) {
				case GLFW_PRESS:
				{
					KeyPressedEvent event(key, 0);
					data.EventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					KeyReleaseEvent event(key);
					data.EventCallback(event);
					break;
				}
				case GLFW_REPEAT:
				{
					KeyPressedEvent event(key, 1);
					data.EventCallback(event);
					break;
				}
			}
		});

		glfwSetCharCallback(m_Window, [](GLFWwindow* window, unsigned int character) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			KeyTypedEvent event(character);
			data.EventCallback(event);
		});
		// ----------- Keyboard Callbacks End ----------------- // 

		// ---------------- Mouse Callbacks ------------------ //
		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			
			switch (action) {
				case GLFW_PRESS:
				{
					MouseButtonPressedEvent event(button);
					data.EventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					MouseButtonReleasedEvent event(button);
					data.EventCallback(event);
					break;
				}
			}
		});

		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xoffset, double yoffset) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			MouseScrolledEvent event((float)xoffset, (float)yoffset);
			data.EventCallback(event);
		});

		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xpos, double ypos) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			MouseMovedEvent event((float)xpos, (float)ypos);
			data.EventCallback(event);
		});
		// ---------------- Mouse Callbacks End ------------------ //

		// ---------------- Window Callbacks ----------------- // 
		glfwSetWindowFocusCallback(m_Window, [](GLFWwindow* window, int focused) 
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			if (focused == GLFW_TRUE) {
				WindowFocusEvent event;
				data.EventCallback(event);
			}
			else {
				WindowLostFocusEvent event;
				data.EventCallback(event);
			}
		});
		
		glfwSetWindowPosCallback(m_Window, [](GLFWwindow* window, int xpos, int ypos) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);	
			WindowMoveEvent event(xpos, ypos);
			data.EventCallback(event);
		});

		// ------------- Window Callbacks End -------------- //

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

	void WindowsWindow::SetClipboard(const char* text) const
	{
		glfwSetClipboardString(m_Window, text);
	}

	const char* WindowsWindow::GetClipboard() const
	{
		return glfwGetClipboardString(m_Window);
	}

	void* WindowsWindow::GetNativeWindow() const
	{
		return m_Window;
	}

	void WindowsWindow::ShutDown()
	{
		glfwDestroyWindow(m_Window);
	}


}