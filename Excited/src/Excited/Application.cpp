// (C) Copyright Kirito 2024

#include "excitedpch.h"
#include "Application.h"

#include <glad/glad.h>

namespace Excited
{
	Application* Application::Instance = nullptr;

	Application::Application()
	{
		EXCITED_CORE_ASSERT(!Instance, "[Initialized] Application already exists!");
		Instance = this;

		Window = std::unique_ptr<IWindow>(IWindow::Create());
		Window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		while (bRunning)
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			for (ILayer* Layer : LayerStack)
			{
				Layer->OnUpdate();
			}
			Window->OnUpdate();
		}
	}

	void Application::OnEvent(IEvent& InEvent)
	{
		TEventDispatcher Dispatcher(InEvent);
		Dispatcher.Dispatch<IWindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowClose));

		EXCITED_CORE_TRACE("{0}", InEvent);

		for (auto It = LayerStack.end(); It != LayerStack.begin(); )
		{
			(*--It)->OnEvent(InEvent);
			if (InEvent.GetHandled())
			{
				break;
			}
		}
	}

	void Application::PushLayer(ILayer* InLayer)
	{
		LayerStack.PushLayer(InLayer);
		InLayer->OnAttach();
	}

	void Application::PushOverlay(ILayer* InLayer)
	{
		LayerStack.PushOverlay(InLayer);
		InLayer->OnAttach();
	}

	bool Application::OnWindowClose(IWindowCloseEvent& InEvent)
	{
		bRunning = false;

		return true;
	}
}