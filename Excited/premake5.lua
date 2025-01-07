project "Excited"
	kind "StaticLib"
	-- kind "SharedLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "Off"

	targetdir ("%{wks.location}/bin/" .. OutputDir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. OutputDir .. "/%{prj.name}")

	pchheader "excitedpch.h"
	pchsource "src/excitedpch.cpp"

	files
	{
		"src/**.h",
		"src/**.cpp",
		"vendor/stb_image/**.h",
		"vendor/stb_image/**.cpp",
		"vendor/glm/glm/**.hpp",
		"vendor/glm/glm/**.inl",
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS",
		"GLFW_INCLUDE_NONE",
	}

	includedirs
	{
		"src",

		"vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.stb_image}",
		"%{IncludeDir.VulkanSDK}",
	}

	links
	{
		"glfw",
		"Glad",
		"ImGui",
		"opengl32.lib",
	}

	filter "system:windows"
		systemversion "latest"

		defines { "EXCITED_PLATFORM_WINDOWS", "EXCITED_BUILD_DLL" }

		links
		{
			"%{Library.WinSock}",
			"%{Library.WinMM}",
			"%{Library.WinVersion}",
			"%{Library.BCrypt}",
		}

	filter "configurations:Debug"
		defines "EXCITED_DEBUG"
		runtime "Debug"
		symbols "On"

		links { }

	filter "configurations:Release"
		defines "EXCITED_RELEASE"
		runtime "Release"
		optimize "On"

		links { }

	filter "configurations:Dist"
		defines "EXCITED_DIST"
		runtime "Release"
		optimize "On"

		links { }