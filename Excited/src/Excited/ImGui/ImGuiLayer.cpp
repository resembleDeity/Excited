// (C) Copyright Kirito 2024

#include "excitedpch.h"
#include "ImGuiLayer.h"

#include "Colors.h"

#include "Excited/Renderer/RendererAPI.h"
#include "Platform/OpenGL/OpenGLImGuiLayer.h"

#include <imgui.h>

namespace Excited
{
	void IImGuiLayer::SetDarkThemeColors()
	{
		auto& Colors = ImGui::GetStyle().Colors;
		Colors[ImGuiCol_WindowBg] = ImVec4{ 0.1f, 0.105f, 0.11f, 1.0f };

		//Headers
		Colors[ImGuiCol_Header] = ImVec4{ 0.2f, 0.205f, 0.21f, 1.0f };
		Colors[ImGuiCol_HeaderHovered] = ImVec4{ 0.3f, 0.305f, 0.31f, 1.0f };
		Colors[ImGuiCol_HeaderActive] = ImVec4{ 0.15f, 0.1505f, 0.151f, 1.0f };

		// Buttons
		Colors[ImGuiCol_Button] = ImVec4{ 0.2f, 0.205f, 0.21f, 1.0f };
		Colors[ImGuiCol_ButtonHovered] = ImVec4{ 0.3f, 0.305f, 0.31f, 1.0f };
		Colors[ImGuiCol_ButtonActive] = ImVec4{ 0.15f, 0.1505f, 0.151f, 1.0f };

		// Frame Background
		Colors[ImGuiCol_FrameBg] = ImVec4{ 0.2f, 0.205f, 0.21f, 1.0f };
		Colors[ImGuiCol_FrameBgHovered] = ImVec4{ 0.3f, 0.305f, 0.31f, 1.0f };
		Colors[ImGuiCol_FrameBgActive] = ImVec4{ 0.15f, 0.1505f, 0.151f, 1.0f };

		// Tabs
		Colors[ImGuiCol_Tab] = ImVec4{ 0.15f, 0.1505f, 0.151f, 1.0f };
		Colors[ImGuiCol_TabHovered] = ImVec4{ 0.38f, 0.3805f, 0.381f, 1.0f };
		Colors[ImGuiCol_TabActive] = ImVec4{ 0.28f, 0.2805f, 0.281f, 1.0f };
		Colors[ImGuiCol_TabUnfocused] = ImVec4{ 0.15f, 0.1505f, 0.151f, 1.0f };
		Colors[ImGuiCol_TabUnfocusedActive] = ImVec4{ 0.2f, 0.205f, 0.21f, 1.0f };

		// Title
		Colors[ImGuiCol_TitleBg] = ImVec4{ 0.15f, 0.1505f, 0.151f, 1.0f };
		Colors[ImGuiCol_TitleBgActive] = ImVec4{ 0.15f, 0.1505f, 0.151f, 1.0f };
		Colors[ImGuiCol_TitleBgCollapsed] = ImVec4{ 0.15f, 0.1505f, 0.151f, 1.0f };

		// Resize Grip
		Colors[ImGuiCol_ResizeGrip] = ImVec4(0.91f, 0.91f, 0.91f, 0.25f);
		Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.81f, 0.81f, 0.81f, 0.67f);
		Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.46f, 0.46f, 0.46f, 0.95f);

		// Scroll Bar
		Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.02f, 0.02f, 0.02f, 0.53f);
		Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.31f, 0.31f, 0.31f, 1.0f);
		Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.41f, 0.41f, 0.41f, 1.0f);
		Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.51f, 0.51f, 0.51f, 1.0f);

		// Check Mark
		Colors[ImGuiCol_CheckMark] = ImVec4(0.94f, 0.94f, 0.94f, 1.0f);

		// Slider
		Colors[ImGuiCol_SliderGrab] = ImVec4(0.51f, 0.51f, 0.51f, 0.7f);
		Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.66f, 0.66f, 0.66f, 1.0f);
	}

	void IImGuiLayer::SetDarkThemeV2Colors()
	{
		auto& Style = ImGui::GetStyle();
		auto& Colors = ImGui::GetStyle().Colors;

		//=============================================
		/// Colours

		// Headers
		Colors[ImGuiCol_Header]					= ImGui::ColorConvertU32ToFloat4(FColors::FTheme::GroupHeader);
		Colors[ImGuiCol_HeaderHovered]			= ImGui::ColorConvertU32ToFloat4(FColors::FTheme::GroupHeader);
		Colors[ImGuiCol_HeaderActive]			= ImGui::ColorConvertU32ToFloat4(FColors::FTheme::GroupHeader);

		// Buttons
		Colors[ImGuiCol_Button]					= ImColor(56, 56, 56, 200);
		Colors[ImGuiCol_ButtonHovered]			= ImColor(70, 70, 70, 255);
		Colors[ImGuiCol_ButtonActive]			= ImColor(56, 56, 56, 150);

		// Frame Background
		Colors[ImGuiCol_FrameBg]				= ImGui::ColorConvertU32ToFloat4(FColors::FTheme::PropertyField);
		Colors[ImGuiCol_FrameBgHovered]			= ImGui::ColorConvertU32ToFloat4(FColors::FTheme::PropertyField);
		Colors[ImGuiCol_FrameBgActive]			= ImGui::ColorConvertU32ToFloat4(FColors::FTheme::PropertyField);

		// Tabs
		Colors[ImGuiCol_Tab]					= ImGui::ColorConvertU32ToFloat4(FColors::FTheme::TitleBar);
		Colors[ImGuiCol_TabHovered]				= ImColor(255, 225, 135, 30);
		Colors[ImGuiCol_TabActive]				= ImColor(255, 225, 135, 60);
		Colors[ImGuiCol_TabUnfocused]			= ImGui::ColorConvertU32ToFloat4(FColors::FTheme::TitleBar);
		Colors[ImGuiCol_TabUnfocusedActive]		= Colors[ImGuiCol_TabHovered];

		// Title
		Colors[ImGuiCol_TitleBg]				= ImGui::ColorConvertU32ToFloat4(FColors::FTheme::TitleBar);
		Colors[ImGuiCol_TitleBgActive]			= ImGui::ColorConvertU32ToFloat4(FColors::FTheme::TitleBar);
		Colors[ImGuiCol_TitleBgCollapsed]		= ImVec4{ 0.15f, 0.1505f, 0.151f, 1.0f };

		// Resize Grip
		Colors[ImGuiCol_ResizeGrip]				= ImVec4(0.91f, 0.91f, 0.91f, 0.25f);
		Colors[ImGuiCol_ResizeGripHovered]		= ImVec4(0.81f, 0.81f, 0.81f, 0.67f);
		Colors[ImGuiCol_ResizeGripActive]		= ImVec4(0.46f, 0.46f, 0.46f, 0.95f);

		// Scroll Bar
		Colors[ImGuiCol_ScrollbarBg]			= ImVec4(0.02f, 0.02f, 0.02f, 0.53f);
		Colors[ImGuiCol_ScrollbarGrab]			= ImVec4(0.31f, 0.31f, 0.31f, 1.0f);
		Colors[ImGuiCol_ScrollbarGrabHovered]	= ImVec4(0.41f, 0.41f, 0.41f, 1.0f);
		Colors[ImGuiCol_ScrollbarGrabActive]	= ImVec4(0.51f, 0.51f, 0.51f, 1.0f);

		// Check Mark
		Colors[ImGuiCol_CheckMark]				= ImColor(200, 200, 200, 255);

		// Slider
		Colors[ImGuiCol_SliderGrab]				= ImVec4(0.51f, 0.51f, 0.51f, 0.7f);
		Colors[ImGuiCol_SliderGrabActive]		= ImVec4(0.66f, 0.66f, 0.66f, 1.0f);

		// Text
		Colors[ImGuiCol_Text]					= ImGui::ColorConvertU32ToFloat4(FColors::FTheme::Text);

		// Check Box
		Colors[ImGuiCol_CheckMark]				= ImGui::ColorConvertU32ToFloat4(FColors::FTheme::Text);

		// Separator
		Colors[ImGuiCol_Separator]				= ImGui::ColorConvertU32ToFloat4(FColors::FTheme::BackgroundDark);
		Colors[ImGuiCol_SeparatorActive]		= ImGui::ColorConvertU32ToFloat4(FColors::FTheme::HighLight);
		Colors[ImGuiCol_SeparatorHovered]		= ImColor(39, 185, 242, 150);

		// Window Background
		Colors[ImGuiCol_WindowBg]				= ImGui::ColorConvertU32ToFloat4(FColors::FTheme::TitleBar);
		Colors[ImGuiCol_ChildBg]				= ImGui::ColorConvertU32ToFloat4(FColors::FTheme::Background);
		Colors[ImGuiCol_PopupBg]				= ImGui::ColorConvertU32ToFloat4(FColors::FTheme::BackgroundPopup);
		Colors[ImGuiCol_Border]					= ImGui::ColorConvertU32ToFloat4(FColors::FTheme::BackgroundDark);

		// Tables
		Colors[ImGuiCol_TableHeaderBg]			= ImGui::ColorConvertU32ToFloat4(FColors::FTheme::GroupHeader);
		Colors[ImGuiCol_TableBorderLight]		= ImGui::ColorConvertU32ToFloat4(FColors::FTheme::BackgroundDark);

		// Menu Bar
		Colors[ImGuiCol_MenuBarBg]				= ImVec4{ 0.0f, 0.0f, 0.0f, 0.0f };

		//=============================================
		/// Style
		Style.FrameRounding = 2.5f;
		Style.FrameBorderSize = 1.0f;
		Style.IndentSpacing = 11.0f;
	}

	void IImGuiLayer::AllowInputEvents(bool InbAllowEvents)
	{

	}

	IImGuiLayer* IImGuiLayer::CreateImGuiLayer()
	{
		switch (IRendererAPI::GetCurrentAPI())
		{
			case ERendererAPIType::None: return nullptr;
			case ERendererAPIType::OpenGL: return new FOpenGLImGuiLayer();
			case ERendererAPIType::Vulkan: return nullptr;
		}

		EXCITED_CORE_ASSERT(false, "Unknown RendererAPI");
		return nullptr;
	}
}