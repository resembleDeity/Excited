#pragma once

#include "Core.h"

namespace Excited
{
	class EXCITED_API KApplication
	{
	public:

		KApplication();
		~KApplication();

		void Run();
	};

	// To be defined int CLIENT
	KApplication* CreateApplication();
}
