workspace "Brain"
	architecture "x86_64"
	startproject "BrainFracker"

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

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Brain/vendor/GLFW/include"
IncludeDir["Glad"] = "Brain/vendor/Glad/include"
IncludeDir["ImGui"] = "Brain/vendor/imgui"
IncludeDir["glm"] = "Brain/vendor/glm"
IncludeDir["stb_image"] = "Brain/vendor/stb_image"

syslibdirs {"C:/opencv/build/x64/vc16/lib"}
includedirs {"C:/opencv/build/include"}

group "Dependencies"
	include "Brain/vendor/GLFW"
	include "Brain/vendor/Glad"
	include "Brain/vendor/imgui"
group ""

project "Brain"
	location "Brain"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "brpch.h"
	pchsource "Brain/src/brpch.cpp"

	files
	{
		"Brain/src/**.h",
		"Brain/src/**.cpp",
		"Brain/vendor/stb_image/**.h",
		"Brain/vendor/stb_image/**.cpp",
		"Brain/vendor/glm/glm/**.hpp",
		"Brain/vendor/glm/glm/**.inl",
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS",
		"GLFW_INCLUDE_NONE"
	}

	includedirs
	{
		"Brain/src",
		"Brain/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.stb_image}"
	}

	links 
	{ 
		"GLFW",
		"Glad",
		"ImGui",
		"opencv_world4100d.lib",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		defines "BR_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "BR_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "BR_DIST"
		runtime "Release"
		optimize "on"

project "BrainFracker"
	location "BrainFracker"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"BrainFracker/src/**.h",
		"BrainFracker/src/**.cpp"
	}

	includedirs
	{
		"Brain/vendor/spdlog/include",
		"Brain/src",
		"Brain/vendor",
		"%{IncludeDir.glm}"
	}

	links
	{
		"Brain"
	}

	filter "system:windows"
		systemversion "latest"
		
	filter "configurations:Debug"
		defines "BR_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "BR_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "BR_DIST"
		runtime "Release"
		optimize "on"
