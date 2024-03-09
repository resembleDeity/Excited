#pragma once

#include "Event.h"



namespace Excited
{
	class EXCITED_API KWindowResizeEvent : public KEvent
	{
	public:
		
		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)

		KWindowResizeEvent(unsigned int InWidth, unsigned int InHeight) 
			: Width(InWidth), Height(InHeight) 
		{ }

		
		
		inline unsigned int GetWidth() const { return Width; }
		inline unsigned int GetHeight() const { return Height; }

		
		
		virtual std::string ToString() const override
		{
			std::stringstream StringStream;
			StringStream << "Window Resize Event: " << Width << ", " << Height;
			return StringStream.str();
		}

	private:

		unsigned int Width;
		unsigned int Height;
	};

	class EXCITED_API KWindowCloseEvent : public KEvent
	{
	public:
		
		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)

		KWindowCloseEvent() { }
	};

	class EXCITED_API KApplicationTickEvent : public KEvent
	{
	public:

		EVENT_CLASS_TYPE(ApplicationTick)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
		
		KApplicationTickEvent() { }
	};

	class EXCITED_API KApplicationUpdateEvent : public KEvent
	{
	public:

		EVENT_CLASS_TYPE(ApplicationUpdate)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
		
		KApplicationUpdateEvent() { }
	};

	class EXCITED_API KApplicationRenderEvent : public KEvent
	{
	public:

		EVENT_CLASS_TYPE(ApplicationRender)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
		
		KApplicationRenderEvent() { }
	};
}
