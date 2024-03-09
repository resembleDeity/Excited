#include "Excitedpch.h"
#include "Application.h"

#include "Excited/Log.h"
#include "Excited/Events/ApplicationEvent.h"



namespace Excited
{
	KApplication::KApplication()
	{
	}

	KApplication::~KApplication()
	{
	}



	void KApplication::Run()
	{
		KWindowResizeEvent Event(1280, 720);
		EXCITED_TRACE(Event);
		
		while (true)
		{
			
		}
	}
}