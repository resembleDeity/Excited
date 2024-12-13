// (C) Copyright Kirito 2024

#include "excitedpch.h"
#include "LayerStack.h"

namespace Excited
{
	FLayerStack::FLayerStack()
	{
		LayerInsert = Layers.begin();
	}

	FLayerStack::~FLayerStack()
	{
		for (ILayer* Layer : Layers)
		{
			delete Layer;
		}
	}

	void FLayerStack::PushLayer(ILayer* InLayer)
	{
		LayerInsert = Layers.emplace(LayerInsert, InLayer);
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
			LayerInsert--;
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