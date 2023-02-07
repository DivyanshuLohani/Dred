#pragma once

#include "pre.h"
#include "Events.h"

namespace Engine {
	class ENGINE_API KeyEvent : public Event {
	public:
		inline int GetKeyCode() const { return m_KeyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput);
	protected:
		KeyEvent(int KeyCode) 
			: m_KeyCode(KeyCode) {}
		int m_KeyCode;
	};


	class ENGINE_API KeyPressedEvent : public KeyEvent {
	public:
		KeyPressedEvent(int keyCode, int repeatCount) 
			: KeyEvent(keyCode), m_repeatCount(repeatCount)
		{

		}

		inline int GetRepeatCount() const { return m_repeatCount; }

		std::string ToString() const override{
			std::stringstream ss;
			ss << "Keypressed Event: " << m_KeyCode << "(Repeats: " << m_repeatCount << ")";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed);

	private:
		int m_repeatCount;
	};
	
	class ENGINE_API KeyReleaseEvent : public KeyEvent {
	public:
		KeyReleaseEvent(int keyCode)
			: KeyEvent(keyCode)
		{

		}

		
		std::string ToString() const override{
			std::stringstream ss;
			ss << "KeyReleaseEvent: " << m_KeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased);

	};
	
	class ENGINE_API KeyTypedEvent : public KeyEvent {
	public:
		KeyTypedEvent(int keyCode)
			: KeyEvent(keyCode)
		{

		}

		
		std::string ToString() const override{
			std::stringstream ss;
			ss << "KeyTypedEvent: " << m_KeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyTyped);
	};
}