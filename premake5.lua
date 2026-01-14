workspace "cce"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "cce"
    location "cce"
    kind "SharedLib"
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
        "%{prj.name}/vendor/spdlog/include"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "CCE_PLATFORM_WINDOWS",
            "CCE_BUILD_DLL",

        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }
    
    filter "configurations:Debug"
        defines "CCE_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "CCE_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "CCE_DIST"
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
        "cce/vendor/spdlog/include",
        "cce/src"
    }

    links
    {
        "cce"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "CCE_PLATFORM_WINDOWS",
        }

    filter "configurations:Debug"
        defines "CCE_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "CCE_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "CCE_DIST"
        optimize "On"


