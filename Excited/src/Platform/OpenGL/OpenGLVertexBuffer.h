// (C) Copyright Kirito 2025

#pragma once

#include "Excited/Renderer/VertexBuffer.h"

namespace Excited
{
	class FOpenGLVertexBuffer : public IVertexBuffer
	{
	public:

		FOpenGLVertexBuffer(void* InData, uint64_t InSize, EVertexBufferUsage InUsage = EVertexBufferUsage::Static);
		FOpenGLVertexBuffer(uint64_t InSize, EVertexBufferUsage InUsage = EVertexBufferUsage::Dynamic);
		virtual ~FOpenGLVertexBuffer();

		virtual void Bind() const override;
		virtual void Unbind() const override;

		virtual void SetData(void* InBuffer, uint64_t InSize, uint64_t InOffset) override;
		virtual void SetDataRuntime(void* InBuffer, uint64_t InSize, uint64_t InOffset) override;


		virtual uint64_t GetSize() const override;
		virtual FRendererID GetRendererID() const override;

		virtual const FVertexBufferLayout& GetLayout() const override { return Layout; }
		virtual void SetLayout(const FVertexBufferLayout& InLayout) override { Layout = InLayout; }

	private:

		FRendererID RendererID;

		uint64_t Size = 0;
		FVertexBufferLayout Layout;
	};
}