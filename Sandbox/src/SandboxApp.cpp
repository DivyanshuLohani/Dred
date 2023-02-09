#include "Engine.h"


class Sandbox : public Engine::Application
{
public:
    Sandbox() {
        PushOverlay(new Engine::ImGuiLayer());
    }
    ~Sandbox() {

    }


};


Engine::Application* Engine::CreateApplication() {
    return new Sandbox();
}