#include "Excitedpch.h"
#include "Application.h"

#include "Excited/Events/ApplicationEvent.h"
#include "Excited/Log.h"

#include <GLFW/glfw3.h>



namespace Excited
{
	KApplication::KApplication()
	{
		Window = std::unique_ptr<KWindow>(KWindow::Create());
	}

	KApplication::~KApplication()
	{
	}



	void KApplication::Run()
	{
		
		while (bRunning)
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			Window->OnUpdate();
		}
	}
}