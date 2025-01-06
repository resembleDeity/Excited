// (C) Copyright Kirito 2025

#pragma once

#include <glm/glm.hpp>

namespace Excited
{
	enum class ERendererAPIType
	{
		None,
		OpenGL,
		Vulkan,
	};

	class IRendererAPI
	{
	public:

		virtual void Init() = 0;
		virtual void SetViewport(uint32_t InX, uint32_t InY, uint32_t InWidth, uint32_t InHeight) = 0;
		virtual void SetClearColor(const glm::vec4& InColor) = 0;
		virtual void Clear() = 0;

		static ERendererAPIType GetCurrentAPI() { return CurrentRendererAPI; }
		static void SetCurrentAPI(ERendererAPIType InAPI);

		static TScope<IRendererAPI> CreateRenderer();

	private:

		static inline ERendererAPIType CurrentRendererAPI = ERendererAPIType::OpenGL;
	};
}