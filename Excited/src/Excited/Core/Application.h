// (C) Copyright Kirito 2024

#pragma once

#include "Excited/Core/Core.h"
#include "Excited/Core/Window.h"
#include "Excited/Core/LayerStack.h"

#include "Excited/Core/Events/ApplicationEvent.h"

#include "Excited/ImGui/ImGuiLayer.h"

int main(int argc, char** argv);

namespace Excited
{
	struct FApplicationSpecification
	{
		std::string Name = "Excited";
		uint32_t WindowWidth = 1600;
		uint32_t WindowHeight = 900;
		std::string WorkingDirectory;
	};

	class IApplication
	{
		friend int ::main(int argc, char** argv);
	public:

		IApplication(const FApplicationSpecification& InSpecification);
		virtual ~IApplication();

		void Run();
		void Close();

		virtual void OnInit() { }
		virtual void OnShutdown();
		virtual void OnUpdate() { }
		void RenderGui();

		virtual void OnEvent(IEvent& InEvent);

		void PushLayer(ILayer* InLayer);
		void PushOverlay(ILayer* InLayer);
		void PopLayer(ILayer* InLayer);
		void PopOverlay(ILayer* InLayer);

		const FApplicationSpecification& GetSpecification() const { return Specification; }

		static inline IApplication& GetInstance() { return *Instance; }
		inline FWindow& GetWindow() { return *Window; }

	private:

		void ProcessEvents();

		bool OnWindowResize(IWindowResizeEvent& InEvent);
		bool OnWindowClose(IWindowCloseEvent& InEvent);

	private:

		static IApplication* Instance;
		bool bRunning = true;

		// 根据不同的平台 和 渲染 API 持有具体的窗口实例
		std::unique_ptr<FWindow> Window;
		FApplicationSpecification Specification;

		FLayerStack LayerStack;
		IImGuiLayer* GuiLayer;
	};

	IApplication* CreateApplication();
}