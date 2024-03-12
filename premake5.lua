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

include "Excited/Vendor/GLFW"



project "Excited"
	location "Excited"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. OutputDir .. "%{prj.name}")
	objdir ("bin-int/" .. OutputDir .. "%{prj.name}")

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
		"%{IncludeDir.GLFW}"
	}

	links
	{
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

	defines
	{
		"EXCITED_PLATFORM_WINDOWS",
		"EXCITED_BUILD_DLL"
	}

	postbuildcommands
	{
		("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. OutputDir .. "Examples")
	}

	filter "configurations:Debug"
		defines "EXCITED_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "EXCITED_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "EXCITED_DIST"
		buildoptions "/MD"
		optimize "On"



project "Examples"
	location "Examples"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. OutputDir .. "%{prj.name}")
	objdir ("bin-int/" .. OutputDir .. "%{prj.name}")

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
		staticruntime "On"
		systemversion "latest"

	defines
	{
		"EXCITED_PLATFORM_WINDOWS"
	}

	filter "configurations:Debug"
		defines "EXCITED_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "EXCITED_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "EXCITED_DIST"
		buildoptions "/MD"
		optimize "On"