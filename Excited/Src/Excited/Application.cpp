#include "Excitedpch.h"
#include "Application.h"

#include <GLFW/glfw3.h>



namespace Excited
{
#define BIND_EVENT_FN(x) std::bind(&KApplication::x, this, std::placeholders::_1)
	KApplication::KApplication()
	{
		Window = std::unique_ptr<KWindow>(KWindow::Create());
		Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
	}

	KApplication::~KApplication()
	{
	}

	void KApplication::OnEvent(KEvent& InEvent)
	{
		TEventDispatcher Dispatcher(InEvent);
		Dispatcher.Dispatch<KWindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));
		
		EXCITED_CORE_TRACE("{0}", InEvent);
	}

	void KApplication::Run()
	{
		
		while (bRunning)
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			Window->OnUpdate();
		}
	}

	bool KApplication::OnWindowClose(KWindowCloseEvent& InEvent)
	{
		bRunning = false;
		return true;
	}
}