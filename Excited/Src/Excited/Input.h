#pragma once

#include "Excited/Core.h"



namespace Excited 
{
    class EXCITED_API KInput
    {
    public:

        inline static bool IsKeyPressed(int KeyCode) { return Instance->IsKeyPressedImpl(KeyCode); }

        inline static bool IsMouseButtonPressed(int Button) { return Instance->IsMouseButtonPressedImpl(Button); }
        inline static float GetMouseX() { return Instance->GetMouseXImpl(); }
        inline static float GetMouseY() { return Instance->GetMouseYImpl(); }
        
    protected:

        virtual bool IsKeyPressedImpl(int KeyCode) = 0;

        virtual bool IsMouseButtonPressedImpl(int Button) = 0;
        virtual float GetMouseXImpl() = 0;
        virtual float GetMouseYImpl() = 0;
        
    private:
        static KInput* Instance;
    };
}