// (C) Copyright Kirito 2024

#pragma once

#include "Excited/Core.h"
#include "Layer.h"

#include <vector>

namespace Excited
{
	class FLayerStack
	{
	public:

		FLayerStack();
		~FLayerStack();

		void PushLayer(ILayer* InLayer);
		void PushOverlay(ILayer* InOverlay);
		void PopLayer(ILayer* InLayer);
		void PopOverlay(ILayer* InOverlay);

		std::vector<ILayer*>::iterator begin() { return Layers.begin(); }
		std::vector<ILayer*>::iterator end() { return Layers.end(); }

	private:

		std::vector<ILayer*> Layers;
		std::vector<ILayer*>::iterator LayerInsert;
	};
}