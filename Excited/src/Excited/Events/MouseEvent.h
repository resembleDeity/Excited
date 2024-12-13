// (C) Copyright Kirito 2024

#pragma once

#include "Event.h"

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

		float MouseX;

		float MouseY;
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
			StrStream << "[Event] Mouse Scrolled: " << XOffset << ", " << YOffset;
			return StrStream.str();
		}

	private:

		float XOffset;

		float YOffset;
	};

	class IMouseButtonEvent : public IEvent
	{
	public:

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

		inline int GetMouseButton() const { return Button; }

	protected:

		IMouseButtonEvent(int InButton)
			: Button(InButton)
		{ }

		int Button;
	};

	class IMouseButtonPressedEvent : public IMouseButtonEvent
	{
	public:

		EVENT_CLASS_TYPE(MouseButtonPressed)

		IMouseButtonPressedEvent(int InButton)
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

		IMouseButtonReleasedEvent(int InButton)
			: IMouseButtonEvent(InButton)
		{ }

		virtual std::string ToString() const override
		{
			std::stringstream StrStream;
			StrStream << "[Event] Mouse Button Released: " << Button;
			return StrStream.str();
		}
	};
}