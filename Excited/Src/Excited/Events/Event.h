#pragma once

#include "Excited/Core.h"

#include <string>
#include <functional>



namespace Excited
{
	enum class EEventType
	{
		None = 0,

		WindowClose, 
		WindowResize,
		WindowFocus,
		WindowLostFocus,
		WindowMoved,

		ApplicationTick,
		ApplicationUpdate,
		ApplicationRender,

		KeyPressed,
		KeyReleased,

		MouseButtonPressed,
		MouseButtonReleased,
		MouseMoved,
		MouseScrolled,
	};

	enum EEventCategory
	{
		None = 0,

		EventCategoryApplication	= BIT(0),
		EventCategoryInput			= BIT(1),
		EventCategoryKeyboard		= BIT(2),
		EventCategoryMouse			= BIT(3),
		EventCategoryMouseButton	= BIT(4),
	};

	

	#define EVENT_CLASS_TYPE(InType) \
		static EEventType GetStaticType() { return EEventType::##InType; } \
		virtual EEventType GetEventType() const override { return GetStaticType(); } \
		virtual const char* GetName() const override { return #InType; }

	#define EVENT_CLASS_CATEGORY(InCategory) \
		virtual int GetCategoryFlags() const override { return InCategory; }



	class EXCITED_API KEvent
	{
		friend class TEventDispatcher;
	public:

		virtual EEventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(EEventCategory InCategory)
		{
			return GetCategoryFlags() & InCategory;
		}

	protected:

		bool bEventHandled = false;
	};

	class TEventDispatcher
	{
		template <typename T>
		using TEventFn = std::function<bool(T&)>;
	public:

		TEventDispatcher(KEvent& InEvent)
			: Event(InEvent)
		{ }

		

		template <typename T>
		bool Dispatch(TEventFn<T> Func)
		{
			if (Event.GetEventType() == T::GetStaticType())
			{
				Event.bEventHandled = Func(*(T*)&Event);
				return true;
			}
			return false;
		}

	private:

		KEvent& Event;
	};


	
	inline std::ostream& operator<<(std::ostream& OS, const KEvent& Event)
	{
		return OS << Event.ToString();
	}
}