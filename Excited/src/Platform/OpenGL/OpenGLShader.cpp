// (C) Copyright Kirito 2025

#include "excitedpch.h"
#include "OpenGLShader.h"

#include <glad/glad.h>

namespace Excited
{

	FOpenGLShader::FOpenGLShader(const std::string& InFilePath)
	{
		size_t Found = InFilePath.find_last_of("/\\");
		Name = Found != std::string::npos ? InFilePath.substr(Found + 1) : InFilePath;
		Found = Name.find_last_of('.');
		Name = Found != std::string::npos ? Name.substr(0, Found) : Name;


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