#pragma once

#include "pre.h"
#include "Events.h"

namespace Dred {
	class DRED_API WindowResizeEvent : public Event {
	public:
		WindowResizeEvent(unsigned int width, unsigned int height) 
			: m_width(width), m_height(height) {}

		inline unsigned int GetWidth() const { return m_width; }
		inline unsigned int GetHeight() const { return m_height; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "WindowResizeEvent: " << m_width << ", " << m_height;
			return ss.str();
		}

		EVENT_CLASS_CATEGORY(EventCategoryApplication)
		EVENT_CLASS_TYPE(WindowResize)
	private:
		unsigned int m_width, m_height;
	};

	class DRED_API WindowCloseEvent : public Event {
	public:
		WindowCloseEvent() {};

		EVENT_CLASS_CATEGORY(EventCategoryApplication)
		EVENT_CLASS_TYPE(WindowClose)
	};

	class DRED_API AppTickEvent : public Event {
	public:
		AppTickEvent() {}

		EVENT_CLASS_CATEGORY(EventCategoryApplication)
		EVENT_CLASS_TYPE(AppTick)
	};
	
	class DRED_API AppUpdateEvent : public Event {
	public:
		AppUpdateEvent() {}

		EVENT_CLASS_CATEGORY(EventCategoryApplication)
		EVENT_CLASS_TYPE(AppUpdate)
	};
	
	class DRED_API AppRendererEvent : public Event {
	public:
		AppRendererEvent() {}

		EVENT_CLASS_CATEGORY(EventCategoryApplication)
		EVENT_CLASS_TYPE(AppRenderer)
	};

	class DRED_API WindowFocusEvent : public Event {
	public:
		WindowFocusEvent() {};
		
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
		EVENT_CLASS_TYPE(WindowFocus)
	};
	
	class DRED_API WindowLostFocusEvent : public Event {
	public:
		WindowLostFocusEvent() {};
		
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
		EVENT_CLASS_TYPE(WindowLostFocus)
	};
	
	class DRED_API WindowMoveEvent : public Event {
	public:
		WindowMoveEvent(int xPos, int yPos) 
			: m_windowX(xPos), m_windowY(yPos) {};
		
		inline int GetX() const { return m_windowX; }
		inline int GetY() const { return m_windowY; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "WindowMoveEvent: " << m_windowX << ", " << m_windowY;
			return ss.str();
		}

		EVENT_CLASS_CATEGORY(EventCategoryApplication)
		EVENT_CLASS_TYPE(WindowMoved)
	private:
		int m_windowX, m_windowY;
	};
}