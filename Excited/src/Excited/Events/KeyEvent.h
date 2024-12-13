// (C) Copyright Kirito 2024

#pragma once

#include "Event.h"

namespace Excited
{
	class IKeyEvent : public IEvent
	{
	public:

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)

		inline int GetKeyCode() const { return KeyCode; }

	protected:

		IKeyEvent(int InKeyCode)
			: KeyCode(InKeyCode)
		{ }

		int KeyCode;
	};

	class IKeyPressedEvent : public IKeyEvent
	{
	public:

		EVENT_CLASS_TYPE(KeyPressed)

		IKeyPressedEvent(int InKeyCode, int InRepeatCount)
			: IKeyEvent(InKeyCode), RepeatCount(InRepeatCount)
		{ }

		inline int GetRepeatCount() const { return RepeatCount; }

		virtual std::string ToString() const override
		{
			std::stringstream StrStream;
			StrStream << "[Event] Key Pressed: " << KeyCode << " (" << RepeatCount << " repeats)";
			return StrStream.str();
		}

	private:

		int RepeatCount;
	};

	class IKeyReleasedEvent : public IKeyEvent
	{
	public:

		EVENT_CLASS_TYPE(KeyReleased)

		IKeyReleasedEvent(int InKeyCode)
			: IKeyEvent(InKeyCode)
		{ }
		
		virtual std::string ToString() const override
		{
			std::stringstream StrStream;
			StrStream << "[Event] Key Released: " << KeyCode;
			return StrStream.str();
		}
	};
}