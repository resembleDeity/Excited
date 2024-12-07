// (C) Copyright Kirito 2024

#pragma once

#ifdef EXCITED_PLATFORM_WINDOWS

#include <stdio.h>

extern Excited::Application* Excited::CreateApplication();

int main(int argc, char** argv)
{
	printf("Start Engine\n");
	auto app = Excited::CreateApplication();
	app->Run();
	delete app;
}

#endif