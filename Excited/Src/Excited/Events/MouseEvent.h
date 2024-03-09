#pragma once

#include "Event.h"

#include <sstream>



namespace Excited
{
    class EXCITED_API KMouseMovedEvent : public KEvent
    {
    public:

        EVENT_CLASS_TYPE(MouseMoved)
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

        KMouseMovedEvent(float InX, float InY)
            : MouseX(InX), MouseY(InY)
        { }

        
        
        inline float GetX() const { return MouseX; }
        inline float GetY() const { return MouseY; }



        virtual std::string ToString() const override
        {
            std::stringstream StringStream;
            StringStream << "Mouse Moved Event: " << MouseX << ", " << MouseY;
            return StringStream.str();
        }

    private:

        float MouseX;
        float MouseY;
    };

    class EXCITED_API KMouseScrolledEvent : public KEvent
    {
    public:

        EVENT_CLASS_TYPE(MouseScrolled)
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

        KMouseScrolledEvent(float InXOffset, float InYOffset)
            : XOffset(InXOffset), YOffset(InYOffset)
        { }



        inline float GetXOffset() const { return XOffset; }
        inline float GetYOffset() const { return YOffset; }



        virtual std::string ToString() const override
        {
            std::stringstream StringStream;
            StringStream << "Mouse Scrolled Event: " << XOffset << ", " << YOffset;
            return StringStream.str();
        }
    
    private:

        float XOffset;
        float YOffset;
    };

    class EXCITED_API KMouseButtonEvent : public KEvent
    {
    public:

        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

        inline int GetMouseButton() const { return Button; }

    protected:

        KMouseButtonEvent(int InButton)
            : Button(InButton)
        { }
        
        int Button;
    };
    
    class EXCITED_API KMouseButtonPressedEvent : public KMouseButtonEvent
    {
    public:

        EVENT_CLASS_TYPE(MouseButtonPressed)

        KMouseButtonPressedEvent(int InButton)
            : KMouseButtonEvent(InButton)
        { }
        
        

        virtual std::string ToString() const override
        {
            std::stringstream StringStream;
            StringStream << "Mouse Button Pressed Event: " << Button;
            return StringStream.str();
        }
    };

    class EXCITED_API KMouseButtonReleasedEvent : public KMouseButtonEvent
    {
    public:

        EVENT_CLASS_TYPE(MouseButtonReleased)

        KMouseButtonReleasedEvent(int InButton)
            : KMouseButtonEvent(InButton)
        { }



        virtual std::string ToString() const override
        {
            std::stringstream StringStream;
            StringStream << "Mouse Button Released Event: " << Button;
            return StringStream.str();
        }
    };
}
