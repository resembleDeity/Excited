#pragma once

#include "Excitedpch.h"

#include "Excited/Core.h" 
#include "Events/Event.h"



namespace Excited
{
    struct FWindowProps
    {
        FWindowProps(const std::string& InTitle = "Excited Engine"
                    , unsigned int InWidth = 1280
                    , unsigned int InHeight = 720)
            : Title(InTitle), Width(InWidth), Height(InHeight)
        { }
        
        std::string Title;
        unsigned int Width;
        unsigned int Height;
    };

    class EXCITED_API KWindow
    {
    public:
        using FEventCallbackFn = std::function<void(KEvent&)>;

        virtual ~KWindow() { }

        
        
        virtual void OnUpdate() = 0;
        
        virtual unsigned int GetWidth() const = 0;
        virtual unsigned int GetHeight() const = 0;

        
        virtual void SetEventCallback(const FEventCallbackFn& InCallback) = 0;
        virtual void SetVSync(bool Enabled) = 0;
        virtual bool IsVSync() const = 0;

        static KWindow* Create(const FWindowProps& InProps = FWindowProps());
    };
}