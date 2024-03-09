#pragma once

#include "Core.h"
#include "Window.h"

namespace Excited
{
	class EXCITED_API KApplication
	{
	public:

		KApplication();
		virtual ~KApplication();

		void Run();

	private:

		std::unique_ptr<KWindow> Window;

		bool bRunning = true;
	};

	// To be defined int CLIENT
	KApplication* CreateApplication();
}
