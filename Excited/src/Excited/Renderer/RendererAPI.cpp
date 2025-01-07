#include "excitedpch.h"
#include "RendererAPI.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Excited
{
	void IRendererAPI::SetCurrentAPI(ERendererAPIType InAPI)
	{
		CurrentRendererAPI = InAPI;
	}

	TScope<IRendererAPI> IRendererAPI::CreateRenderer()
	{
		TScope<IRendererAPI> Result = nullptr;

		switch (CurrentRendererAPI)
		{
			case Excited::ERendererAPIType::None:
				return nullptr;
			case Excited::ERendererAPIType::OpenGL:
				Result = CreateScope<FOpenGLRendererAPI>();
				break;
			case Excited::ERendererAPIType::Vulkan:
				return nullptr;
		}

		return Result;
	}
}