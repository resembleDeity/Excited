// (C) Copyright Kirito 2025

#pragma once

#include "Vulkan.h"

struct GLFWwindow;

namespace Excited
{
	class FVulkanSwapChain
	{
	public:

		void Init(VkInstance InInstance);

		void Create(uint32_t* InWidth, uint32_t* InHeight, bool InbVSync);
		void Destory();

		void OnResize(uint32_t InWidht, uint32_t InHeight);
	};
}