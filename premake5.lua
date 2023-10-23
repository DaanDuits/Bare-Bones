workspace "BareBones"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "BareBones/vendor/GLFW/include"

include "BareBones/vendor/GLFW"

project "BareBones"
    location "BareBones"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "bbpch.h"
    pchsource "BareBones/src/bbpch.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/vendor/spdlog/include",
        "%{prj.name}/src",
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
            "BB_PLATFORM_WINDOWS",
            "BB_BUILD_DLL"
        }
        
        postbuildcommands
        {
            "{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox"
        }
    
    filter "configurations:Debug"
        defines "BB_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "BB_Release"
        optimize "On"

    filter "configurations:Dist"
        defines "BB_DIST"
        optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "BareBones/vendor/spdlog/include",
        "BareBones/src"
    }

    links
    {
        "BareBones"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "BB_PLATFORM_WINDOWS"
        }
    
    filter "configurations:Debug"
        defines "BB_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "BB_Release"
        optimize "On"

    filter "configurations:Dist"
        defines "BB_DIST"
        optimize "On"