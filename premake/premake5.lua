
-- SOLUTION FirstExample
workspace "FirstExample"
	architecture "x86_64"


	configurations 
	{	
		"Debug", 
		"Release" 
	}

	outputdir = "%{cfg.buildcfg}-%{cfg.architecture}"  


-- PROJECT: DLL
project "FirstExapmle_dll"
location "FirstExample_dll"
kind	"SharedLib" 
language "C"
cdialect "C11"
fatalwarnings { "4700"; "6001" }
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}" )	
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}" )	
	pchheader "pch.h"
	pchsource "%{prj.name}/src/pch.c"

	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.c",
		"%{prj.name}/src/**.cpp"
	}

	includedirs	
	{
		"%{wks.location}/%{prj.name}/src"
	}


	filter "system:Windows"
			systemversion "latest"

			defines
			{
				"GMPPT_BUILD_DLL",
				"PLECS"
			}
 
	filter "configurations:Debug"
			defines	"GMPPT_DEBUG"
			symbols  "On"

	filter "configurations:Release"
			defines	"GMPPT_RELEASE"
			optimize "On"

