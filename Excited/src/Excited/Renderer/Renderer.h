// (C) Copyright Kirito 2025

#pragma once

#include "Excited/Renderer/RenderCommand.h"

#include "Excited/Renderer/Shader.h"

namespace Excited
{
	class IRenderer
	{
	public:

		static void Init();
		static void Shutdown();

		static void OnWindowResize(uint32_t InWidth, uint32_t InHeight);

		static void BeginScene();
		static void EndScene();

		static void Submit(const TRef<IShader>& InShader);

		static ERendererAPIType GetRendererAPI() { return IRenderer::GetRendererAPI(); }

	private:

		struct FSceneData
		{
			glm::mat4 ViewProjectionMatrix;
		};

		static TScope<FSceneData> SceneData;
	};
}