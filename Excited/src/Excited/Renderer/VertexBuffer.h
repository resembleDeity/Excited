// (C) Copyright Kirito 2025

#pragma once

#include "RendererTypes.h"
#include "Excited/Core/Assert.h"

namespace Excited
{
	enum class EShaderDataType
	{
		None = 0,
		Bool,
		Int, Int2, Int3, Int4,
		Float, Float2, Float3, Float4,
		Mat3, Mat4,
	};

	static uint32_t ShaderDataTypeToSize(EShaderDataType InType)
	{
		switch (InType)
		{
			case Excited::EShaderDataType::Bool:	return 1;
			case Excited::EShaderDataType::Int:		return 4;
			case Excited::EShaderDataType::Int2:	return 4 * 2;
			case Excited::EShaderDataType::Int3:	return 4 * 3;
			case Excited::EShaderDataType::Int4:	return 4 * 4;
			case Excited::EShaderDataType::Float:	return 4;
			case Excited::EShaderDataType::Float2:	return 4 * 2;
			case Excited::EShaderDataType::Float3:	return 4 * 3;
			case Excited::EShaderDataType::Float4:	return 4 * 4;
			case Excited::EShaderDataType::Mat3:	return 4 * 3 * 3;
			case Excited::EShaderDataType::Mat4:	return 4 * 4 * 4;
		}

		EXCITED_CORE_ASSERT(false, "[Shader] Unknown ShaderDataType!");
		return 0;
	}

	struct FVertexBufferElement
	{
		std::string Name;
		EShaderDataType Type;
		uint32_t Size;
		uint32_t Offset;
		bool bNormalized;

		FVertexBufferElement() = default;

		FVertexBufferElement(EShaderDataType InType, const std::string& InName, bool InbNormalized = false)
			: Name(InName)
			, Type(InType), Size(ShaderDataTypeToSize(InType)), Offset(0)
			, bNormalized(InbNormalized)
		{ }

		uint32_t GetComponentCount() const
		{
			switch (Type)
			{
				case Excited::EShaderDataType::Bool:	return 1;
				case Excited::EShaderDataType::Int:		return 1;
				case Excited::EShaderDataType::Int2:	return 2;
				case Excited::EShaderDataType::Int3:	return 3;
				case Excited::EShaderDataType::Int4:	return 4;
				case Excited::EShaderDataType::Float:	return 1;
				case Excited::EShaderDataType::Float2:	return 2;
				case Excited::EShaderDataType::Float3:	return 3;
				case Excited::EShaderDataType::Float4:	return 4;
				case Excited::EShaderDataType::Mat3:	return 3 * 3;
				case Excited::EShaderDataType::Mat4:	return 4 * 4;
			}

			EXCITED_CORE_ASSERT(false, "[Shader] Unknown ShaderDataType!");
			return 0;
		}
	};

	class FVertexBufferLayout
	{
	public:

		FVertexBufferLayout()
		{ }

		FVertexBufferLayout(const std::initializer_list<FVertexBufferElement>& InElements)
			: Elements(InElements)
		{
			CalculateOffsetsAndStride();
		}

		uint32_t GetStride() const { return Stride; }
		const std::vector<FVertexBufferElement>& GetElements() const { return Elements; }
		uint32_t GetElementCount() const { return (uint32_t)Elements.size(); }

		[[nodiscard]] std::vector<FVertexBufferElement>::iterator begin() { return Elements.begin(); }
		[[nodiscard]] std::vector<FVertexBufferElement>::iterator end() { return Elements.end(); }
		[[nodiscard]] std::vector<FVertexBufferElement>::const_iterator begin() const { return Elements.begin(); }
		[[nodiscard]] std::vector<FVertexBufferElement>::const_iterator end() const { return Elements.end(); }

	private:

		void CalculateOffsetsAndStride()
		{
			uint32_t Offset = 0;
			Stride = 0;
			for (auto& Element : Elements)
			{
				Element.Offset = Offset;
				Offset += Element.Size;
				Stride += Element.Size;
			}
		}

	private:

		std::vector<FVertexBufferElement> Elements;
		uint32_t Stride = 0;
	};

	enum class EVertexBufferUsage
	{
		None = 0, Static = 1, Dynamic = 2,
	};

	class IVertexBuffer
	{
	public:

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		virtual void SetData(void* InBuffer, uint64_t InSize, uint64_t InOffset) = 0;
		virtual void SetDataRuntime(void* InBuffer, uint64_t InSize, uint64_t InOffset) = 0;

		virtual uint64_t GetSize() const = 0;
		virtual FRendererID GetRendererID() const = 0;

		virtual const FVertexBufferLayout& GetLayout() const = 0;
		virtual void SetLayout(const FVertexBufferLayout& InLayout) = 0;

		static TRef<IVertexBuffer> CreateBuffer(void* InData, uint64_t InSize, EVertexBufferUsage InUsage = EVertexBufferUsage::Static);
		static TRef<IVertexBuffer> CreateBuffer(uint64_t InSize, EVertexBufferUsage InUsage = EVertexBufferUsage::Dynamic);
	};
}