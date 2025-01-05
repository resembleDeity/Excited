// (C) Copyright Kirito 2024

#include "excitedpch.h"
#include "Application.h"

#include <glad/glad.h>

extern bool bGApplicationRunning;

namespace Excited
{
	IApplication* IApplication::Instance = nullptr;

	IApplication::IApplication(const FApplicationSpecification& InSpecification)
	{
		EXCITED_CORE_ASSERT(!Instance, "[Initialized] IApplication already exists!");
		Instance = this;

		if (!InSpecification.WorkingDirectory.empty())
		{
			std::filesystem::current_path(InSpecification.WorkingDirectory);
		}

		Window = std::unique_ptr<FWindow>(FWindow::Create());
		Window->Init();
		Window->SetEventCallback(EXCITED_BIND_EVENT_FN(IApplication::OnEvent));

		GuiLayer = IImGuiLayer::CreateImGuiLayer();
		PushOverlay(GuiLayer);
	}

	IApplication::~IApplication()
	{
	}

	void IApplication::Run()
	{
		while (bRunning)
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			for (ILayer* Layer : LayerStack)
			{
				Layer->OnUpdate();
			}

			RenderGui();
			GuiLayer->End();

			ProcessEvents();
			Window->SwapBuffers();
		}

		OnShutdown();
	}

	void IApplication::Close()
	{
		bRunning = false;
	}

	void IApplication::OnShutdown()
	{
		bGApplicationRunning = false;
	}

	void IApplication::RenderGui()
	{
		GuiLayer->Begin();

		for (int i = 0; i < LayerStack.Size(); i++)
		{
			LayerStack[i]->OnGuiRender();
		}
	}

	void IApplication::OnEvent(IEvent& InEvent)
	{
		TEventDispatcher Dispatcher(InEvent);
		Dispatcher.Dispatch<IWindowCloseEvent>(EXCITED_BIND_EVENT_FN(IApplication::OnWindowClose));
		Dispatcher.Dispatch<IWindowResizeEvent>(EXCITED_BIND_EVENT_FN(IApplication::OnWindowResize));

		for (auto It = LayerStack.end(); It != LayerStack.begin(); )
		{
			(*--It)->OnEvent(InEvent);
			if (InEvent.Handled)
			{
				break;
			}
		}

		if (InEvent.Handled)
		{
			return;
		}
	}

	void IApplication::PushLayer(ILayer* InLayer)
	{
		LayerStack.PushLayer(InLayer);
		InLayer->OnAttach();
	}

	void IApplication::PushOverlay(ILayer* InLayer)
	{
		LayerStack.PushOverlay(InLayer);
		InLayer->OnAttach();
	}

	void IApplication::PopLayer(ILayer* InLayer)
	{
		LayerStack.PopLayer(InLayer);
		InLayer->OnDetach();
	}

	void IApplication::PopOverlay(ILayer* InLayer)
	{
		LayerStack.PopOverlay(InLayer);
		InLayer->OnDetach();
	}

	void IApplication::ProcessEvents()
	{
		Window->ProcessEvents();
	}

	bool IApplication::OnWindowResize(IWindowResizeEvent& InEvent)
	{
		const uint32_t Width = InEvent.GetWidth();
		const uint32_t Height = InEvent.GetHeight();
		if (Width == 0 || Height == 0)
		{
			// bMinimized = true;
			return false;
		}
		// bMinimized = false;

		auto& LamdaWindow = Window;

		return false;
	}

	bool IApplication::OnWindowClose(IWindowCloseEvent& InEvent)
	{
		Close();
		return true;
	}
}