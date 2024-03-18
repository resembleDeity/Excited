#pragma once

#include "Excited/Input.h"



namespace Excited
{
    class KWindowsInput : public KInput
    {
    protected:

        virtual bool IsKeyPressedImpl(int KeyCode) override;

        virtual bool IsMouseButtonPressedImpl(int Button) override;
        virtual float GetMouseXImpl() override;
        virtual float GetMouseYImpl() override;
    
    };
}
