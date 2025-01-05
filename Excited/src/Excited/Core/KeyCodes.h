// (C) Copyright Kirito 2025

#pragma once

namespace Excited
{
	enum class EKeyCode : uint16_t
	{
		// From glfw3.h
		Space = 32,
		Apostrophe = 39, /* ' */
		Comma = 44, /* , */
		Minus = 45, /* - */
		Period = 46, /* . */
		Slash = 47, /* / */

		D0 = 48, /* 0 */
		D1 = 49, /* 1 */
		D2 = 50, /* 2 */
		D3 = 51, /* 3 */
		D4 = 52, /* 4 */
		D5 = 53, /* 5 */
		D6 = 54, /* 6 */
		D7 = 55, /* 7 */
		D8 = 56, /* 8 */
		D9 = 57, /* 9 */

		Semicolon = 59, /* ; */
		Equal = 61, /* = */

		A = 65,
		B = 66,
		C = 67,
		D = 68,
		E = 69,
		F = 70,
		G = 71,
		H = 72,
		I = 73,
		J = 74,
		K = 75,
		L = 76,
		M = 77,
		N = 78,
		O = 79,
		P = 80,
		Q = 81,
		R = 82,
		S = 83,
		T = 84,
		U = 85,
		V = 86,
		W = 87,
		X = 88,
		Y = 89,
		Z = 90,

		LeftBracket = 91,  /* [ */
		Backslash = 92,  /* \ */
		RightBracket = 93,  /* ] */
		GraveAccent = 96,  /* ` */

		World1 = 161, /* non-US #1 */
		World2 = 162, /* non-US #2 */

		/* Function keys */
		Escape = 256,
		Enter = 257,
		Tab = 258,
		Backspace = 259,
		Insert = 260,
		Delete = 261,
		Right = 262,
		Left = 263,
		Down = 264,
		Up = 265,
		PageUp = 266,
		PageDown = 267,
		Home = 268,
		End = 269,
		CapsLock = 280,
		ScrollLock = 281,
		NumLock = 282,
		PrintScreen = 283,
		Pause = 284,
		F1 = 290,
		F2 = 291,
		F3 = 292,
		F4 = 293,
		F5 = 294,
		F6 = 295,
		F7 = 296,
		F8 = 297,
		F9 = 298,
		F10 = 299,
		F11 = 300,
		F12 = 301,
		F13 = 302,
		F14 = 303,
		F15 = 304,
		F16 = 305,
		F17 = 306,
		F18 = 307,
		F19 = 308,
		F20 = 309,
		F21 = 310,
		F22 = 311,
		F23 = 312,
		F24 = 313,
		F25 = 314,

		/* Keypad */
		KP0 = 320,
		KP1 = 321,
		KP2 = 322,
		KP3 = 323,
		KP4 = 324,
		KP5 = 325,
		KP6 = 326,
		KP7 = 327,
		KP8 = 328,
		KP9 = 329,
		KPDecimal = 330,
		KPDivide = 331,
		KPMultiply = 332,
		KPSubtract = 333,
		KPAdd = 334,
		KPEnter = 335,
		KPEqual = 336,

		LeftShift = 340,
		LeftControl = 341,
		LeftAlt = 342,
		LeftSuper = 343,
		RightShift = 344,
		RightControl = 345,
		RightAlt = 346,
		RightSuper = 347,
		Menu = 348
	};

	enum class EKeyState
	{
		None = -1,
		Pressed,
		Held,
		Released,
	};

	enum class ECursorMode
	{
		Normal = 0,
		Hidden = 1,
		Locked = 2,
	};

	enum class EMouseButton : uint16_t
	{
		Button0 = 0,
		Button1 = 1,
		Button2 = 2,
		Button3 = 3,
		Button4 = 4,
		Button5 = 5,
		Left = Button0,
		Right = Button1,
		Middle = Button2
	};

	inline std::ostream& operator<<(std::ostream& InOS, EKeyCode InKeyCode)
	{
		InOS << static_cast<int32_t>(InKeyCode);
		return InOS;
	}

	inline std::ostream& operator<<(std::ostream& InOS, EMouseButton InButton)
	{
		InOS << static_cast<int32_t>(InButton);
		return InOS;
	}

	inline std::string format_as(EKeyCode InKeyCode)
	{
		std::stringstream StrStream;
		StrStream << "[Input] Key Code: " << static_cast<char>(InKeyCode) << " ()" << InKeyCode;
		return StrStream.str();
	}

	inline std::string format_as(EMouseButton InButton)
	{
		std::stringstream StrStream;
		StrStream << "[Input] Mouse Button: " << static_cast<char>(InButton) << " ()" << InButton;
		return StrStream.str();
	}
}

