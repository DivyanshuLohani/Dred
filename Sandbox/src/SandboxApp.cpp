#include "Dred.h"


class Sandbox : public Dred::Application
{
public:
    Sandbox() {
        PushOverlay(new Dred::ImGuiLayer());
    }
    ~Sandbox() {

    }


};


Dred::Application* Dred::CreateApplication() {
    return new Sandbox();
}