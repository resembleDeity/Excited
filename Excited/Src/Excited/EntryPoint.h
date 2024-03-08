#pragma once

#ifdef EXCITED_PLATFORM_WINDOWS

extern Excited::KApplication* Excited::CreateApplication();

int main(int argc, char** argv)
{
	auto Application = Excited::CreateApplication();
	Application->Run();
	delete Application;
}

#endif