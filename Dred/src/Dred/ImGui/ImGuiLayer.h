#pragma once
#include "Dred/Layers/Layer.h"
#include "Dred/Events/Events.h"
#include "Dred/Events/KeyEvent.h"
#include "Dred/Events/MouseEvent.h"
#include "Dred/Events/ApplicationEvents.h"

namespace Dred {
    class DRED_API ImGuiLayer :
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
