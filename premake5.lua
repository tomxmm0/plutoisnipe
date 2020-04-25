workspace "plutoisnipe"
	location "./build"
	objdir "%{wks.location}/obj"
	targetdir "%{wks.location}/bin/%{cfg.platform}/%{cfg.buildcfg}"

	configurations {
		"Debug",
		"Release",
	}

	platforms { "x86" }
	architecture "x86"

	systemversion "latest"
	symbols "On"
	staticruntime "Off"
	editandcontinue "Off"
	warnings "Extra"
	characterset "ASCII"
	
	buildoptions { "/utf-8", "/Zm200" }

	filter "action:vs*"
		buildoptions "/std:c++17"
		defines {
			"_WINDOWS",
			"WIN32",
		}

	filter "action:gmake*"
		cppdialect "C++17"
		buildoptions "-std=c++17"
		defines {
			"_LINUX",
		}

	filter "Release"
		optimize "Full"

		defines {
			"NDEBUG",
		}

		flags {
			"FatalCompileWarnings",
		}

	filter "Debug"
		optimize "Debug"

		defines {
			"DEBUG",
			"_DEBUG",
		}

	filter {}

	project "plutoisnipe"
		pchheader "stdinc.hpp"
		pchsource "./src/stdinc.cpp"

		kind "SharedLib"
		language "C++"

		files {
			"./src/**.hpp",
			"./src/**.cpp",
		}

		includedirs {
			"./src",
			"%{prj.location}/src",
		}

		libdirs {
			"./lib",
		}

		links {
			"detours.lib",
		}

		vpaths
		{
			["Headers"] = { "src/**.hpp", "src/**.h", },
			["Source"] = {"src/**.cpp", "src/**.cc", "src/stdinc.hpp", }
		}
