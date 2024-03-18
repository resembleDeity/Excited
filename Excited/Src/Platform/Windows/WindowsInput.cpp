#include "Excitedpch.h"
#include "WindowsInput.h"

#include "Excited/Application.h"
#include <GLFW/glfw3.h>



namespace Excited
{
    bool KWindowsInput::IsKeyPressedImpl(int KeyCode)
    {
        auto Window = static_cast<GLFWwindow*>(KApplication::GetApplication().GetWindow().GetNativeWindow());
        auto State = glfwGetKey(Window, KeyCode);

        return State == GLFW_PRESS || State == GLFW_REPEAT;
    }

    bool KWindowsInput::IsMouseButtonPressedImpl(int Button)
    {
        auto Window = static_cast<GLFWwindow*>(KApplication::GetApplication().GetWindow().GetNativeWindow());
        auto State = glfwGetMouseButton(Window, Button);

        return State == GLFW_PRESS;
    }

    float KWindowsInput::GetMouseXImpl()
    {
        auto Window = static_cast<GLFWwindow*>(KApplication::GetApplication().GetWindow().GetNativeWindow());
        double XPos = 0;
        double YPos = 0;
        glfwGetCursorPos(Window, &XPos, &YPos);

        return (float)XPos;
    }

    float KWindowsInput::GetMouseYImpl()
    {
        auto Window = static_cast<GLFWwindow*>(KApplication::GetApplication().GetWindow().GetNativeWindow());
        double XPos = 0;
        double YPos = 0;
        glfwGetCursorPos(Window, &XPos, &YPos);

        return (float)YPos;
    }
}
