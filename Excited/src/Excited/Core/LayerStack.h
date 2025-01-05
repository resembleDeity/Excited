// (C) Copyright Kirito 2024

#pragma once

#include "Assert.h"
#include "Layer.h"

#include <vector>

namespace Excited
{
	class FLayerStack
	{
	public:

		FLayerStack();
		~FLayerStack();

		size_t Size() { return Layers.size(); }

		void PushLayer(ILayer* InLayer);
		void PushOverlay(ILayer* InOverlay);
		void PopLayer(ILayer* InLayer);
		void PopOverlay(ILayer* InOverlay);

		ILayer* operator[](size_t InIndex)
		{
			EXCITED_CORE_ASSERT(InIndex >= 0 && InIndex < Layers.size(), "LayerStack: Index Error!");
			return Layers[InIndex];
		}

		const ILayer* operator[](size_t InIndex) const
		{
			EXCITED_CORE_ASSERT(InIndex >= 0 && InIndex < Layers.size(), "LayerStack: Index Error!");
			return Layers[InIndex];
		}

		std::vector<ILayer*>::iterator begin() { return Layers.begin(); }
		std::vector<ILayer*>::iterator end() { return Layers.end(); }

	private:

		std::vector<ILayer*> Layers;
		unsigned int LayerInsertIndex = 0;
	};
}