#pragma once

#include "pre.h"
#include "Dred/Core.h"
#include "Dred/Events/Events.h"

namespace Dred
{
	/// <summary>
	/// Window props contains the normal items such as title, width and height 
	/// this is just a utitlity struct
	/// </summary>
	struct WindowProps
	{
		std::string Title;
		unsigned int Width, Height;

		WindowProps(const std::string& title = "Dred",
			unsigned int width = 1280,
			unsigned int height = 720) : Title(title), Width(width), Height(height) {}
	};
	/// <summary>
	/// Base window class which all platform classes need to inherit to be able to be handled properly
	/// This contians general functions like width and height these functions should be implemented by 
	/// the platforms for this class to work properly 
	/// </summary>
	class DRED_API Window
	{
	public:
		using EventCallbackFn = std::function<void(Event &)>;
		virtual ~Window() {}

		virtual void OnUpdate() = 0;

		virtual unsigned int GetHeight() const = 0;
		virtual unsigned int GetWidth() const = 0;

		virtual void SetEventCallback(const EventCallbackFn &callback) = 0;
		virtual void SetVsync(bool enabled) = 0;
		virtual bool IsVsync() const = 0;
		virtual void SetClipboard(const char *text) const = 0;
		virtual const char *GetClipboard() const = 0;
		virtual void *GetNativeWindow() const = 0;

		static Window *Create(const WindowProps &props = WindowProps());

	private:
	};

}