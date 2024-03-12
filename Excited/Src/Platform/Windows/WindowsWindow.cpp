#include "Excitedpch.h"
#include "WindowsWindow.h"

#include "Excited/Events/ApplicationEvent.h"
#include "Excited/Events/MouseEvent.h"
#include "Excited/Events/KeyEvent.h"

#include <glad/glad.h>



namespace Excited
{
    static bool bGLFWInitialized = false;

    static void GLFWErrorCallback(int InErrorCode, const char* InDescription)
    {
        EXCITED_CORE_ERROR("GLFW Error ({0}): {1}", InErrorCode, InDescription);
    }
    
    KWindow* KWindow::Create(const FWindowProps& InProps)
    {
        return new KWindowsWindow(InProps);
    }
    
    KWindowsWindow::KWindowsWindow(const FWindowProps& InProps)
    {
        Init(InProps);
    }

    KWindowsWindow::~KWindowsWindow()
    {
        
    }

    void KWindowsWindow::Init(const FWindowProps& InProps)
    {
        Data.Title = InProps.Title;
        Data.Width = InProps.Width;
        Data.Height = InProps.Height;

        EXCITED_CORE_INFO("Creating Window {0} ({1}, {2})", InProps.Title, InProps.Width, InProps.Height);

        if (!bGLFWInitialized)
        {
            int Success = glfwInit();
            EXCITED_CORE_ASSERT(Success, "Could not initialized GLFW!");

            glfwSetErrorCallback(GLFWErrorCallback);
            
            bGLFWInitialized = true;
        }

        Window = glfwCreateWindow((int)InProps.Width, (int)InProps.Height, Data.Title.c_str(), nullptr, nullptr);
        glfwMakeContextCurrent(Window);

        int Status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        EXCITED_CORE_ASSERT(Status, "Failed to initialize Glad!");

        glfwSetWindowUserPointer(Window, &Data);
        SetVSync(true);

        

        // Set GLFW callbacks
        glfwSetWindowSizeCallback(Window, [](GLFWwindow* InWindow, int InWidth, int InHeight)
        {
            FWindowData& Data = *(FWindowData*)glfwGetWindowUserPointer(InWindow);
            Data.Width = InWidth;
            Data.Height = InHeight;

            KWindowResizeEvent Event(InWidth, InHeight);
            Data.EventCallback(Event);
        });

        glfwSetWindowCloseCallback(Window, [](GLFWwindow* InWindow)
        {
            FWindowData& Data = *(FWindowData*)glfwGetWindowUserPointer(InWindow);

            KWindowCloseEvent Event;
            Data.EventCallback(Event);
        });

        glfwSetKeyCallback(Window, [](GLFWwindow* InWindow, int InKeycode, int InScancode, int InAction, int InMods)
        {
            FWindowData& Data = *(FWindowData*)glfwGetWindowUserPointer(InWindow);

            switch (InAction)
            {
                case GLFW_PRESS:
                {
                    KKeyPressedEvent Event(InKeycode, 0);
                    Data.EventCallback(Event);
                    break;
                }
                case GLFW_RELEASE:
                {
                    KKeyReleasedEvent Event(InKeycode);
                    Data.EventCallback(Event);
                    break;
                }
                case GLFW_REPEAT:
                {
                    KKeyPressedEvent Event(InKeycode, 1);
                    Data.EventCallback(Event);
                    break;
                }
            }
        });

        glfwSetCharCallback(Window, [](GLFWwindow* InWindow, unsigned int InKeycode)
        {
            FWindowData& Data = *(FWindowData*)glfwGetWindowUserPointer(InWindow);
            
            KKeyTypedEvent Event(InKeycode);
            Data.EventCallback(Event);
        });

        glfwSetMouseButtonCallback(Window, [](GLFWwindow* InWindow, int InButton, int InAction, int InMods)
        {
            FWindowData& Data = *(FWindowData*)glfwGetWindowUserPointer(InWindow);

            switch (InAction)
            {
                case GLFW_PRESS:
                {
                    KMouseButtonPressedEvent Event(InButton);
                    Data.EventCallback(Event);
                    break;
                }
                case GLFW_RELEASE:
                {
                    KMouseButtonReleasedEvent Event(InButton);
                    Data.EventCallback(Event);
                    break;
                }
            }
        });

        glfwSetScrollCallback(Window, [](GLFWwindow* InWindow, double InXOffset, double InYOffset)
        {
            FWindowData& Data = *(FWindowData*)glfwGetWindowUserPointer(InWindow);

            KMouseScrolledEvent Event((float)InXOffset, (float)InYOffset);
            Data.EventCallback(Event);
        });

        glfwSetCursorPosCallback(Window, [](GLFWwindow* InWindow, double InXPos, double InYPos)
        {
            FWindowData& Data = *(FWindowData*)glfwGetWindowUserPointer(InWindow);

            KMouseMovedEvent Event((float)InXPos, (float)InYPos);
            Data.EventCallback(Event);
        });
    }

    void KWindowsWindow::Shutdown()
    {
    }

    void KWindowsWindow::OnUpdate()
    {
        glfwPollEvents();
        glfwSwapBuffers(Window);
    }

    void KWindowsWindow::SetVSync(bool Enabled)
    {
        if (Enabled)
        {
            glfwSwapInterval(1);
        }
        else
        {
            glfwSwapInterval(0);
        }

        Data.bVSync = Enabled;
    }

    bool KWindowsWindow::IsVSync() const
    {
        return Data.bVSync;
    }
}
