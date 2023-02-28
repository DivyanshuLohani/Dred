#include "Dred.h"
#include "imgui/imgui.h"


class ExampleLayer : public Dred::Layer {
public:
    ExampleLayer() : Dred::Layer("Example Layer") {

    }
    void OnUpdate() override {
        if (Dred::Input::IsKeyPressed(DRED_KEY_SPACE)) {
            DD_INFO("Space Pressed");
        }
    }

    void OnImGuiRender() override
    {
        ImGui::Begin("Hello Window!");
        ImGui::Text("This is a normal text and I am a pro");
        ImGui::End();
    }
};

class Sandbox : public Dred::Application
{
public:
    Sandbox() {
        PushLayer(new ExampleLayer());
    }
    ~Sandbox() {

    }

};


Dred::Application* Dred::CreateApplication() {
    return new Sandbox();
}