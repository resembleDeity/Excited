#pragma once

#ifdef EXCITED_PLATFORM_WINDOWS

extern Excited::KApplication* Excited::CreateApplication();

int main(int argc, char** argv)
{
	Excited::KLog::Init();
	EXCITED_CORE_WARN("Initialized Log!");
	EXCITED_INFO("Started Client! Var={0}", 5);

	auto Application = Excited::CreateApplication();
	Application->Run();
	delete Application;
}

#endif