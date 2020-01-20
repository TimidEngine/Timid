workspace "Timid"
	architecture "x64"
	startproject "Sandbox"

	configurations {
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

	project "Timid"
		location "Timid"
		kind "SharedLib"
		language "C++"

		targetdir ("bin/" .. outputdir .. "/%{prj.name}")
		objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

		pchheader "tmdpch.h"
		pchsource "Timid/src/tmdpch.cpp"

		files {
			"%{prj.name}/src/**.h",
			"%{prj.name}/src/**.cpp"
		}

		includedirs {
			"%{prj.name}/src",
			"%{prj.name}/vendor/spdlog/include"
		}

		filter "system:windows"
			cppdialect "C++17"
			staticruntime "On"
			systemversion "latest"

			defines {
				"TMD_PLATFORM_WINDOWS",
				"TMD_BUILD_DLL"
			}

			postbuildcommands {
				("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
			}

		filter "configurations:Debug"
			defines "TMD_DEBUG"
			symbols "On"

		filter "configurations:Release"
			defines "TMD_RELEASE"
			optimize "On"

		filter "configurations:Dist"
			defines "TMD_DIST"
			optimize "On"

	project "Sandbox"
		location "Sandbox"
		kind "ConsoleApp"
		language "C++"

		targetdir ("bin/" .. outputdir .. "/%{prj.name}")
		objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

		files {
			"%{prj.name}/src/**.h",
			"%{prj.name}/src/**.cpp"
		}

		includedirs {
			"Timid/vendor/spdlog/include",
			"Timid/src"
		}

		links {
			"Timid"
		}

		filter "system:windows"
			cppdialect "C++17"
			staticruntime "On"
			systemversion "latest"

			defines {
				"TMD_PLATFORM_WINDOWS"
			}

		filter "configurations:Debug"
			defines "TMD_DEBUG"
			symbols "On"

		filter "configurations:Release"
			defines "TMD_RELEASE"
			optimize "On"

		filter "configurations:Dist"
			defines "TMD_DIST"
			optimize "On"