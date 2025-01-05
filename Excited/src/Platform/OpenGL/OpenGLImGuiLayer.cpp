// (C) Copyright Kirito 2025

#include "excitedpch.h"
#include "OpenGLImGuiLayer.h"

#include <imgui.h>
#include <imgui_internal.h>

#ifndef IMGUI_IMPL_API
	#define IMGUI_IMPL_API
#endif
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"

#include "Excited/Core/Application.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Excited
{

	FOpenGLImGuiLayer::FOpenGLImGuiLayer()
	{ }

	FOpenGLImGuiLayer::FOpenGLImGuiLayer(const std::string& InName)
	{ }

	FOpenGLImGuiLayer::~FOpenGLImGuiLayer()
	{ }

	void FOpenGLImGuiLayer::Begin()
	{
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
	}

	void FOpenGLImGuiLayer::End()
	{
		ImGuiIO& IO = ImGui::GetIO();
		IApplication& App = IApplication::GetInstance();
		IO.DisplaySize = ImVec2((float)App.GetWindow().GetWidth(), (float)App.GetWindow().GetHeight());

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		if (IO.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
		{
			GLFWwindow* BackupCurrentContext = glfwGetCurrentContext();
			ImGui::UpdatePlatformWindows();
			ImGui::RenderPlatformWindowsDefault();
			glfwMakeContextCurrent(BackupCurrentContext);
		}
	}

	void FOpenGLImGuiLayer::OnAttach()
	{
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGuiIO& IO = ImGui::GetIO(); (void)IO;
		IO.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
		IO.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;
		IO.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
		IO.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;
		// IO.ConfigFlags |= ImGuiConfigFlags_ViewportsNoTaskBarIcons;
		// IO.ConfigFlags |= ImGuiConfigFlags_ViewportsNoMerge;

		float FontSize = 18.0f;
		// IO.Fonts->AddFontFromFileTTF();
		// IO.FontDefault = IO.Fonts->AddFontFromFileTTF();

		ImGui::StyleColorsDark();
		// ImGui::StyleColorsClassic();

		ImGuiStyle& Style = ImGui::GetStyle();
		if (IO.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
		{
			Style.WindowRounding = 0.0f;
			Style.Colors[ImGuiCol_WindowBg].w = 1.0f;
		}

		SetDarkThemeV2Colors();

		IApplication& App = IApplication::GetInstance();
		GLFWwindow* Window = static_cast<GLFWwindow*>(App.GetWindow().GetNativeWindow());

		ImGui_ImplGlfw_InitForOpenGL(Window, true);
		ImGui_ImplOpenGL3_Init("#version 460");
	}

	void FOpenGLImGuiLayer::OnDetach()
	{
		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
		ImGui::DestroyContext();
	}

	void FOpenGLImGuiLayer::OnGuiRender()
	{

	}
}