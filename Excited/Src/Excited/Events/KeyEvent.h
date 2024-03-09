#pragma once

#include "Event.h"



namespace Excited
{
	class EXCITED_API KKeyEvent : public KEvent
	{
	public:

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)

		inline int GetKeyCode() const { return KeyCode; }

	protected:

		KKeyEvent(int InKeyCode)
			: KeyCode(InKeyCode) 
		{ }

		int KeyCode;
	};

	class EXCITED_API KKeyPressedEvent : public KKeyEvent
	{
	public:

		EVENT_CLASS_TYPE(KeyPressed)

		KKeyPressedEvent(int InKeyCode, int InRepeatCount)
			: KKeyEvent(InKeyCode), RepeatCount(InRepeatCount)
		{ }

		
		
		inline int GetRepeatCount() const { return RepeatCount; }

		
		
		virtual std::string ToString() const override
		{
			std::stringstream StringStream;
			StringStream << "Key Pressed Event: " << KeyCode << " (" << RepeatCount << " repeats)";
			return StringStream.str();
		}
		
	private:

		int RepeatCount;
	};

	class EXCITED_API KKeyReleasedEvent : public KKeyEvent
	{
	public:

		EVENT_CLASS_TYPE(KeyReleased)
		
		KKeyReleasedEvent(int InKeyCode)
			: KKeyEvent(InKeyCode)
		{ }

		

		virtual std::string ToString() const override
		{
			std::stringstream StringStream;
			StringStream << "Key Released Event: " << KeyCode;
			return StringStream.str();
		}
	};
}