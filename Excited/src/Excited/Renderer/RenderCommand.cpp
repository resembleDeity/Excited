// (C) Copyright Kirito 2025

#include "excitedpch.h"
#include "RenderCommand.h"

namespace Excited
{
	TScope<IRendererAPI> IRenderCommand::RendererAPI = IRendererAPI::CreateRenderer();
}