// From glfw3.h
#define EXCITED_KEY_SPACE           ::Excited::EKeyCode::Space
#define EXCITED_KEY_APOSTROPHE      ::Excited::EKeyCode::Apostrophe    /* ' */
#define EXCITED_KEY_COMMA           ::Excited::EKeyCode::Comma         /* , */
#define EXCITED_KEY_MINUS           ::Excited::EKeyCode::Minus         /* - */
#define EXCITED_KEY_PERIOD          ::Excited::EKeyCode::Period        /* . */
#define EXCITED_KEY_SLASH           ::Excited::EKeyCode::Slash         /* / */
#define EXCITED_KEY_0               ::Excited::EKeyCode::D0
#define EXCITED_KEY_1               ::Excited::EKeyCode::D1
#define EXCITED_KEY_2               ::Excited::EKeyCode::D2
#define EXCITED_KEY_3               ::Excited::EKeyCode::D3
#define EXCITED_KEY_4               ::Excited::EKeyCode::D4
#define EXCITED_KEY_5               ::Excited::EKeyCode::D5
#define EXCITED_KEY_6               ::Excited::EKeyCode::D6
#define EXCITED_KEY_7               ::Excited::EKeyCode::D7
#define EXCITED_KEY_8               ::Excited::EKeyCode::D8
#define EXCITED_KEY_9               ::Excited::EKeyCode::D9
#define EXCITED_KEY_SEMICOLON       ::Excited::EKeyCode::Semicolon     /* ; */
#define EXCITED_KEY_EQUAL           ::Excited::EKeyCode::Equal         /* = */
#define EXCITED_KEY_A               ::Excited::EKeyCode::A
#define EXCITED_KEY_B               ::Excited::EKeyCode::B
#define EXCITED_KEY_C               ::Excited::EKeyCode::C
#define EXCITED_KEY_D               ::Excited::EKeyCode::D
#define EXCITED_KEY_E               ::Excited::EKeyCode::E
#define EXCITED_KEY_F               ::Excited::EKeyCode::F
#define EXCITED_KEY_G               ::Excited::EKeyCode::G
#define EXCITED_KEY_H               ::Excited::EKeyCode::H
#define EXCITED_KEY_I               ::Excited::EKeyCode::I
#define EXCITED_KEY_J               ::Excited::EKeyCode::J
#define EXCITED_KEY_K               ::Excited::EKeyCode::K
#define EXCITED_KEY_L               ::Excited::EKeyCode::L
#define EXCITED_KEY_M               ::Excited::EKeyCode::M
#define EXCITED_KEY_N               ::Excited::EKeyCode::N
#define EXCITED_KEY_O               ::Excited::EKeyCode::O
#define EXCITED_KEY_P               ::Excited::EKeyCode::P
#define EXCITED_KEY_Q               ::Excited::EKeyCode::Q
#define EXCITED_KEY_R               ::Excited::EKeyCode::R
#define EXCITED_KEY_S               ::Excited::EKeyCode::S
#define EXCITED_KEY_T               ::Excited::EKeyCode::T
#define EXCITED_KEY_U               ::Excited::EKeyCode::U
#define EXCITED_KEY_V               ::Excited::EKeyCode::V
#define EXCITED_KEY_W               ::Excited::EKeyCode::W
#define EXCITED_KEY_X               ::Excited::EKeyCode::X
#define EXCITED_KEY_Y               ::Excited::EKeyCode::Y
#define EXCITED_KEY_Z               ::Excited::EKeyCode::Z
#define EXCITED_KEY_LEFT_BRACKET    ::Excited::EKeyCode::LeftBracket   /* [ */
#define EXCITED_KEY_BACKSLASH       ::Excited::EKeyCode::Backslash     /* \ */
#define EXCITED_KEY_RIGHT_BRACKET   ::Excited::EKeyCode::RightBracket  /* ] */
#define EXCITED_KEY_GRAVE_ACCENT    ::Excited::EKeyCode::GraveAccent   /* ` */
#define EXCITED_KEY_WORLD_1         ::Excited::EKeyCode::World1        /* non-US #1 */
#define EXCITED_KEY_WORLD_2         ::Excited::EKeyCode::World2        /* non-US #2 */

