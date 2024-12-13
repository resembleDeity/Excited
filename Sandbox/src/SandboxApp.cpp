#include <Excited.h>

class ExampleLayer : public Excited::ILayer
{
public:

	ExampleLayer()
		: ILayer("Example")
	{ }

	virtual void OnUpdate() override
	{
		EXCITED_INFO("[Layer] ExampleLayer::OnUpdate");
	}
};

class Sandbox : public Excited::Application
{
public:

	Sandbox() 
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Excited::FImGuiLayer());
	}

	~Sandbox()
	{ }
};

Excited::Application* Excited::CreateApplication()
{
	return new Sandbox();
}