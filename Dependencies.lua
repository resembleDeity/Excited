
-- Excited Dependencies

VULKAN_SDK = os.getenv("VULKAN_SDK")

IncludeDir = {}
IncludeDir["stb_image"] = "%{wks.location}/Excited/vendor/stb_image"
IncludeDir["Box2D"] = "%{wks.location}/Excited/vendor/Box2D/include"
IncludeDir["GLFW"] = "%{wks.location}/Excited/vendor/GLFW/include"
IncludeDir["Glad"] = "%{wks.location}/Excited/vendor/Glad/include"
IncludeDir["ImGui"] = "%{wks.location}/Excited/vendor/ImGui"
IncludeDir["ImGuizmo"] = "%{wks.location}/Excited/vendor/ImGuizmo"
IncludeDir["glm"] = "%{wks.location}/Excited/vendor/glm"
IncludeDir["VulkanSDK"] = "%{VULKAN_SDK}/include"

Library = {}

-- Windows
Library["WinSock"] = "Ws2_32.lib"
Library["WinMM"] = "Winmm.lib"
Library["WinVersion"] = "Version.lib"
Library["BCrypt"] = "Bcrypt.lib"