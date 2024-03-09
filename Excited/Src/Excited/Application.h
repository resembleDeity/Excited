#pragma once

#include "Core.h"

namespace Excited
{
	class EXCITED_API KApplication
	{
	public:

		KApplication();
		virtual ~KApplication();

		void Run();
	};

	// To be defined int CLIENT
	KApplication* CreateApplication();
}
