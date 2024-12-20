project "Excited"                                               --项目
    kind "StaticLib"                                            --类型（动态库）
    language "C++"                                              --语言
    cppdialect "C++17"                                          --C++标准（编译时）
    staticruntime "On"                                          --是否将运行时库静态链接运行时库（dll属性的文件需要关闭）

    targetdir ("%{wks.location}/bin/" .. OutputDir .. "/%{prj.name}")               --输出目录(.. XX ..中 ".."是字符串连接符)
    objdir ("%{wks.location}/bin-int/" .. OutputDir .. "/%{prj.name}")              --中间目录

    pchheader "excitedpch.h"                                        --预编译头文件
    pchsource "src/excitedpch.cpp"                                  --(实际上编译器不需要 但是VS需要这个.cpp文件)
    

    files                                                       --将源代码文件包含到项目中
    {
       "src/**.h",
       "src/**.cpp",
       "LogOutputType.txt"
       -- "vendor/stb_image/**.h",
       -- "vendor/stb_image/**.cpp",
       -- "vendor/glm/glm/**.hpp",
       -- "vendor/glm/glm/**.inl",

       -- "vendor/ImGuizmo/ImGuizmo.h",
       -- "vendor/ImGuizmo/ImGuizmo.cpp"
    }

    defines
    {
        "_CRT_SECURE_NO_WARNINGS",
        "GLFW_INCLUDE_NONE",
        "YAML_CPP_STATIC_DEFINE"
    }

    includedirs                                                 --库文件（包含库目录）
    {
        "src",
        "vendor/spdlog/include",
        "%{IncludeDir.GLFW}",                                       --将IncludeDir表中GLFW键索引的值（地址）作为一个库文件路径
        "%{IncludeDir.Glad}",                                       --将IncludeDir表中Glad键索引的值（地址）作为一个库文件路径
        "%{IncludeDir.ImGui}",                                      --将IncludeDir表中ImGui键索引的值（地址）作为一个库文件路径
        -- "%{IncludeDir.glm}",                                        --将IncludeDir表中glm键索引的值（地址）作为一个库文件路径
        -- "%{IncludeDir.stb_image}",
        -- "%{IncludeDir.entt}",
        -- "%{IncludeDir.yaml_cpp}",
        -- "%{IncludeDir.ImGuizmo}"
    }

    links                                                       --为EXCITED项目(.dll)链接文件
    {
        "GLFW",                                                     --链接上方group中的项目GLFW
        "Glad",                                                     --链接上方group中的项目Glad
        "ImGui",                                                    --链接上方group中的项目ImGui
        -- "yaml-cpp",                                                 --链接根目录premake文件里group中的项目yaml-cpp
        "opengl32.lib"
    }

    -- filter "files:vendor/ImGuizmo/**.cpp"                       --?? why
    -- flags {"NoPCH"}

    filter "system:windows"                                     --过滤器(如果系统是windows)   >>> !!!  filter, not filters  !!!
        systemversion "latest"                                      --windows SDK 版本

        defines                                                 --宏的声明
        {                          
            "EXCITED_BUILD_DLL",
        }

        --  //////////////////////////////////////////////////////////////////////
        --  ////  NOW WE USE EXCITED AS A STATIC LIB, SO DON'T NEED THIS COMMAND  ////
        --  //////////////////////////////////////////////////////////////////////
        --[[
        postbuildcommands           --构建项目完成后执行的指令
        {
            ("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
        }   
        --将当前项目的构建目标文件复制到 "../bin/" 下的一个名为 "Debug/Sandbox" 或 "Release/Sandbox" 的子目录中
        ]]

    filter "configurations:Debug"                       -->>> !!!  configurations, not configuration  !!!
        defines "EXCITED_DEBUG"
        runtime "Debug"
        symbols "on"                                        --编译器是否生成带有调试符号的可执行文件

    filter "configurations:Release"
        defines "EXCITED_Release"
        runtime "Release"
        optimize "on"                                       --是否开启代码优化

    filter "configurations:Dist"
        defines "EXCITED_DIST"
        runtime "Release"
        optimize "on"