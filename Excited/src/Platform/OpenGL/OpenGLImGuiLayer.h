// (C) Copyright Kirito 2025

#pragma once

#include "Excited/ImGui/ImGuiLayer.h"

namespace Excited
{
	class FOpenGLImGuiLayer : public IImGuiLayer
	{
	public:

		FOpenGLImGuiLayer();
		FOpenGLImGuiLayer(const std::string& InName);
		virtual ~FOpenGLImGuiLayer();

		virtual void Begin() override;
		virtual void End() override;

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnGuiRender() override;

	private:

		float Time = 0.0f;
	};
}