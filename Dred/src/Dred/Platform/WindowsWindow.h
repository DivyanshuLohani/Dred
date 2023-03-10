#pragma once
#include "pre.h"
#include "Dred/Window.h"

#include <GLFW/glfw3.h>

namespace Dred{

	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		inline unsigned int GetHeight() const override { return m_Data.height; }
		inline unsigned int GetWidth() const override { return m_Data.width; }

		inline void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }
		void SetVsync(bool enable) override;
		bool IsVsync() const override;
		void SetClipboard(const char* text) const override;
		const char* GetClipboard() const override;
		void* GetNativeWindow() const override;

	private:
		virtual void Init(const WindowProps& props);
		virtual void ShutDown();

		GLFWwindow* m_Window;

		struct WindowData {
			std::string Title;
			unsigned int width, height;
			bool vSync;

			EventCallbackFn EventCallback;
		};

		WindowData m_Data;

	};
}

