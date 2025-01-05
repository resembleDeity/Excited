// (C) Copyright Kirito 2024

#pragma once

#include "Event.h"
#include "Excited/Core/KeyCodes.h"

#include <sstream>

namespace Excited
{
	class IKeyEvent : public IEvent
	{
	public:

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)

		inline EKeyCode GetKeyCode() const { return KeyCode; }

	protected:

		IKeyEvent(EKeyCode InKeyCode)
			: KeyCode(InKeyCode)
		{ }

		EKeyCode KeyCode;
	};

	class IKeyPressedEvent : public IKeyEvent
	{
	public:

		EVENT_CLASS_TYPE(KeyPressed)

		IKeyPressedEvent(EKeyCode InKeyCode, int InRepeatCount)
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

		IKeyReleasedEvent(EKeyCode InKeyCode)
			: IKeyEvent(InKeyCode)
		{ }
		
		virtual std::string ToString() const override
		{
			std::stringstream StrStream;
			StrStream << "[Event] Key Released: " << KeyCode;
			return StrStream.str();
		}
	};

	class IKeyTypedEvent : public IKeyEvent
	{
	public:

		EVENT_CLASS_TYPE(KeyTyped)

		IKeyTypedEvent(EKeyCode InKeyCode)
			: IKeyEvent(InKeyCode)
		{ }

		virtual std::string ToString() const override
		{
			std::stringstream StrStream;
			StrStream << "[Event] Key Typed: " << KeyCode;
			return StrStream.str();
		}
	};
}