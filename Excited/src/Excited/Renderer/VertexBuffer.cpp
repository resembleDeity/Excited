// (C) Copyright Kirito 2025

#include "excitedpch.h"
#include "VertexBuffer.h"

#include "Platform/OpenGL/OpenGLVertexBuffer.h"

namespace Excited
{
	TRef<IVertexBuffer> IVertexBuffer::CreateBuffer(void* InData, uint64_t InSize, EVertexBufferUsage InUsage /*= EVertexBufferUsage::Static*/)
	{
		switch (IRendererAPI::GetCurrentAPI()
		{

		}
	}

	TRef<IVertexBuffer> IVertexBuffer::CreateBuffer(uint64_t InSize, EVertexBufferUsage InUsage /*= EVertexBufferUsage::Dynamic*/)
	{

	}
}