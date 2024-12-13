// (C) Copyright Kirito 2024

#pragma once

#include "Excited/Layer.h"

namespace Excited
{
	class FImGuiLayer : public ILayer
	{
	public:

		FImGuiLayer();
		~FImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnUpdate() override;
		virtual void OnEvent(IEvent& InEvent) override;

	private:

		float Time = 0.0f;
	};
}