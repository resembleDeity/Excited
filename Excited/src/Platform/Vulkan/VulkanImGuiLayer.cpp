// (C) Copyright Kirito 2025

#include "excitedpch.h"
#include "VulkanImGuiLayer.h"

#include <imgui.h>

#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_vulkan.h"

namespace Excited
{
	
	FVulkanImGuiLayer::FVulkanImGuiLayer()
	{

	}

	FVulkanImGuiLayer::FVulkanImGuiLayer(const std::string& InName)
	{

	}

	FVulkanImGuiLayer::~FVulkanImGuiLayer()
	{

	}

	void FVulkanImGuiLayer::Begin()
	{
		ImGui_ImplVulkan_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
	}

	void FVulkanImGuiLayer::End()
	{
		ImGui::Render();
	}

	void FVulkanImGuiLayer::OnAttach()
	{

	}

	void FVulkanImGuiLayer::OnDetach()
	{

	}

	void FVulkanImGuiLayer::OnGuiRender()
	{

	}

}