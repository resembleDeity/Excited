// (C) Copyright Kirito 2024

#pragma once

#include "Excited/Core/Core.h"
#include "Excited/Core/Events/Event.h"

struct GLFWwindow;
struct GLFWcursor;

namespace Excited
{
	struct FWindowSpecification
	{
		std::string Title = "Excited";
		uint32_t Width = 1600;
		uint32_t Height = 900;
		bool FullScreen = false;
		bool VSync = true;
	};

	class FWindow
	{
	public:

		using FEventCallback = std::function<void(IEvent&)>;

		FWindow(const FWindowSpecification& InSpecification);
		virtual ~FWindow();

		virtual void Init();
		virtual void ProcessEvents();
		virtual void SwapBuffers();

		virtual const std::string& GetTitle() const { return Data.Title; }
		inline uint32_t GetWidth() const { return Data.Width; }
		inline uint32_t GetHeight() const { return Data.Height; }
		virtual std::pair<uint32_t, uint32_t> GetSize() const { return { Data.Width, Data.Height }; }
		virtual bool IsVSync() const;

		virtual void SetTitle(const std::string& InTitle);
		virtual void SetEventCallback(const FEventCallback& InCallback) { Data.EventCallback = InCallback; }
		virtual void SetVSync(bool InbEnabled);
		
		inline void* GetNativeWindow() const { return Window; }

		static FWindow* Create(const FWindowSpecification& InSpecification = FWindowSpecification());

	private:

		virtual void Shutdown();

	private:

		GLFWwindow* Window;
		GLFWcursor* ImGuiMouseCursors[9] = { 0 };
		FWindowSpecification Specification;

		struct FWindowData
		{
			std::string Title;
			uint32_t Width;
			uint32_t Height;

			FEventCallback EventCallback;
		};

		FWindowData Data;
		float LastFrameTime = 0.0f;
	};
}