/* Function keys */
#define EXCITED_KEY_ESCAPE          ::Excited::EKeyCode::Escape
#define EXCITED_KEY_ENTER           ::Excited::EKeyCode::Enter
#define EXCITED_KEY_TAB             ::Excited::EKeyCode::Tab
#define EXCITED_KEY_BACKSPACE       ::Excited::EKeyCode::Backspace
#define EXCITED_KEY_INSERT          ::Excited::EKeyCode::Insert
#define EXCITED_KEY_DELETE          ::Excited::EKeyCode::Delete
#define EXCITED_KEY_RIGHT           ::Excited::EKeyCode::Right
#define EXCITED_KEY_LEFT            ::Excited::EKeyCode::Left
#define EXCITED_KEY_DOWN            ::Excited::EKeyCode::Down
#define EXCITED_KEY_UP              ::Excited::EKeyCode::Up
#define EXCITED_KEY_PAGE_UP         ::Excited::EKeyCode::PageUp
#define EXCITED_KEY_PAGE_DOWN       ::Excited::EKeyCode::PageDown
#define EXCITED_KEY_HOME            ::Excited::EKeyCode::Home
#define EXCITED_KEY_END             ::Excited::EKeyCode::End
#define EXCITED_KEY_CAPS_LOCK       ::Excited::EKeyCode::CapsLock
#define EXCITED_KEY_SCROLL_LOCK     ::Excited::EKeyCode::ScrollLock
#define EXCITED_KEY_NUM_LOCK        ::Excited::EKeyCode::NumLock
#define EXCITED_KEY_PRINT_SCREEN    ::Excited::EKeyCode::PrintScreen
#define EXCITED_KEY_PAUSE           ::Excited::EKeyCode::Pause
#define EXCITED_KEY_F1              ::Excited::EKeyCode::F1
#define EXCITED_KEY_F2              ::Excited::EKeyCode::F2
#define EXCITED_KEY_F3              ::Excited::EKeyCode::F3
#define EXCITED_KEY_F4              ::Excited::EKeyCode::F4
#define EXCITED_KEY_F5              ::Excited::EKeyCode::F5
#define EXCITED_KEY_F6              ::Excited::EKeyCode::F6
#define EXCITED_KEY_F7              ::Excited::EKeyCode::F7
#define EXCITED_KEY_F8              ::Excited::EKeyCode::F8
#define EXCITED_KEY_F9              ::Excited::EKeyCode::F9
#define EXCITED_KEY_F10             ::Excited::EKeyCode::F10
#define EXCITED_KEY_F11             ::Excited::EKeyCode::F11
#define EXCITED_KEY_F12             ::Excited::EKeyCode::F12
#define EXCITED_KEY_F13             ::Excited::EKeyCode::F13
#define EXCITED_KEY_F14             ::Excited::EKeyCode::F14
#define EXCITED_KEY_F15             ::Excited::EKeyCode::F15
#define EXCITED_KEY_F16             ::Excited::EKeyCode::F16
#define EXCITED_KEY_F17             ::Excited::EKeyCode::F17
#define EXCITED_KEY_F18             ::Excited::EKeyCode::F18
#define EXCITED_KEY_F19             ::Excited::EKeyCode::F19
#define EXCITED_KEY_F20             ::Excited::EKeyCode::F20
#define EXCITED_KEY_F21             ::Excited::EKeyCode::F21
#define EXCITED_KEY_F22             ::Excited::EKeyCode::F22
#define EXCITED_KEY_F23             ::Excited::EKeyCode::F23
#define EXCITED_KEY_F24             ::Excited::EKeyCode::F24
#define EXCITED_KEY_F25             ::Excited::EKeyCode::F25

/* Keypad */
#define EXCITED_KEY_KP_0            ::Excited::EKeyCode::KP0
#define EXCITED_KEY_KP_1            ::Excited::EKeyCode::KP1
#define EXCITED_KEY_KP_2            ::Excited::EKeyCode::KP2
#define EXCITED_KEY_KP_3            ::Excited::EKeyCode::KP3
#define EXCITED_KEY_KP_4            ::Excited::EKeyCode::KP4
#define EXCITED_KEY_KP_5            ::Excited::EKeyCode::KP5
#define EXCITED_KEY_KP_6            ::Excited::EKeyCode::KP6
#define EXCITED_KEY_KP_7            ::Excited::EKeyCode::KP7
#define EXCITED_KEY_KP_8            ::Excited::EKeyCode::KP8
#define EXCITED_KEY_KP_9            ::Excited::EKeyCode::KP9
#define EXCITED_KEY_KP_DECIMAL      ::Excited::EKeyCode::KPDecimal
#define EXCITED_KEY_KP_DIVIDE       ::Excited::EKeyCode::KPDivide
#define EXCITED_KEY_KP_MULTIPLY     ::Excited::EKeyCode::KPMultiply
#define EXCITED_KEY_KP_SUBTRACT     ::Excited::EKeyCode::KPSubtract
#define EXCITED_KEY_KP_ADD          ::Excited::EKeyCode::KPAdd
#define EXCITED_KEY_KP_ENTER        ::Excited::EKeyCode::KPEnter
#define EXCITED_KEY_KP_EQUAL        ::Excited::EKeyCode::KPEqual

#define EXCITED_KEY_LEFT_SHIFT      ::Excited::EKeyCode::LeftShift
#define EXCITED_KEY_LEFT_CONTROL    ::Excited::EKeyCode::LeftControl
#define EXCITED_KEY_LEFT_ALT        ::Excited::EKeyCode::LeftAlt
#define EXCITED_KEY_LEFT_SUPER      ::Excited::EKeyCode::LeftSuper
#define EXCITED_KEY_RIGHT_SHIFT     ::Excited::EKeyCode::RightShift
#define EXCITED_KEY_RIGHT_CONTROL   ::Excited::EKeyCode::RightControl
#define EXCITED_KEY_RIGHT_ALT       ::Excited::EKeyCode::RightAlt
#define EXCITED_KEY_RIGHT_SUPER     ::Excited::EKeyCode::RightSuper
#define EXCITED_KEY_MENU            ::Excited::EKeyCode::Menu

// Mouse
#define EXCITED_MOUSE_BUTTON_LEFT    ::Excited::EMouseButton::Left
#define EXCITED_MOUSE_BUTTON_RIGHT   ::Excited::EMouseButton::Right
#define EXCITED_MOUSE_BUTTON_MIDDLE  ::Excited::EMouseButton::Middle