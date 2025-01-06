// (C) Copyright Kirito 2025

#pragma once

#include "Excited/Core/Core.h"

#include <glm/glm.hpp>

#include <filesystem>

namespace Excited
{
	struct FTextureSpecification
	{
		uint32_t Width = 1;
		uint32_t Height = 1;

		bool GenerateMips = true;
		bool Storage = false;
		bool StoreLocally = false;

		std::string DebugName;
	};

	class ITexture
	{
	public:

		virtual ~ITexture() { }

		virtual void Bind(uint32_t InSlot = 0) const = 0;

		virtual uint32_t GetWidth() const = 0;
		virtual uint32_t GetHeight() const = 0;
		virtual glm::uvec2 GetSize() const = 0;
	};
}