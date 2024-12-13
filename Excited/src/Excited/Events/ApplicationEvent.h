// (C) Copyright Kirito 2024

#pragma once

#include "Excited/Events/Event.h"

namespace Excited
{
	class IWindowResizeEvent : public IEvent
	{
	public:

		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)

		IWindowResizeEvent(unsigned int InWidth, unsigned int InHeight)
			: Width(InWidth), Height(InHeight)
		{ }

		inline unsigned int GetWidth() const { return Width; }
		inline unsigned int GetHeight() const { return Height; }

		virtual std::string ToString() const override
		{
			std::stringstream StrStream;
			StrStream << "[Event] Window Resize: " << Width	<< ", " << Height;
			return StrStream.str();
		}

	private:

		unsigned int Width;

		unsigned int Height;
	};

	class IWindowCloseEvent : public IEvent
	{
	public:

		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)

		IWindowCloseEvent()
		{ }

		virtual std::string ToString() const override
		{
			std::stringstream StrStream;
			StrStream << "[Event] Window Close";
			return StrStream.str();
		}
	};

	class IAppTickEvent : public IEvent
	{
	public:

		EVENT_CLASS_TYPE(AppTick)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)

		IAppTickEvent()
		{ }
	};

	class IAppUpdateEvent : public IEvent
	{
	public:

		EVENT_CLASS_TYPE(AppUpdate)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)

		IAppUpdateEvent()
		{ }
	};

	class IAppRenderEvent : public IEvent
	{
	public:

		EVENT_CLASS_TYPE(AppRender)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)

		IAppRenderEvent()
		{ }
	};
}