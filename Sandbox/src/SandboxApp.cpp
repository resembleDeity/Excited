#include <Excited.h>

class Sandbox : public Excited::Application
{
public:

	Sandbox() 
	{ }

	~Sandbox()
	{ }
};

Excited::Application* Excited::CreateApplication()
{
	return new Sandbox();
}