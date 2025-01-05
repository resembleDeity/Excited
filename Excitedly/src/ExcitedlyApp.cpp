#include <Excited.h>
#include <Excited/Core/EntryPoint.h>

#include "EditorLayer.h"

namespace Excited
{
	class Excitedly : public IApplication
	{
	public:

		Excitedly(const FApplicationSpecification& InSpec)
			: IApplication(InSpec)
		{
			PushLayer(new EditorLayer());
		}
	};

	IApplication* CreateApplication()
	{
		FApplicationSpecification Spec;
		Spec.Name = "Excitedly";

		return new Excitedly(Spec);
	}
}