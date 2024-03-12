#include "Excitedpch.h"
#include "Application.h"
#include "Events/Event.h"

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

	void KApplication::PushLayer(KLayer* Layer)
	{
		LayerStack.PushLayer(Layer);
	}

	void KApplication::PushOverlay(KLayer* Overlay)
	{
		LayerStack.PushOverlay(Overlay);
	}

	void KApplication::OnEvent(KEvent& InEvent)
	{
		TEventDispatcher Dispatcher(InEvent);
		Dispatcher.Dispatch<KWindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

		for (auto It = LayerStack.end(); It != LayerStack.begin(); )
		{
			(*--It)->OnEvent(InEvent);
			if (InEvent.bEventHandled)
			{
				break;
			}
		}
	}

	void KApplication::Run()
	{
		
		while (bRunning)
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			for (KLayer* Layer : LayerStack)
			{
				Layer->OnUpdate();
			}
			
			Window->OnUpdate();
		}
	}

	bool KApplication::OnWindowClose(KWindowCloseEvent& InEvent)
	{
		bRunning = false;
		return true;
	}
}