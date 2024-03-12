#pragma once

#include "Excited/Window.h"
#include <GLFW/glfw3.h>



namespace Excited
{
    class KWindowsWindow : public KWindow
    {
    public:

        KWindowsWindow(const FWindowProps& InProps);
        virtual ~KWindowsWindow() override;

        virtual void OnUpdate() override;

        virtual inline unsigned int GetWidth() const override { return Data.Width; }
        virtual inline unsigned int GetHeight() const override { return Data.Height; }

        virtual inline void SetEventCallback(const FEventCallbackFn& InCallback) override { Data.EventCallback = InCallback; }
        virtual void SetVSync(bool Enabled) override;
        virtual bool IsVSync() const override;

    private:

        virtual void Init(const FWindowProps& InProps);
        virtual void Shutdown();
        
    private:
            
        GLFWwindow* Window;

        struct FWindowData
        {
            std::string Title;
            unsigned int Width;
            unsigned int Height;
            bool bVSync;
            
            FEventCallbackFn EventCallback;
        };

        FWindowData Data;
    };
}
