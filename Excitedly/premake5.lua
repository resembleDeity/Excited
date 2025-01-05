project "Excitedly"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "Off"

	targetdir ("%{wks.location}/bin/" .. OutputDir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. OutputDir .. "/%{prj.name}")

	files
	{
		"src/**.h",
		"src/**.cpp"
	}

	includedirs
	{
		"%{wks.location}/Excited/vendor/spdlog/include",
		"%{wks.location}/Excited/src",
		"%{wks.location}/Excited/vendor",

		"%{IncludeDir.glm}",
	}

	links { "Excited" }

	filter "system:windows"
		systemversion "latest"
		defines { "EXCITED_PLATFORM_WINDOWS" }

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