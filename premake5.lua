workspace "Excited"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}



OutputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = { }
IncludeDir["GLFW"] = "Excited/Vendor/GLFW/include"
IncludeDir["Glad"] = "Excited/Vendor/Glad/include"
IncludeDir["imgui"] = "Excited/Vendor/imgui"

include "Excited/Vendor/GLFW"
include "Excited/Vendor/Glad"
include "Excited/Vendor/imgui"



project "Excited"
	location "Excited"
	kind "SharedLib"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. OutputDir .. "/%{prj.name}")
	objdir ("bin-int/" .. OutputDir .. "/%{prj.name}")

	pchheader "Excitedpch.h"
	pchsource "Excited/Src/Excitedpch.cpp"

	files
	{
		"%{prj.name}/Src/**.h",
		"%{prj.name}/Src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/Src",
		"%{prj.name}/Vendor/SpdLog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.imgui}"
	}

	links
	{
		"GLFW",
		"Glad",
		"imgui",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

	defines
	{
		"EXCITED_PLATFORM_WINDOWS",
		"EXCITED_BUILD_DLL",
		"GLFW_INCLUDE_NONE"
	}

	postbuildcommands
	{
		("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. OutputDir .. "/Examples/\"")
	}

	filter "configurations:Debug"
		defines "EXCITED_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "EXCITED_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "EXCITED_DIST"
		runtime "Release"
		optimize "On"



project "Examples"
	location "Examples"
	kind "ConsoleApp"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. OutputDir .. "/%{prj.name}")
	objdir ("bin-int/" .. OutputDir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/Src/**.h",
		"%{prj.name}/Src/**.cpp"
	}

	includedirs
	{
		"Excited/Vendor/SpdLog/include",
		"Excited/Src"
	}

	links
	{
		"Excited"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

	defines
	{
		"EXCITED_PLATFORM_WINDOWS"
	}

	filter "configurations:Debug"
		defines "EXCITED_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "EXCITED_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "EXCITED_DIST"
		runtime "Release"
		optimize "On"