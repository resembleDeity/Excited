
-- Excited Dependencies



IncludeDir = {}
IncludeDir["stb_image"] = "%{wks.location}/Excited/vendor/stb_image"
IncludeDir["Box2D"] = "%{wks.location}/Excited/vendor/Box2D/include"

IncludeDir["GLFW"] = "%{wks.location}/Excited/vendor/GLFW/include"
IncludeDir["Glad"] = "%{wks.location}/Excited/vendor/Glad/include"

IncludeDir["assimp"] = "%{wks.location}/Excited/vendor/assimp/include"
IncludeDir["ImGui"] = "%{wks.location}/Excited/vendor/Imgui"
IncludeDir["ImGuizmo"] = "%{wks.location}/Excited/vendor/ImGuizmo"
IncludeDir["glm"] = "%{wks.location}/Excited/vendor/glm"
IncludeDir["entt"] = "%{wks.location}/Excited/vendor/entt/include"
IncludeDir["magic_enum"] = "%{wks.location}/Excited/vendor/magic_enum/include"

LibraryDir = {}

Library = {}

-- Windows
Library["WinSock"] = "Ws2_32.lib"
Library["WinMM"] = "Winmm.lib"
Library["WinVersion"] = "Version.lib"
Library["BCrypt"] = "Bcrypt.lib"
