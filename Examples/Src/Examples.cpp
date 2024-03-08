#include <Excited.h>

class KExamples : public Excited::KApplication
{
public:

	KExamples()
	{

	}

	~KExamples()
	{

	}

};

Excited::KApplication* Excited::CreateApplication()
{
	return new KExamples();
}
