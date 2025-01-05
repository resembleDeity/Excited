// (C) Copyright Kirito 2024

#pragma once

#include "Event.h"
#include "Excited/Core/KeyCodes.h"

#include <sstream>

namespace Excited
{
	class IMouseMovedEvent : public IEvent
	{
	public:

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

		IMouseMovedEvent(float InX, float InY)
			: MouseX(InX), MouseY(InY)
		{ }

		inline float GetX() const { return MouseX; }
		inline float GetY() const { return MouseY; }

		virtual std::string ToString() const override
		{
			std::stringstream StrStream;
			StrStream << "[Event] Mouse Moved: " << MouseX << ", " << MouseY;
			return StrStream.str();
		}

	private:

		float MouseX, MouseY;
	};

	class IMouseScrolledEvent : public IEvent
	{
	public:

		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

		IMouseScrolledEvent(float InXOffset, float InYOffset)
			: XOffset(InXOffset), YOffset(InYOffset)
		{ }

		inline float GetXOffset() const { return XOffset; }
		inline float GetYOffset() const { return YOffset; }

		virtual std::string ToString() const override
		{
			std::stringstream StrStream;
			StrStream << "[Event] Mouse Scrolled: " << GetXOffset() << ", " << GetYOffset();
			return StrStream.str();
		}

	private:

		float XOffset, YOffset;
	};

	class IMouseButtonEvent : public IEvent
	{
	public:

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

		inline EMouseButton GetMouseButton() const { return Button; }

	protected:

		IMouseButtonEvent(EMouseButton InButton)
			: Button(InButton)
		{ }

		EMouseButton Button;
	};

	class IMouseButtonPressedEvent : public IMouseButtonEvent
	{
	public:

		EVENT_CLASS_TYPE(MouseButtonPressed)

		IMouseButtonPressedEvent(EMouseButton InButton)
			: IMouseButtonEvent(InButton)
		{ }

		virtual std::string ToString() const override
		{
			std::stringstream StrStream;
			StrStream << "[Event] Mouse Button Pressed: " << Button;
			return StrStream.str();
		}
	};

	class IMouseButtonReleasedEvent : public IMouseButtonEvent
	{
	public:

		EVENT_CLASS_TYPE(MouseButtonReleased)

		IMouseButtonReleasedEvent(EMouseButton InButton)
			: IMouseButtonEvent(InButton)
		{ }

		virtual std::string ToString() const override
		{
			std::stringstream StrStream;
			StrStream << "[Event] Mouse Button Released: " << Button;
			return StrStream.str();
		}
	};

	class IMouseButtonDownEvent : public IMouseButtonEvent
	{
	public:

		EVENT_CLASS_TYPE(MouseButtonDown)

		IMouseButtonDownEvent(EMouseButton InButton)
			: IMouseButtonEvent(InButton)
		{ }

		virtual std::string ToString() const override
		{
			std::stringstream StrStream;
			StrStream << "[Event] Mouse Button Down: " << Button;
			return StrStream.str();
		}
	};
}