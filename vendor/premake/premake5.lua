project "Premake"
	kind "Utility"

	targetdir ("%{wks.location}/bin/" .. OutputDir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. OutputDir .. "/%{prj.name}")

	files { "%{wks.location}/**.lua" }

	postbuildmessage "Regenerating project files with Premake5!"
	postbuildcommands { "\"%{prj.location}bin/premake5\" %{_ACTION} --file=\"%{wks.location}**.lua\"" }