#include "Excitedpch.h"
#include "ImGuiLayer.h"

#include "imgui.h"
#include "Excited/Application.h"
#include "Platform/OpenGL/ImGuiOpenGLRender.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>


namespace Excited
{
	KImGuiLayer::KImGuiLayer()
		: KLayer("ImGuiLayer")
	{ }

	KImGuiLayer::~KImGuiLayer()
	{ }
	
	void KImGuiLayer::OnAttach()
	{
		ImGui::CreateContext();
		ImGui::StyleColorsDark();

		ImGuiIO& IO = ImGui::GetIO();
		IO.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
		IO.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

		IO.KeyMap[ImGuiKey_Tab] = GLFW_KEY_TAB;
		IO.KeyMap[ImGuiKey_LeftArrow] = GLFW_KEY_LEFT;
		IO.KeyMap[ImGuiKey_RightArrow] = GLFW_KEY_RIGHT;
		IO.KeyMap[ImGuiKey_UpArrow] = GLFW_KEY_UP;
		IO.KeyMap[ImGuiKey_DownArrow] = GLFW_KEY_DOWN;
		IO.KeyMap[ImGuiKey_PageUp] = GLFW_KEY_PAGE_UP;
		IO.KeyMap[ImGuiKey_PageDown] = GLFW_KEY_PAGE_DOWN;
		IO.KeyMap[ImGuiKey_Home] = GLFW_KEY_HOME;
		IO.KeyMap[ImGuiKey_End] = GLFW_KEY_END;
		IO.KeyMap[ImGuiKey_Insert] = GLFW_KEY_INSERT;
		IO.KeyMap[ImGuiKey_Delete] = GLFW_KEY_DELETE;
		IO.KeyMap[ImGuiKey_Backspace] = GLFW_KEY_BACKSPACE;
		IO.KeyMap[ImGuiKey_Space] = GLFW_KEY_SPACE;
		IO.KeyMap[ImGuiKey_Enter] = GLFW_KEY_ENTER;
		IO.KeyMap[ImGuiKey_Escape] = GLFW_KEY_ESCAPE;

		IO.KeyMap[ImGuiKey_A] = GLFW_KEY_A;
		IO.KeyMap[ImGuiKey_C] = GLFW_KEY_C;
		IO.KeyMap[ImGuiKey_V] = GLFW_KEY_V;
		IO.KeyMap[ImGuiKey_X] = GLFW_KEY_X;
		IO.KeyMap[ImGuiKey_Y] = GLFW_KEY_Y;
		IO.KeyMap[ImGuiKey_Z] = GLFW_KEY_Z;

		ImGui_ImplOpenGL3_Init("#version 460");
	}

	void KImGuiLayer::OnDetach()
	{
	}

	void KImGuiLayer::OnUpdate()
	{
		ImGuiIO& IO = ImGui::GetIO();
		KApplication& App = KApplication::GetApplication();
		IO.DisplaySize = ImVec2(App.GetWindow().GetWidth(), App.GetWindow().GetHeight());
		
		float CurrentTime = (float)glfwGetTime();
		IO.DeltaTime = Time > 0.0f ? (CurrentTime - Time) : (1.0f / 60.0f);
		Time = CurrentTime;

		ImGui_ImplOpenGL3_NewFrame();
		ImGui::NewFrame();
		
		static bool bShow = true;
		ImGui::ShowDemoWindow(&bShow);
		
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}
	
