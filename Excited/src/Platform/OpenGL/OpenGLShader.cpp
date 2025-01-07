// (C) Copyright Kirito 2025

#include "excitedpch.h"
#include "OpenGLShader.h"

#include <fstream>

#include <glad/glad.h>

namespace Excited
{
	namespace Utils
	{
		static GLenum ShaderTypeFromString(std::string_view InType)
		{
			if (InType == "Vertex" || InType == "vertex")
			{
				return GL_VERTEX_SHADER;
			}

			if (InType == "Fragment" || InType == "fragment" || InType == "Pixel" || InType == "pixel")
			{
				return GL_FRAGMENT_SHADER;
			}

			EXCITED_CORE_ASSERT(false, "[Shader] Unknown shader type!");
			return 0;
		}

		static const char* GLShaderStageToString(GLenum InStage)
		{
			switch (InStage)
			{
				case GL_VERTEX_SHADER: return "GL_VERTEX_SHADER";
				case GL_FRAGMENT_SHADER: return "GL_FRAGMENT_SHADER";
			}

			EXCITED_CORE_ASSERT(false, "[Shader] Unknow shader stage!");
			return nullptr;
		}

		static const char* GetCacheDirectory()
		{
			return "Assets/Cache/Shaders/OpenGL";
		}

		static void CreateCacheDirectoryIfNeeded()
		{
			std::string_view CacheDirectory = GetCacheDirectory();
			if (!std::filesystem::exists(CacheDirectory))
			{
				std::filesystem::create_directories(CacheDirectory);
			}
		}

		static const char* GLShaderStageCachedOpenGLFileExtension(uint32_t InStage)
		{
			switch (InStage)
			{
				case GL_VERTEX_SHADER:		return ".cached_opengl.vert";
				case GL_FRAGMENT_SHADER:	return ".cached_opengl_frag";
			}

			EXCITED_CORE_ASSERT(false, "[Shader] Unknow shader stage!");
			return "";
		}

		static const char* GLShaderStageCachedVulkanFileExtension(uint32_t InStage)
		{
			switch (InStage)
			{
			case GL_VERTEX_SHADER:		return ".cached_vulkan.vert";
			case GL_FRAGMENT_SHADER:	return ".cached_vulkan.frag";
			}

			EXCITED_CORE_ASSERT(false, "[Shader] Unknow shader stage!");
			return "";
		}
	}

	FOpenGLShader::FOpenGLShader(const std::string& InFilePath)
		: AssetPath(InFilePath)
	{
		Utils::CreateCacheDirectoryIfNeeded();

		std::string_view Source = ReadFile(InFilePath);

		size_t Found = InFilePath.find_last_of("/\\");
		Name = Found != std::string::npos ? InFilePath.substr(Found + 1) : InFilePath;
		Found = Name.find_last_of('.');
		Name = Found != std::string::npos ? Name.substr(0, Found) : Name;


	}

	FOpenGLShader::FOpenGLShader(const std::string& InName, const std::string& InVertexSrc, const std::string& InFragmentSrc)
	{

	}

	FOpenGLShader::~FOpenGLShader()
	{

	}

	void FOpenGLShader::Bind() const
	{
		glUseProgram(RendererID);
	}

	void FOpenGLShader::Unbind() const
	{
		glUseProgram(0);
	}
}