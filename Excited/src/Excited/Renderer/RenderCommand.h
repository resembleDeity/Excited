// (C) Copyright Kirito 2025

#pragma once

#include "Excited/Renderer/RendererAPI.h"

namespace Excited
{
	class IRenderCommand
	{
	public:

		static void Init()
		{
			RendererAPI->Init();
		}

		static void SetViewport(uint32_t InX, uint32_t InY, uint32_t InWidth, uint32_t InHeight)
		{
			RendererAPI->SetViewport(InX, InY, InWidth, InHeight);
		}

		static void SetClearColor(const glm::vec4& InColor)
		{
			RendererAPI->SetClearColor(InColor);
		}

		static void Clear()
		{
			RendererAPI->Clear();
		}

		static void DrawIndexed()
		{

		}

	private:

		static TScope<IRendererAPI> RendererAPI;
	};
}