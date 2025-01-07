// (C) Copyright Kirito 2025

#include "excitedpch.h"
#include "VertexBuffer.h"

#include "Excited/Renderer/Renderer.h"

#include "Platform/OpenGL/OpenGLVertexBuffer.h"
// #include "Platform/Vulkan/VulkanVertexBuffer.h"

namespace Excited
{
	TRef<IVertexBuffer> IVertexBuffer::CreateBuffer(void* InData, uint64_t InSize, EVertexBufferUsage InUsage /*= EVertexBufferUsage::Static*/)
	{
		TRef<IVertexBuffer> Result = nullptr;

		switch (IRendererAPI::GetCurrentAPI())
		{
			case ERendererAPIType::None:
				return nullptr;
			case ERendererAPIType::OpenGL:
				Result = CreateRef<FOpenGLVertexBuffer>(InData, InSize, InUsage);
				break;
			case ERendererAPIType::Vulkan:
				// Result = CreateRef<FVulkanVertexBuffer>(InData, InSize, InUsage);
				return nullptr;
				break;
		}

		EXCITED_CORE_ASSERT(false, "Unknown RendererAPI");
		return Result;
	}

	TRef<IVertexBuffer> IVertexBuffer::CreateBuffer(uint64_t InSize, EVertexBufferUsage InUsage /*= EVertexBufferUsage::Dynamic*/)
	{
		TRef<IVertexBuffer> Result = nullptr;

		switch (IRendererAPI::GetCurrentAPI())
		{
			case ERendererAPIType::None:
				return nullptr;
			case ERendererAPIType::OpenGL:
				Result = CreateRef<FOpenGLVertexBuffer>(InSize, InUsage);
				break;
			case ERendererAPIType::Vulkan:
				// Result = CreateRef<FVulkanVertexBuffer>(InSize, InUsage);
				return nullptr;
				break;
		}

		EXCITED_CORE_ASSERT(false, "Unknown RendererAPI");
		return Result;
	}
}