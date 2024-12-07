// (C) Copyright Kirito 2024

#pragma once

#include "Core.h"

namespace Excited
{
	class EXCITED_API Application
	{
	public:

		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();
}