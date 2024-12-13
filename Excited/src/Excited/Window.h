// (C) Copyright Kirito 2024

#pragma once

#include "excitedpch.h"

#include "Excited/Core.h"
#include "Excited/Events/Event.h"

namespace Excited
{
	struct FWindowProps
	{
		FWindowProps(const std::string& InTitle = "Excited Engine", 
					unsigned int InWidth = 1280, unsigned int InHeight = 720)
			:Title(InTitle), Width(InWidth), Height(InHeight)
		{ }

		std::string Title;
		unsigned int Width;
		unsigned int Height;
	};

	class IWindow
	{
	public:

		using FEventCallback = std::function<void(IEvent&)>;

		virtual ~IWindow() 
		{ }

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		virtual void SetEventCallback(const FEventCallback& InCallback) = 0;
		
		virtual void SetVSync(bool InbEnabled) = 0;
		virtual bool IsVSync() const = 0;

		static IWindow* Create(const FWindowProps& InProps = FWindowProps());
	};
}