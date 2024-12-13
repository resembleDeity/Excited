// (C) Copyright Kirito 2024

#pragma once

#include "Excited/Window.h"

#include <GLFW/glfw3.h>

namespace Excited
{
	class FWindowsWindow : public IWindow
	{
	public:

		FWindowsWindow(const FWindowProps& InProps);
		virtual ~FWindowsWindow();
		
		virtual void OnUpdate() override;

		virtual inline unsigned int GetWidth() const override { return Data.Width; }
		virtual inline unsigned int GetHeight() const override { return Data.Height; }

		virtual inline void SetEventCallback(const FEventCallback& InCallback) override { Data.EventCallback = InCallback; }

		virtual void SetVSync(bool InbEnabled) override;
		virtual bool IsVSync() const override;

	private:

		virtual void Init(const FWindowProps& InProps);
		virtual void Shutdown();

	private:

		GLFWwindow* Window;

		struct FWindowData
		{
			std::string Title;
			unsigned int Width;
			unsigned int Height;

			bool bVSync;

			FEventCallback EventCallback;
		};

		FWindowData Data;
	};
}