set(IMGUIPATH "${CMAKE_CURRENT_SOURCE_DIR}/imgui")
set(GLADPATH "${CMAKE_CURRENT_SOURCE_DIR}/GLAD")
set(STBPATH "${CMAKE_CURRENT_SOURCE_DIR}/stb")

add_library(GLAD ${GLADPATH}/src/glad.c)

add_library(Imgui ${IMGUIPATH}/imgui_demo.cpp
			${IMGUIPATH}/imgui_draw.cpp
			${IMGUIPATH}/imgui_tables.cpp
			${IMGUIPATH}/imgui_widgets.cpp
			${IMGUIPATH}/imgui.cpp
			${IMGUIPATH}/backends/imgui_impl_opengl3.cpp
			${IMGUIPATH}/backends/imgui_impl_glfw.cpp)

target_include_directories(GLAD
          PUBLIC ${GLADPATH}/includes
)

target_include_directories(Imgui
	PUBLIC ${IMGUIPATH}
	PUBLIC ${IMGUIPATH}/backends
)

target_include_directories(${PROJECT_NAME}
	PUBLIC ${STBPATH}
)

target_link_libraries(Imgui PUBLIC glfw)


