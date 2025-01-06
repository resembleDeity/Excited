include "./vendor/premake/SolutionItems.lua"
include "Dependencies.lua"

workspace "Excited"
	architecture "x86_64"
	startproject "Excitedly"

	configurations { "Debug", "Release", "Dist" }

	solutionitems { ".editorconfig" }

	flags { "MultiProcessorCompile" }

	defines { "EXCITED_LIB" }
	-- defines { "EXCITED_DLL" }

OutputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

group "Dependencies"
	include "vendor/premake"
	include "Excited/vendor/GLFW"
	include "Excited/vendor/Glad"
	include "Excited/vendor/imgui"
group ""


include "Excited"
include "Excitedly"