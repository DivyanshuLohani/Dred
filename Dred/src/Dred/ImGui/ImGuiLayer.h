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


        virtual void OnAttach() override;
        virtual void OnDetach() override;
        virtual void OnImGuiRender() override;

        void Begin();
        void End();
        
    private:
        float m_time = 0;
    };

}
