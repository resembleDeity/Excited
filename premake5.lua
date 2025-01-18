include "./vendor/premake/SolutionItems.lua"
include "Dependencies.lua"

workspace "Excited"
	architecture "x86_64"
	startproject "Excitedly"

	configurations { "Debug", "Release", "Dist" }

	solutionitems { ".editorconfig" }

	flags { "MultiProcessorCompile" }

	defines { "EXCITED_LIB", "GUI_LIB" }
	-- defines { "EXCITED_DLL", "GUI_DLL" }

OutputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

group "Dependencies"
	include "vendor/premake"
	include "Excited/vendor/GLFW"
	include "Excited/vendor/Glad"
	include "Excited/vendor/imgui"
group ""

group "Core"
	include "Excited"
	include "Excitedly"
group ""