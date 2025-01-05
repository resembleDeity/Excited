// (C) Copyright Kirito 2024

#pragma once

#include "Excited/Core/Core.h"

#include <ostream>
#include <string>

namespace Excited
{
	enum class EEventType
	{
		None = 0,
		WindowClose, WindowMinimize, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased, KeyTyped,
		MouseButtonPressed, MouseButtonReleased, MouseButtonDown, MouseMoved, MouseScrolled
	};

	enum EEventCategory
	{
		None = 0,
		EventCategoryApplication	= BIT(0),
		EventCategoryInput			= BIT(1),
		EventCategoryKeyboard		= BIT(2),
		EventCategoryMouse			= BIT(3),
		EventCategoryMouseButton	= BIT(4)
	};

#define EVENT_CLASS_TYPE(InType) \
							static EEventType GetStaticType() { return EEventType::InType; } \
							virtual EEventType GetEventType() const override { return GetStaticType(); } \
							virtual const char* GetName() const override { return #InType; }

#define EVENT_CLASS_CATEGORY(InCategory) \
							virtual int GetCategoryFlags() const override { return InCategory; }

	class IEvent
	{
	public:

		virtual ~IEvent() { }

		virtual EEventType GetEventType() const = 0;

		virtual const char* GetName() const = 0;

		virtual int GetCategoryFlags() const = 0;

		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(EEventCategory InCategory) 
		{
			return GetCategoryFlags() & InCategory; 
		}
	
		bool Handled = false;
		bool Synced = false;
	};

	class TEventDispatcher
	{
		template <typename TEvent>
		using FRetEventCallback = std::function<bool(TEvent&)>;

	public:

		TEventDispatcher(IEvent& InEvent)
			: Event(InEvent)
		{ }

		template <typename TEvent>
		bool Dispatch(FRetEventCallback<TEvent> InFunc)
		{
			if (Event.GetEventType() == TEvent::GetStaticType() && !Event.Handled)
			{
				Event.Handled = InFunc(*(TEvent*)&Event);
				return true;
			}
			return false;
		}

	private:

		IEvent& Event;
	};

	inline std::ostream& operator<<(std::ostream& InOS, const IEvent& InEvent)
	{
		return InOS << InEvent.ToString();
	}

	inline std::string format_as(const IEvent& InEvent)
	{
		return InEvent.ToString();
	}
}