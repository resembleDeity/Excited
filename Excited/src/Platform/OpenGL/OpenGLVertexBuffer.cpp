// (C) Copyright Kirito 2025

#include "excitedpch.h"
#include "OpenGLVertexBuffer.h"

#include <glad/glad.h>

namespace Excited
{
	static GLenum BufferUsageToGLUsage(EVertexBufferUsage InUsage)
	{
		GLenum Result = GL_NONE;

		switch (InUsage)
		{
		case Excited::EVertexBufferUsage::None:
			EXCITED_CORE_ASSERT(false, "Unknown Buffer Usage!");
			return Result;
		case Excited::EVertexBufferUsage::Static:
			Result = GL_STATIC_DRAW;
			break;
		case Excited::EVertexBufferUsage::Dynamic:
			Result = GL_DYNAMIC_DRAW;
			break;
		}

		EXCITED_CORE_ASSERT(false, "Unknown Buffer Usage!");
		return Result;
	}

	FOpenGLVertexBuffer::FOpenGLVertexBuffer(void* InData, uint64_t InSize, EVertexBufferUsage InUsage /*= EVertexBufferUsage::Static*/)
		: Size(InSize)
	{
		glCreateBuffers(1, &RendererID);
		glBindBuffer(GL_ARRAY_BUFFER, RendererID);
		glBufferData(GL_ARRAY_BUFFER, InSize, InData, BufferUsageToGLUsage(InUsage));
	}

	FOpenGLVertexBuffer::FOpenGLVertexBuffer(uint64_t InSize, EVertexBufferUsage InUsage /*= EVertexBufferUsage::Dynamic*/)
		: Size(InSize)
	{
		glCreateBuffers(1, &RendererID);
		glBindBuffer(GL_ARRAY_BUFFER, RendererID);
		glBufferData(GL_ARRAY_BUFFER, InSize, nullptr, BufferUsageToGLUsage(InUsage));
	}

	FOpenGLVertexBuffer::~FOpenGLVertexBuffer()
	{
		glDeleteBuffers(1, &RendererID);
	}

	void FOpenGLVertexBuffer::Bind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, RendererID);
	}

	void FOpenGLVertexBuffer::Unbind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	void FOpenGLVertexBuffer::SetData(void* InBuffer, uint64_t InSize, uint64_t InOffset)
	{
		glBindBuffer(GL_ARRAY_BUFFER, RendererID);
		glBufferSubData(GL_ARRAY_BUFFER, 0, InSize, InBuffer);
	}

	void FOpenGLVertexBuffer::SetDataRuntime(void* InBuffer, uint64_t InSize, uint64_t InOffset)
	{

	}

	uint64_t FOpenGLVertexBuffer::GetSize() const
	{
		return Size;
	}

	FRendererID FOpenGLVertexBuffer::GetRendererID() const
	{
		return RendererID;
	}
}