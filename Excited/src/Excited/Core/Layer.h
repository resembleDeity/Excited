// (C) Copyright Kirito 2024

#pragma once

#include "Excited/Core/Events/Event.h"

namespace Excited
{
	class ILayer
	{
	public:

		ILayer(const std::string& InName = "Layer");
		virtual ~ILayer();

		virtual void OnAttach() { }
		virtual void OnDetach() { }
		virtual void OnUpdate() { }
		virtual void OnGuiRender() { }
		virtual void OnEvent(IEvent& InEvent) { }

		inline const std::string& GetName() const { return DebugName; }

	protected:

		std::string DebugName;
	};
}