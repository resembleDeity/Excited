// (C) Copyright Kirito 2025

#pragma once

#include <imgui.h>

namespace Excited
{
	namespace FColors
	{
		static inline float ConvertSRGBFromLinear(float InLinearValue);
		static inline float ConvertSRGBToLinear(float InSRGBValue);
		ImVec4 ConvertFromSRGB(ImVec4 InColour);
		ImVec4 ConvertToSRGB(ImVec4 InColour);

		namespace FTheme
		{
			constexpr auto Accent			= IM_COL32(236, 158, 36, 255);
			constexpr auto HighLight		= IM_COL32(39, 185, 242, 255);
			constexpr auto NiceBlue			= IM_COL32(83, 232, 254, 255);
			constexpr auto Compliment		= IM_COL32(78, 151, 166, 255);
			constexpr auto Background		= IM_COL32(36, 36, 36, 255);
			constexpr auto BackgroundDark	= IM_COL32(26, 26, 26, 255);
			constexpr auto TitleBar			= IM_COL32(21, 21, 21, 255);
			constexpr auto TitleBarOrange	= IM_COL32(186, 66, 30, 255);
			constexpr auto TitleBarGreen	= IM_COL32(18, 88, 30, 255);
			constexpr auto TitleBarRed		= IM_COL32(185, 30, 30, 255);
			constexpr auto PropertyField	= IM_COL32(15, 15, 15, 255);
			constexpr auto Text				= IM_COL32(192, 192, 192, 255);
			constexpr auto TextBrighter		= IM_COL32(210, 210, 210, 255);
			constexpr auto TextDarker		= IM_COL32(128, 128, 128, 255);
			constexpr auto TextError		= IM_COL32(230, 51, 51, 255);
			constexpr auto Muted			= IM_COL32(77, 77, 77, 255);
			constexpr auto GroupHeader		= IM_COL32(47, 47, 47, 255);
			constexpr auto Selection		= IM_COL32(237, 192, 119, 255);
			constexpr auto SelectionMuted	= IM_COL32(237, 201, 142, 23);
			constexpr auto BackgroundPopup	= IM_COL32(50, 50, 50, 255);
			constexpr auto ValidPrefab		= IM_COL32(82, 179, 222, 255);
			constexpr auto InvalidPrefab	= IM_COL32(222, 43, 43, 255);
			constexpr auto MissingMesh		= IM_COL32(230, 102, 76, 255);
			constexpr auto MeshNotSet		= IM_COL32(250, 101, 23, 255);
		}
	}
}