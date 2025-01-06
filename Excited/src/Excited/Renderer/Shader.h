// (C) Copyright Kirito 2025

#pragma once

#include "Excited/Core/Core.h"

#include <string>

#define EXCITED_HAS_SHADER_COMPILER !EXCITED_DIST

namespace Excited
{
	namespace ShaderUtils
	{
		enum class EShaderLanguage
		{
			NONE, GLSL, HLSL,
		};
	}

	enum class EShaderUniformType
	{
		None = 0,
		Bool,
		Int, UInt, IVec2, IVec3, IVec4,
		Float, Vec2, Vec3, Vec4,
		Mat3, Mat4,
	};

	class IShader
	{
	public:

		virtual ~IShader() = default;

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		virtual const std::string& GetName() const = 0;

		static TRef<IShader> CreateShader(const std::string& InFilePath);

		static constexpr const char* GetShaderDirectoryPath()
		{
			return "Resources/Shaders/";
		}
	};

	class UShaderLibrary
	{
	public:

		UShaderLibrary();
		~UShaderLibrary();

		void Add(const TRef<IShader>& InShader);
		void Load(std::string_view InName, const std::string& InPath);
	
		const TRef<IShader>& Get(const std::string& InName) const;
		std::unordered_map<std::string, TRef<IShader>>& GetShaders() { return Shaders; }
		const std::unordered_map<std::string, TRef<IShader>>& GetShaders() const { return Shaders; }

		size_t GetSize() const { return Shaders.size(); }

	private:

		std::unordered_map<std::string, TRef<IShader>> Shaders;
	};
}