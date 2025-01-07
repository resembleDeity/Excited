// (C) Copyright Kirito 2025

#pragma once

#include "Excited/Renderer/RendererAPI.h"

namespace Excited
{
	class FOpenGLRendererAPI : public IRendererAPI
	{
	public:

		virtual void Init() override;

		virtual void SetViewport(uint32_t InX, uint32_t InY, uint32_t InWidth, uint32_t InHeight) override;

		virtual void SetClearColor(const glm::vec4& InColor) override;
		virtual void Clear() override;
	};
}