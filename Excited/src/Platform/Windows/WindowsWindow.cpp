// (C) Copyright Kirito 2024

#include "excitedpch.h"
#include "WindowsWindow.h"

#include "Excited/Events/KeyEvent.h"
#include "Excited/Events/MouseEvent.h"
#include "Excited/Events/ApplicationEvent.h"

#include <glad/glad.h>

namespace Excited
{
	static bool bGLFWInitialized = false;

	static void GLFWErrorCallback(int InErrorCode, const char* InDescription)
	{
		EXCITED_CORE_ERROR("[GLFW] Error ({0}): {1}", InErrorCode, InDescription);
	}

	IWindow* IWindow::Create(const FWindowProps& InProps)
	{
		return new FWindowsWindow(InProps);
	}

	FWindowsWindow::FWindowsWindow(const FWindowProps& InProps)
	{
		Init(InProps);
	}

	FWindowsWindow::~FWindowsWindow()
	{
		Shutdown();
	}

	void FWindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(Window);
	}

	void FWindowsWindow::SetVSync(bool InbEnabled)
	{
		if (InbEnabled)
		{
			glfwSwapInterval(1);
		}
		else
		{
			glfwSwapInterval(0);
		}

		Data.bVSync = InbEnabled;
	}

	bool FWindowsWindow::IsVSync() const
	{
		return Data.bVSync;
	}

	void FWindowsWindow::Init(const FWindowProps& InProps)
	{
		Data.Title = InProps.Title;
		Data.Width = InProps.Width;
		Data.Height = InProps.Height;

		EXCITED_CORE_INFO("[Window] Create {0} ({1}, {2})", InProps.Title, InProps.Width, InProps.Height);

		if (!bGLFWInitialized)
		{
			int bSuccess = glfwInit();
			EXCITED_CORE_ASSERT(bSuccess, "[GLFW] Could not initialize GLFW!");
			glfwSetErrorCallback(GLFWErrorCallback);

			bGLFWInitialized = true;
		}

		Window = glfwCreateWindow((int)InProps.Width, (int)InProps.Height, Data.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(Window);

		int Status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		EXCITED_CORE_ASSERT(Status, "[Glad] Failed initialize!");

		glfwSetWindowUserPointer(Window, &Data);
		SetVSync(true);

		// Set GLFW callbacks
		glfwSetWindowSizeCallback(Window,
			[](GLFWwindow* InWindow, int InWidth, int InHeight)
			{
				FWindowData& WindowData = *(FWindowData*)glfwGetWindowUserPointer(InWindow);
				WindowData.Width = InWidth;
				WindowData.Height = InHeight;

				IWindowResizeEvent Event(InWidth, InHeight);
				WindowData.EventCallback(Event);
			});

		glfwSetWindowCloseCallback(Window,
			[](GLFWwindow* InWindow)
			{
				FWindowData& WindowData = *(FWindowData*)glfwGetWindowUserPointer(InWindow);
				
				IWindowCloseEvent Event;
				WindowData.EventCallback(Event);
			});

		glfwSetKeyCallback(Window,
			[](GLFWwindow* InWindow, int InKey, int InScancode, int InAction, int InMods)
			{
				FWindowData& WindowData = *(FWindowData*)glfwGetWindowUserPointer(InWindow);

				switch (InAction)
				{
					case GLFW_PRESS:
					{
						IKeyPressedEvent Event(InKey, 0);
						WindowData.EventCallback(Event);

						break;
					}
					case GLFW_RELEASE:
					{
						IKeyReleasedEvent Event(InKey);
						WindowData.EventCallback(Event);

						break;
					}
					case GLFW_REPEAT:
					{
						IKeyPressedEvent Event(InKey, 1);
						WindowData.EventCallback(Event);

						break;
					}
				}
			});

		glfwSetMouseButtonCallback(Window,
			[](GLFWwindow* InWindow, int InButton, int InAction, int InMods)
			{
				FWindowData& WindowData = *(FWindowData*)glfwGetWindowUserPointer(InWindow);

				switch (InAction)
				{
					case GLFW_PRESS:
					{
						IMouseButtonPressedEvent Event(InButton);
						WindowData.EventCallback(Event);

						break;
					}
					case GLFW_RELEASE:
					{
						IMouseButtonReleasedEvent Event(InButton);
						WindowData.EventCallback(Event);

						break;
					}
				}
			});

		glfwSetScrollCallback(Window,
			[](GLFWwindow* InWindow, double InXOffset, double InYOffset)
			{
				FWindowData& WindowData = *(FWindowData*)glfwGetWindowUserPointer(InWindow);

				IMouseScrolledEvent Event((float)InXOffset, (float)InYOffset);
				WindowData.EventCallback(Event);
			});

		glfwSetCursorPosCallback(Window,
			[](GLFWwindow* InWindow, double InXPos, double InYPos)
			{
				FWindowData& WindowData = *(FWindowData*)glfwGetWindowUserPointer(InWindow);

				IMouseMovedEvent Event((float)InXPos, (float)InYPos);
				WindowData.EventCallback(Event);
			});
	}

	void FWindowsWindow::Shutdown()
	{
		glfwDestroyWindow(Window);
	}
}