// (C) Copyright Kirito 2025

#pragma once

#include "KeyCodes.h"

namespace Excited
{
	struct FKeyData
	{
		EKeyCode Key;
		EKeyState State = EKeyState::None;
		EKeyState OldState = EKeyState::None;
	};

	struct FButtonData
	{
		EMouseButton Button;
		EKeyState State = EKeyState::None;
		EKeyState OldState = EKeyState::None;
	};

	class FInput
	{
	public:

		static void Update();

		static bool IsKeyPressed(EKeyCode InKeyCode);
		static bool IsKeyHeld(EKeyCode InKeyCode);
		static bool IsKeyDown(EKeyCode InKeyCode);
		static bool IsKeyReleased(EKeyCode InKeyCode);

		static bool IsMouseButtonPressed(EMouseButton InButton);
		static bool IsMouseButtonHeld(EMouseButton InButton);
		static bool IsMouseButtonDown(EMouseButton InButton);
		static bool IsMouseButtonReleased(EMouseButton InButton);

		static float GetMouseX();
		static float GetMouseY();
		static std::pair<float, float> GetMousePosition();

		static void SetCursorMode(ECursorMode InCursorMode);
		static ECursorMode GetCursorMode();

		static void UpdateKeyState(EKeyCode InKey, EKeyState InNewState);
		static void UpdateButtonState(EMouseButton InButton, EKeyState InNewState);
		static void ClearReleasedKeys();

	private:

		static inline std::map<EKeyCode, FKeyData> KeyDatas;
		static inline std::map<EMouseButton, FButtonData> MouseDatas;
	};
}