	void KImGuiLayer::OnEvent(KEvent& Event)
	{
		TEventDispatcher Dispatcher(Event);

		Dispatcher.Dispatch<KMouseButtonPressedEvent>(EXCITED_BIND_EVENT_FN(KImGuiLayer::OnMouseButtonPressedEvent));
		Dispatcher.Dispatch<KMouseButtonReleasedEvent>(EXCITED_BIND_EVENT_FN(KImGuiLayer::OnMouseButtonReleasedEvent));
		
		Dispatcher.Dispatch<KMouseMovedEvent>(EXCITED_BIND_EVENT_FN(KImGuiLayer::OnMouseMovedEvent));
		Dispatcher.Dispatch<KMouseScrolledEvent>(EXCITED_BIND_EVENT_FN(KImGuiLayer::OnMouseScrolledEvent));
		
		Dispatcher.Dispatch<KKeyPressedEvent>(EXCITED_BIND_EVENT_FN(KImGuiLayer::OnKeyPressedEvent));
		Dispatcher.Dispatch<KKeyReleasedEvent>(EXCITED_BIND_EVENT_FN(KImGuiLayer::OnKeyReleasedEvent));
		Dispatcher.Dispatch<KKeyTypedEvent>(EXCITED_BIND_EVENT_FN(KImGuiLayer::OnKeyTypedEvent));
		
		Dispatcher.Dispatch<KWindowResizeEvent>(EXCITED_BIND_EVENT_FN(KImGuiLayer::OnWindowResizeEvent));
	}

	bool KImGuiLayer::OnMouseButtonPressedEvent(KMouseButtonPressedEvent& Event)
	{
		ImGuiIO& IO = ImGui::GetIO();
		IO.MouseDown[Event.GetMouseButton()] = true;

		return false;
	}

	bool KImGuiLayer::OnMouseButtonReleasedEvent(KMouseButtonReleasedEvent& Event)
	{
		ImGuiIO& IO = ImGui::GetIO();
		IO.MouseDown[Event.GetMouseButton()] = false;

		return false;
	}

	bool KImGuiLayer::OnMouseMovedEvent(KMouseMovedEvent& Event)
	{
		ImGuiIO& IO = ImGui::GetIO();
		IO.MousePos = ImVec2(Event.GetX(), Event.GetY());

		return false;
	}

	bool KImGuiLayer::OnMouseScrolledEvent(KMouseScrolledEvent& Event)
	{
		ImGuiIO& IO = ImGui::GetIO();
		IO.MouseWheelH += Event.GetXOffset();
		IO.MouseWheel += Event.GetYOffset();

		return false;
	}

	bool KImGuiLayer::OnKeyPressedEvent(KKeyPressedEvent& Event)
	{
		ImGuiIO& IO = ImGui::GetIO();
		IO.KeysDown[Event.GetKeyCode()] = true;

		IO.KeyCtrl = IO.KeysDown[GLFW_KEY_LEFT_CONTROL] || IO.KeysDown[GLFW_KEY_RIGHT_CONTROL];
		IO.KeyAlt = IO.KeysDown[GLFW_KEY_LEFT_ALT] || IO.KeysDown[GLFW_KEY_RIGHT_ALT];
		IO.KeyShift = IO.KeysDown[GLFW_KEY_LEFT_SHIFT] || IO.KeysDown[GLFW_KEY_RIGHT_SHIFT];
		IO.KeySuper = IO.KeysDown[GLFW_KEY_LEFT_SUPER] || IO.KeysDown[GLFW_KEY_RIGHT_SUPER];
		
		return false;
	}

	bool KImGuiLayer::OnKeyReleasedEvent(KKeyReleasedEvent& Event)
	{
		ImGuiIO& IO = ImGui::GetIO();
		IO.KeysDown[Event.GetKeyCode()] = false;

		return false;
	}

	bool KImGuiLayer::OnKeyTypedEvent(KKeyTypedEvent& Event)
	{
		ImGuiIO& IO = ImGui::GetIO();

		int KeyCode = Event.GetKeyCode();
		if (KeyCode > 0 && KeyCode < 0x10000)
		{
			IO.AddInputCharacter((unsigned short)KeyCode);
		}

		return false;
	}

	bool KImGuiLayer::OnWindowResizeEvent(KWindowResizeEvent& Event)
	{
		ImGuiIO& IO = ImGui::GetIO();
		IO.DisplaySize = ImVec2(Event.GetWidth(), Event.GetHeight());
		IO.DisplayFramebufferScale = ImVec2(1.0f, 1.0f);
		glViewport(0, 0, Event.GetWidth(), Event.GetHeight());

		return false;
	}
}
