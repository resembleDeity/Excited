// (C) Copyright Kirito 2025

#pragma once

namespace Excited::Math
{
	template <typename T>
	struct TPoint
	{
		union
		{
			struct
			{
				T X;
				T Y;
			};
		};
	};
}