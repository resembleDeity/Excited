// (C) Copyright Kirito 2025

#include "excitedpch.h"
#include "OpenGLRendererAPI.h"

#include <glad/glad.h>

namespace Excited
{
	void OpenGLMessageCallback(
		unsigned InSource, unsigned InType, unsigned InID, unsigned InSeverity,
		int InLength, const char* InMessage, const void* InUserParam)
	{
		switch (InSeverity)
		{
			case GL_DEBUG_SEVERITY_HIGH:			EXCITED_CORE_CRITICAL(InMessage); return;
			case GL_DEBUG_SEVERITY_MEDIUM:			EXCITED_CORE_ERROR(InMessage); return;
			case GL_DEBUG_SEVERITY_LOW:				EXCITED_CORE_WARN(InMessage); return;
			case GL_DEBUG_SEVERITY_NOTIFICATION:	EXCITED_CORE_TRACE(InMessage); return;
		}

		EXCITED_CORE_ASSERT(false, "Unknown severity level!");
	}

	void FOpenGLRendererAPI::Init()
	{
	#ifdef EXCITED_DEBUG
		glEnable(GL_DEBUG_OUTPUT);
		glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
		glDebugMessageCallback(OpenGLMessageCallback, nullptr);

		glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DEBUG_SEVERITY_NOTIFICATION, 0, NULL, GL_FALSE);
	#endif

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glEnable(GL_DEPTH_TEST);
		glEnable(GL_LINE_SMOOTH);
	}

	void FOpenGLRendererAPI::SetViewport(uint32_t InX, uint32_t InY, uint32_t InWidth, uint32_t InHeight)
	{
		glViewport(InX, InY, InWidth, InHeight);
	}

	void FOpenGLRendererAPI::SetClearColor(const glm::vec4& InColor)
	{
		glClearColor(InColor.r, InColor.g, InColor.b, InColor.a);
	}

	void FOpenGLRendererAPI::Clear()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}
}