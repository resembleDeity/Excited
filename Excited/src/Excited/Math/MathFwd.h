// (C) Copyright Kirito 2025

#pragma once

namespace Excited::Math
{
	template <typename T> struct TVector;
	template <typename T> struct TVector2;
	template <typename T> struct TVector3;
}

namespace ispc
{
	struct FVector;
	struct FVector2D;
	struct FVector4;
}

using FVector = Excited::Math::TVector<double>;
using FVector2D = Excited::Math::TVector2<double>;
using FVector4 = Excited::Math::TVector4<double>;

using FVector3d = Excited::Math::TVector<double>;
using FVector2d = Excited::Math::TVector2<double>;
using FVector4d = Excited::Math::TVector4<double>;

using FVector3f = Excited::Math::TVector<float>;
using FVector2f = Excited::Math::TVector2<float>;
using FVector4f = Excited::Math::TVector4<float>;