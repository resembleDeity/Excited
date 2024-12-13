// (C) Copyright Kirito 2024

#pragma once

#include "Core.h"

#ifdef EXCITED_PLATFORM_WINDOWS

extern Excited::Application* Excited::CreateApplication();

int main(int argc, char** argv)
{
	Excited::FLog::Init();

	auto app = Excited::CreateApplication();
	app->Run();
	delete app;
}

#endif