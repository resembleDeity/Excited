// (C) Copyright Kirito 2025

#pragma once

#include "Excited/ImGui/ImGuiLayer.h"

namespace Excited
{
	class FVulkanImGuiLayer : public IImGuiLayer
	{
	public:

		FVulkanImGuiLayer();
		FVulkanImGuiLayer(const std::string& InName);
		virtual ~FVulkanImGuiLayer();

		virtual void Begin() override;
		virtual void End() override;

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnGuiRender() override;

	private:

		float Time = 0.0f;
	};
}