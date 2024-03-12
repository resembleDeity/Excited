#include "Excitedpch.h"
#include "Application.h"
#include "Events/Event.h"

#include <glad/glad.h>



namespace Excited
{
	KApplication* KApplication::Instance = nullptr;
	
	KApplication::KApplication()
	{
		EXCITED_CORE_ASSERT(!Instance, "Application already exists!");
		Instance = this;
		
		Window = std::unique_ptr<KWindow>(KWindow::Create());
		Window->SetEventCallback(EXCITED_BIND_EVENT_FN(KApplication::OnEvent));
	}

	KApplication::~KApplication()
	{
	}

	void KApplication::PushLayer(KLayer* Layer)
	{
		LayerStack.PushLayer(Layer);
		Layer->OnAttach();
	}

	void KApplication::PushOverlay(KLayer* Overlay)
	{
		LayerStack.PushOverlay(Overlay);
		Overlay->OnAttach();
	}

	void KApplication::OnEvent(KEvent& InEvent)
	{
		TEventDispatcher Dispatcher(InEvent);
		Dispatcher.Dispatch<KWindowCloseEvent>(EXCITED_BIND_EVENT_FN(KApplication::OnWindowClose));

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