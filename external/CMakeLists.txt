set(ImguiPath "${CMAKE_CURRENT_SOURCE_DIR}/imgui")
set(GLADPath "${CMAKE_CURRENT_SOURCE_DIR}/GLAD")


add_library(GLAD ${GLADPath}/src/glad.c)

add_library(Imgui ${ImguiPath}/imgui_demo.cpp
			${ImguiPath}/imgui_draw.cpp
			${ImguiPath}/imgui_tables.cpp
			${ImguiPath}/imgui_widgets.cpp
			${ImguiPath}/imgui.cpp)

target_include_directories(GLAD
          PUBLIC ${GLADPath}/includes
          )

target_include_directories(Imgui
          PUBLIC ${ImguiPath}
          )