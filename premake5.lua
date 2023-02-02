workspace "Engine"
architecture "x64"

configurations { "Debug",
    "Release",
    "Dist"
}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Engine/vendor/GLFW/include"
IncludeDir["Glad"] = "Engine/vendor/Glad/include"

include "Engine/vendor/GLFW"
include "Engine/vendor/Glad"

project "Engine"
    location "Engine"
    kind "SharedLib"
    language "C++"
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "pre.h"
	pchsource "Engine/src/pre.cpp"

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs {
        "%{prj.name}/src/",
        "%{prj.name}/vendor/spdlog/include/",
        "%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}"
    }

    links 
	{ 
		"GLFW",
        "Glad",
		"opengl32.lib"
	}

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines {
            "ENGINE_WINDOWS_BUILD",
            "ENGINE_DLL_BUILD",
            "GLFW_INCLUDE_NONE"
        }

        postbuildcommands{
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }

    filter "configurations:Debug"
        defines "EN_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "EN_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "EN_DIST"
        optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"

    language "C++"
    targetdir ("./bin/" .. outputdir .. "/%{prj.name}")
    objdir ("./bin-int/" .. outputdir .. "/%{prj.name}")

     files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs {
        "Engine/vendor/spdlog/include/",
        "Engine/src"
    }

    links {
        "Engine"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines {
            "ENGINE_WINDOWS_BUILD",
        }


    filter "configurations:Debug"
        defines "EN_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "EN_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "EN_DIST"
        optimize "On"