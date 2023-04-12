cmake_minimum_required(VERSION 3.10)


project(LearnOpenGL)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(${PROJECT_SOURCE_DIR}/external/glfw ${PROJECT_SOURCE_DIR}/external/GLAD)


target_link_libraries(${PROJECT_NAME} PUBLIC glfw)