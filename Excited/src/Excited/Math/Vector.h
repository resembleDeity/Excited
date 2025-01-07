// (C) Copyright Kirito 2025

#pragma once

#include "Excited/Core/Core.h"

namespace Excited::Math
{
	template <typename T>
	struct TVector
	{
	public:

		union
		{
			struct
			{
				T X;

				T Y;

				T Z;
			};

			T XYZ[3];
		};

		static const TVector<T> ZeroVector;

		static const TVector<T> OneVector;

		static const TVector<T> UpVector;

		static const TVector<T> DownVector;

		static const TVector<T> LeftVector;

		static const TVector<T> RightVector;

		static const TVector<T> ForwardVector;

		static const TVector<T> BackwardVector;

		static inline TVector<T> Zero() { return ZeroVector; }
	
		static inline TVector<T> One() { return OneVector; }
	
	public:
		
		TVector() = default;

		explicit EXCITED_FORCE_INLINE TVector(T InF);

		EXCITED_FORCE_INLINE TVector(T InX, T InY, T InZ);
	
		explicit EXCITED_FORCE_INLINE TVector(const TVector2<T> InV, T InZ);
	};
}