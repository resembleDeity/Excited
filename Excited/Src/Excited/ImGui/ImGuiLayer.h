#pragma once

#include "Excited/Layer.h"
#include "Excited/Events/MouseEvent.h"
#include "Excited/Events/KeyEvent.h"
#include "Excited/Events/ApplicationEvent.h"


namespace Excited
{
	class EXCITED_API KImGuiLayer : public KLayer
	{
	public:

		KImGuiLayer();
		~KImGuiLayer();



		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnUpdate() override;
		virtual void OnEvent(KEvent& Event) override;

	private:

		bool OnMouseButtonPressedEvent(KMouseButtonPressedEvent& Event);
		bool OnMouseButtonReleasedEvent(KMouseButtonReleasedEvent& Event);
		
		bool OnMouseMovedEvent(KMouseMovedEvent& Event);
		bool OnMouseScrolledEvent(KMouseScrolledEvent& Event);
		
		bool OnKeyPressedEvent(KKeyPressedEvent& Event);
		bool OnKeyReleasedEvent(KKeyReleasedEvent& Event);
		bool OnKeyTypedEvent(KKeyTypedEvent& Event);
		
		bool OnWindowResizeEvent(KWindowResizeEvent& Event);

	private:

		float Time = 0.0f;
	};
}
