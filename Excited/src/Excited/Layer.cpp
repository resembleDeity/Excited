// (C) Copyright Kirito 2024

#include "excitedpch.h"
#include "Layer.h"

namespace Excited
{
	ILayer::ILayer(const std::string& InName)
		: DebugName(InName)
	{ }

	ILayer::~ILayer()
	{ }
}