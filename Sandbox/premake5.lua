project "Sandbox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

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
    }

    links                           --链接
    {
        "Excited"
    }

    filter "system:windows"        
        systemversion "latest"

        defines
        {
            
        }

        filter "configurations:Debug"
            defines "EXCITED_DEBUG"
            runtime "Debug"
            symbols "on"            

        filter "configurations:Release"
            defines "EXCITED_Release"
            runtime "Release"
            optimize "on"           

        filter "configurations:Dist"
            defines "EXCITED_DIST"
            runtime "Release"
            optimize "on"