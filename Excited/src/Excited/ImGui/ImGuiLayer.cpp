// (C) Copyright Kirito 2024

#include "excitedpch.h"
#include "ImGuiLayer.h"

#include "Excited/Application.h"

#include "imgui.h"
#include "Platform/OpenGL/ImGuiOpenGLRenderer.h"
#include <GLFW/glfw3.h>

namespace Excited
{
	FImGuiLayer::FImGuiLayer()
		: ILayer("ImGui")
	{ }

	FImGuiLayer::~FImGuiLayer()
	{ }

	void FImGuiLayer::OnAttach()
	{
		ImGui::CreateContext();
		ImGui::StyleColorsDark();

		ImGuiIO& IO = ImGui::GetIO();
		IO.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
		IO.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

		ImGui_ImplOpenGL3_Init("#version 460");
	}

	void FImGuiLayer::OnDetach()
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	void FImGuiLayer::OnUpdate()
	{
		ImGuiIO& IO = ImGui::GetIO();
		Application& App = Application::GetInstance();
		IO.DisplaySize = ImVec2(App.GetWindow().GetWidth(), App.GetWindow().GetHeight());

		float GLFWTime = (float)glfwGetTime();
		IO.DeltaTime = Time > 0.0f ? (GLFWTime - Time) : (0.0166666666666667f);
		Time = GLFWTime;

		ImGui_ImplOpenGL3_NewFrame();
		ImGui::NewFrame();

		static bool bShow = true;
		ImGui::ShowDemoWindow(&bShow);

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}

	void FImGuiLayer::OnEvent(IEvent& InEvent)
	{

	}
}