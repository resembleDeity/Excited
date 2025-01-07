// (C) Copyright Kirito 2025

#include "excitedpch.h"
#include "Shader.h"

#include "Platform/OpenGL/OpenGLShader.h"

#include "Excited/Renderer/RendererAPI.h"

namespace Excited
{
	TRef<IShader> IShader::CreateShader(const std::string& InFilePath)
	{
		TRef<IShader> Result = nullptr;

		switch (IRendererAPI::GetCurrentAPI())
		{
			case ERendererAPIType::None: 
				return nullptr;
			case ERendererAPIType::OpenGL: 
				Result = CreateRef<FOpenGLShader>(InFilePath);
				break;
			case ERendererAPIType::Vulkan:
				return nullptr;
		}

		return Result;
	}

	TRef<IShader> IShader::CreateShader(const std::string& InName, const std::string& InVertexSrc, const std::string& InFragmentSrc)
	{
		TRef<IShader> Result = nullptr;

		switch (IRendererAPI::GetCurrentAPI())
		{
			case ERendererAPIType::None:
				return nullptr;
			case ERendererAPIType::OpenGL:
				Result = CreateRef<FOpenGLShader>(InName, InVertexSrc, InFragmentSrc);
				break;
			case ERendererAPIType::Vulkan:
				return nullptr;
		}

		return Result;
	}

	UShaderLibrary::UShaderLibrary()
	{ }

	UShaderLibrary::~UShaderLibrary()
	{ }

	void UShaderLibrary::Add(const TRef<IShader>& InShader)
	{
		auto& Name = InShader->GetName();
		Add(Name, InShader);
	}

	void UShaderLibrary::Add(std::string_view InName, const TRef<IShader>& InShader)
	{
		EXCITED_CORE_ASSERT(!Exists(InName), "[Shader Library] Shader already exists!");
		Shaders[std::string(InName)] = InShader;
	}

	TRef<IShader> UShaderLibrary::Load(const std::string& InPath)
	{
		auto Shader = IShader::CreateShader(InPath);
		Add(Shader);
		return Shader;
	}

	TRef<IShader> UShaderLibrary::Load(std::string_view InName, const std::string& InPath)
	{
		auto Shader = IShader::CreateShader(InPath);
		Add(InName, Shader);
		return Shader;
	}

	TRef<IShader>& UShaderLibrary::Get(std::string_view InName)
	{
		EXCITED_CORE_ASSERT(Exists(InName), "[Shader Library] Shader not found!");
		return Shaders[std::string(InName)];
	}

	bool UShaderLibrary::Exists(std::string_view InName) const
	{
		return Shaders.find(std::string(InName)) != Shaders.end();
	}
}