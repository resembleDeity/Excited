#pragma once

#include "Core.h"
#include "Excited/Events/ApplicationEvent.h"
#include "Window.h"

namespace Excited
{
	class EXCITED_API KApplication
	{
	public:

		KApplication();
		virtual ~KApplication();

		void Run();

		void OnEvent(KEvent& InEvent);

	private:

		bool OnWindowClose(KWindowCloseEvent& InEvent);
		
	private:

		std::unique_ptr<KWindow> Window;

		bool bRunning = true;
	};

	// To be defined int CLIENT
	KApplication* CreateApplication();
}
