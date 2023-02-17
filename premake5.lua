workspace "Dred"
architecture "x64"

configurations { "Debug",
    "Release",
    "Dist"
}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"]  = "Dred/vendor/GLFW/include"
IncludeDir["Glad"]  = "Dred/vendor/Glad/include"
IncludeDir["ImGui"] = "Dred/vendor/imgui"
IncludeDir["glm"] = "Dred/vendor/glm"

include "Dred/vendor/GLFW"
include "Dred/vendor/Glad"
include "Dred/vendor/imgui"

project "Dred"
    location "Dred"
    kind "StaticLib"
    language "C++"
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
    staticruntime "on"

    pchheader "pre.h"
	pchsource "Dred/src/pre.cpp"

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
        "%{prj.name}/vendor/glm/glm/**.hpp",
        "%{prj.name}/vendor/glm/glm/**.ini"
    }

    includedirs {
        "%{prj.name}/src/",
        "%{prj.name}/src/Dred/",
        "%{prj.name}/vendor/spdlog/include/",
        "%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
    }

    links 
	{ 
		"GLFW",
        "Glad",
        "ImGui",
		"opengl32.lib"
	}

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines {
            "DRED_WINDOWS_BUILD",
            "DRED_DLL_BUILD",
            "GLFW_INCLUDE_NONE"
        }

        postbuildcommands{
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }

    filter "configurations:Debug"
        defines "DD_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "DD_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "DD_DIST"
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
        "Dred/vendor/spdlog/include/",
        "Dred/src",
        "Dred/vendor",
        "%{IncludeDir.glm}"
    }

    links {
        "Dred"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines {
            "DRED_WINDOWS_BUILD",
        }


    filter "configurations:Debug"
        defines "DD_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "DD_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "DD_DIST"
        optimize "On"