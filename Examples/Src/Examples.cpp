#include <Excited.h>


class KExamplesLayer : public Excited::KLayer
{
public:

	KExamplesLayer()
		: KLayer()
	{ }

	virtual void OnUpdate() override
	{
		EXCITED_INFO("Examples Layer: Update");
	}

	virtual void OnEvent(Excited::KEvent& Event) override
	{
		EXCITED_INFO("{0}", Event);
	}
	
};


class KExamples : public Excited::KApplication
{
public:

	KExamples()
	{
		PushLayer(new KExamplesLayer());
	}

	~KExamples()
	{

	}

};

Excited::KApplication* Excited::CreateApplication()
{
	return new KExamples();
}
