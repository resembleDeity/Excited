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

	UShaderLibrary::UShaderLibrary()
	{ }

	UShaderLibrary::~UShaderLibrary()
	{ }

	void UShaderLibrary::Add(const TRef<IShader>& InShader)
	{
		auto& Name = InShader->GetName();
		EXCITED_CORE_ASSERT(Shaders.find(Name) == Shaders.end(), "[Shader Library] Shader already exits!");
		Shaders[Name] = InShader;
	}

	void UShaderLibrary::Load(std::string_view InName, const std::string& InPath)
	{
		EXCITED_CORE_ASSERT(Shaders.find(std::string(InName)) == Shaders.end(), "[Shader Library] Shader not find!");
		Shaders[std::string(InName)] = IShader::CreateShader(InPath);
	}

	const TRef<IShader>& UShaderLibrary::Get(const std::string& InName) const
	{

	}
}