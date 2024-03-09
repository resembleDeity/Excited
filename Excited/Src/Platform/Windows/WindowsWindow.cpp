#include "Excitedpch.h"
#include "WindowsWindow.h"



namespace Excited
{
    static bool bGLFWInitialized = false;
    
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

            bGLFWInitialized = true;
        }

        Window = glfwCreateWindow((int)InProps.Width, (int)InProps.Height, Data.Title.c_str(), nullptr, nullptr);
        glfwMakeContextCurrent(Window);
        glfwSetWindowUserPointer(Window, &Data);
        SetVSync(true);
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
