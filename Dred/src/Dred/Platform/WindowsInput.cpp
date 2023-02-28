#include "pre.h"
#include <GLFW/glfw3.h>

#include "Dred/Application.h"
#include "WindowsInput.h"

/// <summary>
/// All Input for the Windows
/// </summary>
namespace Dred {
    Input* Input::s_instance = new WindowsInput();

    bool WindowsInput::IsKeyPressedImpl(int keycode)
    {
        auto* window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
        auto key = glfwGetKey(window, keycode);
        return key == GLFW_PRESS || key == GLFW_REPEAT;
    }

    bool WindowsInput::IsMouseButtonPressedImpl(int mouseButton)
    {
        auto* window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
        auto key = glfwGetMouseButton(window, mouseButton);
        return key == GLFW_PRESS;
    }

    float WindowsInput::GetMouseXImpl()
    {
        auto* window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
        double xpos;
        glfwGetCursorPos(window, &xpos, 0);
        return xpos;
    }

    float WindowsInput::GetMouseYImpl()
    {
        auto* window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
        double ypos;
        glfwGetCursorPos(window, 0, &ypos);
        return ypos;
    }

    std::pair<float, float> WindowsInput::GetMousePositionImpl() 
    {
        auto* window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);
        return std::pair<float, float>(xpos, ypos);
    }
}
