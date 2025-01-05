// (C) Copyright Kirito 2025

#include "excitedpch.h"
#include "Excited/Core/Input.h"
#include "Window.h"

#include "Excited/Core/Application.h"

#include <GLFW/glfw3.h>
#include <imgui_internal.h>

namespace Excited
{
	void FInput::Update()
	{

	}

	bool FInput::IsKeyPressed(EKeyCode InKeyCode)
	{
		return KeyDatas.find(InKeyCode) != KeyDatas.end() && KeyDatas[InKeyCode].State == EKeyState::Pressed;
	}

	bool FInput::IsKeyHeld(EKeyCode InKeyCode)
	{
		return KeyDatas.find(InKeyCode) != KeyDatas.end() && KeyDatas[InKeyCode].State == EKeyState::Held;
	}

	bool FInput::IsKeyDown(EKeyCode InKeyCode)
	{
		return false;
	}

	bool FInput::IsKeyReleased(EKeyCode InKeyCode)
	{
		return KeyDatas.find(InKeyCode) != KeyDatas.end() && KeyDatas[InKeyCode].State == EKeyState::Released;
	}

	bool FInput::IsMouseButtonPressed(EMouseButton InButton)
	{
		return MouseDatas.find(InButton) != MouseDatas.end() && MouseDatas[InButton].State == EKeyState::Pressed;
	}

	bool FInput::IsMouseButtonHeld(EMouseButton InButton)
	{
		return MouseDatas.find(InButton) != MouseDatas.end() && MouseDatas[InButton].State == EKeyState::Held;
	}

	bool FInput::IsMouseButtonDown(EMouseButton InButton)
	{ 
		return false;
	}

	bool FInput::IsMouseButtonReleased(EMouseButton InButton)
	{
		return MouseDatas.find(InButton) != MouseDatas.end() && MouseDatas[InButton].State == EKeyState::Released;
	}

	float FInput::GetMouseX()
	{
		auto [X, Y] = GetMousePosition();
		return (float)X;
	}

	float FInput::GetMouseY()
	{
		auto [X, Y] = GetMousePosition();
		return (float)Y;
	}

	std::pair<float, float> FInput::GetMousePosition()
	{
		auto& Window = static_cast<FWindow&>(IApplication::GetInstance().GetWindow());

		double X, Y;
		glfwGetCursorPos(static_cast<GLFWwindow*>(Window.GetNativeWindow()), &X, &Y);
		return { (float)X, (float)Y };
	}

	void FInput::SetCursorMode(ECursorMode InCursorMode)
	{
		auto& Window = static_cast<FWindow&>(IApplication::GetInstance().GetWindow());
		glfwSetInputMode(static_cast<GLFWwindow*>(Window.GetNativeWindow()), GLFW_CURSOR, GLFW_CURSOR_NORMAL + (int)InCursorMode);
	}

	Excited::ECursorMode FInput::GetCursorMode()
	{
		auto& Window = static_cast<FWindow&>(IApplication::GetInstance().GetWindow());
		return (ECursorMode)(glfwGetInputMode(static_cast<GLFWwindow*>(Window.GetNativeWindow()), GLFW_CURSOR) - GLFW_CURSOR_NORMAL);
	}

	void FInput::UpdateKeyState(EKeyCode InKey, EKeyState InNewState)
	{
		FKeyData& KeyData = KeyDatas[InKey];
		KeyData.Key = InKey;
		KeyData.OldState = KeyData.State;
		KeyData.State = InNewState;
	}

	void FInput::UpdateButtonState(EMouseButton InButton, EKeyState InNewState)
	{
		FButtonData& MouseData = MouseDatas[InButton];
		MouseData.Button = InButton;
		MouseData.OldState = MouseData.State;
		MouseData.State = InNewState;
	}

	void FInput::ClearReleasedKeys()
	{
		for (const auto& [Key, KeyData] : KeyDatas)
		{
			if (KeyData.State == EKeyState::Released)
			{
				UpdateKeyState(Key, EKeyState::None);
			}
		}

		for (const auto& [Button, ButtonData] : MouseDatas)
		{
			if (ButtonData.State == EKeyState::Released)
			{
				UpdateButtonState(Button, EKeyState::None);
			}
		}
	}
}