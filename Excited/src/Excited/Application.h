// (C) Copyright Kirito 2024

#pragma once

#include "Core.h"

#include "Window.h"
#include "Excited/LayerStack.h"
#include "Excited/Events/Event.h"
#include "Excited/Events/ApplicationEvent.h"

int main(int argc, char** argv);

namespace Excited
{
	class Application
	{
		friend int ::main(int argc, char** argv);
	public:

		Application();
		virtual ~Application();

		void Run();

		void OnEvent(IEvent& InEvent);

		void PushLayer(ILayer* InLayer);
		void PushOverlay(ILayer* InLayer);

		inline static Application& GetInstance() { return *Instance; }
		inline IWindow& GetWindow() { return *Window; }

	private:

		bool OnWindowClose(IWindowCloseEvent& InEvent);

	private:

		static Application* Instance;
		bool bRunning = true;

		// 根据不同的平台 和 渲染 API 持有具体的窗口实例
		std::unique_ptr<IWindow> Window;

		FLayerStack LayerStack;
	};

	Application* CreateApplication();
}