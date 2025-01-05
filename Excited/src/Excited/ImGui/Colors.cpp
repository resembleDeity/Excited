// (C) Copyright Kirito 2025

#include "excitedpch.h"
#include "Colors.h"

namespace Excited
{
	namespace FColors
	{
		static inline float ConvertSRGBFromLinear(float InLinearValue)
		{
			return 
				InLinearValue <= 0.0031308f ? 
				InLinearValue * 12.92f : 
				powf(InLinearValue, 1.0f / 2.2f) * 1.055f - 0.055f;
		}

		static inline float ConvertSRGBToLinear(float InSRGBValue)
		{
			return 
				InSRGBValue <= 0.04045f ? 
				InSRGBValue / 12.92f :
				powf((InSRGBValue + 0.055f) / 1.055f, 2.2f);
		}

		ImVec4 ConvertFromSRGB(ImVec4 InColour)
		{
			return ImVec4
			(
				ConvertSRGBFromLinear(InColour.x),
				ConvertSRGBFromLinear(InColour.y),
				ConvertSRGBFromLinear(InColour.z),
				InColour.w
			);
		}

		ImVec4 ConvertToSRGB(ImVec4 InColour)
		{
			return ImVec4
			(
				std::pow(InColour.x, 2.2f),
				std::pow(InColour.y, 2.2f),
				std::pow(InColour.z, 2.2f),
				InColour.w
			);
		}
	}
}