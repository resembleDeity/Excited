#pragma once

#include "Core.h"

#include "Window.h"
#include "LayerStack.h"
#include "Excited/Events/ApplicationEvent.h"

namespace Excited
{
	class EXCITED_API KApplication
	{
	public:

		KApplication();
		virtual ~KApplication();

		void Run();

		void OnEvent(KEvent& InEvent);

		void PushLayer(KLayer* Layer);
		void PushOverlay(KLayer* Overlay);

	private:

		bool OnWindowClose(KWindowCloseEvent& InEvent);
		
	private:

		std::unique_ptr<KWindow> Window;

		KLayerStack LayerStack;
		
		bool bRunning = true;
	};

	// To be defined int CLIENT
	KApplication* CreateApplication();
}
