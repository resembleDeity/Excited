// (C) Copyright Kirito 2024

#pragma once

#include "excitedpch.h"

#include "Excited/Core.h"

namespace Excited
{
	enum class EEventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum EEventCategory
	{
		None = 0,
		EventCategoryApplication	= Bit(0),
		EventCategoryInput			= Bit(1),
		EventCategoryKeyboard		= Bit(2),
		EventCategoryMouse			= Bit(3),
		EventCategoryMouseButton	= Bit(4)
	};

#define EVENT_CLASS_TYPE(InType) \
							static EEventType GetStaticType() { return EEventType::##InType; } \
							virtual EEventType GetEventType() const override { return GetStaticType(); } \
							virtual const char* GetName() const override { return #InType; }

#define EVENT_CLASS_CATEGORY(InCategory) \
							virtual int GetCategoryFlags() const override { return InCategory; }

	class IEvent
	{
		friend class TEventDispatcher;

	public:

		virtual EEventType GetEventType() const = 0;

		virtual const char* GetName() const = 0;

		virtual int GetCategoryFlags() const = 0;

		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(EEventCategory InCategory) { return GetCategoryFlags() & InCategory; }
	
		bool GetHandled() const { return Handled; }

	protected:

		bool Handled = false;
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
			if (Event.GetEventType() == TEvent::GetStaticType())
			{
				Event.Handled = InFunc(*(TEvent*)&Event);
				return true;
			}
			return false;
		}

	private:

		IEvent& Event;
	};

	inline std::string format_as(const IEvent& InEvent)
	{
		return InEvent.ToString();
	}
}