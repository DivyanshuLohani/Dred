#pragma once

#include "Core.h"

namespace Engine {
	class ENGINE_API Input {
	public:
		inline static bool IsKeyPressed(int keyCode) { return s_instance->IsKeyPressedImpl(keyCode); }
		inline static bool IsMouseButtonPressed(int mouseButton) { return s_instance->IsMouseButtonPressedImpl(mouseButton); }

		inline static float GetMouseX() { return s_instance->GetMouseXImpl(); }
		inline static float GetMouseY() { return s_instance->GetMouseYImpl(); }
		inline static std::pair<float, float> GetMousePosition() { return s_instance->GetMousePositionImpl(); }

	protected:
		virtual bool IsKeyPressedImpl(int keycode) = 0;
		virtual bool IsMouseButtonPressedImpl(int keycode) = 0;
		virtual float GetMouseXImpl() = 0;
		virtual float GetMouseYImpl() = 0;
		virtual std::pair<float, float> GetMousePositionImpl() = 0;

	private:
		static Input* s_instance;
	};
}