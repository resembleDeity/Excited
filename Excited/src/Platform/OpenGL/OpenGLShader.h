// (C) Copyright Kirito 2025

#pragma once

#include "Excited/Renderer/Shader.h"

namespace Excited
{
	class FOpenGLShader : public IShader
	{
	public:

		FOpenGLShader() = default;
		FOpenGLShader(const std::string& InFilePath);
		FOpenGLShader(const std::string& InName, const std::string& InVertexSrc, const std::string& InFragmentSrc);
		virtual ~FOpenGLShader();

		virtual void Bind() const override;
		virtual void Unbind() const override;

		virtual const std::string& GetName() const override { return Name; }

	private:

		uint32_t RendererID;

		std::filesystem::path AssetPath;
		std::string Name;
	};
}