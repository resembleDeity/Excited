// (C) Copyright Kirito 2025

#pragma once

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

		static ERendererAPIType GetCurrentAPI() { return CurrentRendererAPI; }
		static void SetCurrentAPI(ERendererAPIType InAPI);

	private:

		static inline ERendererAPIType CurrentRendererAPI = ERendererAPIType::OpenGL;
	};
}