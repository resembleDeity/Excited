// (C) Copyright Kirito 2024

#pragma once

#include "Excited/Core/Application.h"

extern Excited::IApplication* Excited::CreateApplication();
bool bGApplicationRunning = true;

namespace Excited
{
	int Main(int argc, char** argv)
	{
		while (bGApplicationRunning)
		{
			Excited::FLog::Init();
			IApplication* app = CreateApplication();
			app->Run();
			delete app;
		}

		return 0;
	}
}

#if EXCITED_DIST && EXCITED_PLATFORM_WINDOWS

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	return Excited::Main(__argc, __argv);
}

#else
int main(int argc, char** argv)
{
	return Excited::Main(argc, argv);
}

#endif