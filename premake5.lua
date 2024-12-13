workspace "Excited"
    architecture "x86_64"
    startproject "Sandbox"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

    flags
    {
        "MultiProcessorCompile"
    }


OutputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

include "Dependencies.lua"

group "Dependencies"
    include "Excited/vendor/GLFW"
    include "Excited/vendor/Glad"
    include "Excited/vendor/imgui"
group ""

include "Excited"

include "Sandbox"