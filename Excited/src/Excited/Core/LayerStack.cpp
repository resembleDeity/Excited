// (C) Copyright Kirito 2024

#include "excitedpch.h"
#include "LayerStack.h"

namespace Excited
{
	FLayerStack::FLayerStack()
	{ }

	FLayerStack::~FLayerStack()
	{ }

	void FLayerStack::PushLayer(ILayer* InLayer)
	{
		Layers.emplace(Layers.begin() + LayerInsertIndex, InLayer);
		LayerInsertIndex++;
	}

	void FLayerStack::PushOverlay(ILayer* InOverlay)
	{
		Layers.emplace_back(InOverlay);
	}

	void FLayerStack::PopLayer(ILayer* InLayer)
	{
		auto It = std::find(Layers.begin(), Layers.end(), InLayer);
		if (It != Layers.end())
		{
			Layers.erase(It);
			LayerInsertIndex--;
		}
	}

	void FLayerStack::PopOverlay(ILayer* InOverlay)
	{
		auto It = std::find(Layers.begin(), Layers.end(), InOverlay);
		if (It != Layers.end())
		{
			Layers.erase(It);
		}
	}
}