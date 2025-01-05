// (C) Copyright Kirito 2024

#pragma once

#include "Excited/Core/Events/Event.h"

#include <sstream>

namespace Excited
{
	class IWindowResizeEvent : public IEvent
	{
	public:

		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)

		IWindowResizeEvent(uint32_t InWidth, uint32_t InHeight)
			: Width(InWidth), Height(InHeight)
		{ }

		inline uint32_t GetWidth() const { return Width; }
		inline uint32_t GetHeight() const { return Height; }

		virtual std::string ToString() const override
		{
			std::stringstream StrStream;
			StrStream << "[Event] Window Resize: " << Width	<< ", " << Height;
			return StrStream.str();
		}

	private:

		uint32_t Width, Height;
	};

	class IWindowMinimizeEvent : public IEvent
	{
	public:

		EVENT_CLASS_TYPE(WindowMinimize)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)

		IWindowMinimizeEvent(bool InbMinimized)
			: bMinimized(InbMinimized)
		{ }

		bool IsMinimized() const { return bMinimized; }

		virtual std::string ToString() const override
		{
			std::stringstream StrStream;
			StrStream << "[Event] Window Minimize";
			return StrStream.str();
		}

	private:

		bool bMinimized = false;
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

		virtual std::string ToString() const override
		{
			std::stringstream StrStream;
			StrStream << "[Event] Application Tick";
			return StrStream.str();
		}
	};

	class IAppUpdateEvent : public IEvent
	{
	public:

		EVENT_CLASS_TYPE(AppUpdate)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)

		IAppUpdateEvent()
		{ }

		virtual std::string ToString() const override
		{
			std::stringstream StrStream;
			StrStream << "[Event] Application Update";
			return StrStream.str();
		}
	};

	class IAppRenderEvent : public IEvent
	{
	public:

		EVENT_CLASS_TYPE(AppRender)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)

		IAppRenderEvent()
		{ }

		virtual std::string ToString() const override
		{
			std::stringstream StrStream;
			StrStream << "[Event] Application Render";
			return StrStream.str();
		}
	};
}