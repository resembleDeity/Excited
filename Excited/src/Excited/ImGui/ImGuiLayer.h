// (C) Copyright Kirito 2024

#pragma once

#include "Excited/Core/Layer.h"

namespace Excited
{
	class IImGuiLayer : public ILayer
	{
	public:

		virtual void Begin() = 0;
		virtual void End() = 0;

		void SetDarkThemeColors();
		void SetDarkThemeV2Colors();

		void AllowInputEvents(bool InbAllowEvents);

		static IImGuiLayer* CreateImGuiLayer();
	};
}