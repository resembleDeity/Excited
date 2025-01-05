// (C) Copyright Kirito 2025

#include "excitedpch.h"
#include "Window.h"

#include "Excited/Core/Events/ApplicationEvent.h"
#include "Excited/Core/Events/KeyEvent.h"
#include "Excited/Core/Events/MouseEvent.h"
#include "Excited/Core/Input.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Excited
{
	static void GLFWErrorCallback(int InErrorCode, const char* InDescription)
	{
		EXCITED_CORE_ERROR("[GLFW] Error ({0}): {1}", InErrorCode, InDescription);
	}

	static bool bGLFWInitialized = false;

	FWindow::FWindow(const FWindowSpecification& InSpecification)
		: Specification(InSpecification)
	{ }

	FWindow::~FWindow()
	{
		Shutdown();
	}

	void FWindow::Init()
	{
		Data.Title = Specification.Title;
		Data.Width = Specification.Width;
		Data.Height = Specification.Height;

		EXCITED_CORE_INFO("[Window] Create {0} ({1}, {2})", Specification.Title, Specification.Width, Specification.Height);

		if (!bGLFWInitialized)
		{
			int Success = glfwInit();
			EXCITED_CORE_ASSERT(Success, "Could not initialize GLFW!");
			glfwSetErrorCallback(GLFWErrorCallback);

			bGLFWInitialized = true;
		}

		if (Specification.FullScreen)
		{
			GLFWmonitor* PrimaryMonitor = glfwGetPrimaryMonitor();
			const GLFWvidmode* Mode = glfwGetVideoMode(PrimaryMonitor);

			glfwWindowHint(GLFW_DECORATED, false);
			glfwWindowHint(GLFW_RED_BITS, Mode->redBits);
			glfwWindowHint(GLFW_GREEN_BITS, Mode->greenBits);
			glfwWindowHint(GLFW_BLUE_BITS, Mode->blueBits);
			glfwWindowHint(GLFW_REFRESH_RATE, Mode->refreshRate);

			Window = glfwCreateWindow(Mode->width, Mode->height, Data.Title.c_str(), PrimaryMonitor, nullptr);
		}
		else
		{
			Window = glfwCreateWindow((int)Specification.Width, (int)Specification.Height, Data.Title.c_str(), nullptr, nullptr);
		}

		glfwMakeContextCurrent(Window);

		int Status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		EXCITED_CORE_ASSERT(Status, "[Glad] Failed initialize!");

		glfwSetWindowUserPointer(Window, &Data);
		SetVSync(true);

		glfwSetWindowSizeCallback(Window,
			[](GLFWwindow* InWindow, int InWidth, int InHeight)
			{
				FWindowData& WindowData = *((FWindowData*)glfwGetWindowUserPointer(InWindow));

				IWindowResizeEvent Event((uint32_t)InWidth, (uint32_t)InHeight);
				WindowData.EventCallback(Event);
				WindowData.Width = InWidth;
				WindowData.Height = InHeight;
			});

		glfwSetWindowCloseCallback(Window,
			[](GLFWwindow* InWindow)
			{
				FWindowData& WindowData = *((FWindowData*)glfwGetWindowUserPointer(InWindow));

				IWindowCloseEvent Event;
				WindowData.EventCallback(Event);
			});

		glfwSetKeyCallback(Window, 
			[](GLFWwindow* InWindow, int InKey, int InScancode, int InAction, int InMods)
			{
				FWindowData& WindowData = *((FWindowData*)glfwGetWindowUserPointer(InWindow));

				switch (InAction)
				{
					case GLFW_PRESS:
					{
						FInput::UpdateKeyState((EKeyCode)InKey, EKeyState::Pressed);
						IKeyPressedEvent Event((EKeyCode)InKey, 0);
						WindowData.EventCallback(Event);
						break;
					}
					case GLFW_RELEASE:
					{
						FInput::UpdateKeyState((EKeyCode)InKey, EKeyState::Released);
						IKeyReleasedEvent Event((EKeyCode)InKey);
						WindowData.EventCallback(Event);
						break;
					}
					case GLFW_REPEAT:
					{
						FInput::UpdateKeyState((EKeyCode)InKey, EKeyState::Held);
						IKeyPressedEvent event((EKeyCode)InKey, 1);
						WindowData.EventCallback(event);
						break;
					}
				}
			});

		glfwSetCharCallback(Window, 
			[](GLFWwindow* InWindow, uint32_t InCodePoint)
			{
				FWindowData& WindowData = *((FWindowData*)glfwGetWindowUserPointer(InWindow));

				IKeyTypedEvent Event((EKeyCode)InCodePoint);
				WindowData.EventCallback(Event);
			});

		glfwSetMouseButtonCallback(Window, 
			[](GLFWwindow* InWindow, int InButton, int InAction, int InMods)
			{
				FWindowData& WindowData = *((FWindowData*)glfwGetWindowUserPointer(InWindow));

				switch (InAction)
				{
				case GLFW_PRESS:
				{
					FInput::UpdateButtonState((EMouseButton)InButton, EKeyState::Pressed);
					IMouseButtonPressedEvent Event((EMouseButton)InButton);
					WindowData.EventCallback(Event);
					break;
				}
				case GLFW_RELEASE:
				{
					FInput::UpdateButtonState((EMouseButton)InButton, EKeyState::Released);
					IMouseButtonReleasedEvent Event((EMouseButton)InButton);
					WindowData.EventCallback(Event);
					break;
				}
				}
			});

		glfwSetScrollCallback(Window, 
			[](GLFWwindow* InWindow, double InXOffset, double InYOffset)
			{
				FWindowData& WindowData = *((FWindowData*)glfwGetWindowUserPointer(InWindow));

				IMouseScrolledEvent Event((float)InXOffset, (float)InYOffset);
				WindowData.EventCallback(Event);
			});

		glfwSetCursorPosCallback(Window, 
			[](GLFWwindow* InWindow, double InXPos, double InYPos)
			{
				FWindowData& WindowData = *((FWindowData*)glfwGetWindowUserPointer(InWindow));
				IMouseMovedEvent Event((float)InXPos, (float)InYPos);
				WindowData.EventCallback(Event);
			});

		{
			int Width, Height;
			glfwGetWindowSize(Window, &Width, &Height);
			Data.Width = Width;
			Data.Height = Height;
		}
	}

	void FWindow::ProcessEvents()
	{
		glfwPollEvents();
		FInput::Update();
	}

	void FWindow::SwapBuffers()
	{
		glfwSwapBuffers(Window);
	}

	void FWindow::SetVSync(bool InbEnabled)
	{
		Specification.VSync = InbEnabled;
	}

	bool FWindow::IsVSync() const
	{
		return Specification.VSync;
	}

	void FWindow::SetTitle(const std::string& InTitle)
	{
		Data.Title = InTitle;
		glfwSetWindowTitle(Window, Data.Title.c_str());
	}

	void FWindow::Shutdown()
	{
		glfwDestroyWindow(Window);
		glfwTerminate();
		bGLFWInitialized = false;
	}

	FWindow* FWindow::Create(const FWindowSpecification& InSpecification /*= FWindowSpecification()*/)
	{
		return new FWindow(InSpecification);
	}
}