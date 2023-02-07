#pragma once
#include "Engine/Layers/Layer.h"
#include "Engine/Events/Events.h"
#include "Engine/Events/KeyEvent.h"
#include "Engine/Events/MouseEvent.h"
#include "Engine/Events/ApplicationEvents.h"

namespace Engine {
    class ENGINE_API ImGuiLayer :
        public Layer
    {
    public:
        ImGuiLayer();
        ~ImGuiLayer();


        void OnAttach();
        void OnDetach();
        void OnUpdate();
        void OnEvent(Event& event);
    private:
        // Mouse
        bool OnMouseButtonPressed(MouseButtonPressedEvent& event);
        bool OnMouseButtonReleased(MouseButtonReleasedEvent& event);
        bool OnMouseScrolled(MouseScrolledEvent& event);
        bool OnMouseMoved(MouseMovedEvent& event);
        // Keyboard
        bool OnKeyPressed(KeyPressedEvent& event);
        bool OnKeyReleased(KeyReleaseEvent& event);
        bool OnKeyTyped(KeyTypedEvent& event);
        // Window
        bool OnWindowResize(WindowResizeEvent& event);

    private:
        float m_time = 0;
    };

}
