cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_C_COMPILER "")
set(CMAKE_CXX_COMPILER "")

project(LearnOpenGL)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)


aux_source_directory(${PROJECT_SOURCE_DIR}/src DIR_SRCS)
add_executable(${PROJECT_NAME} ${DIR_SRCS})

add_subdirectory(${PROJECT_SOURCE_DIR}/external/glfw)
add_subdirectory(${PROJECT_SOURCE_DIR}/external)

add_dependencies(Imgui glfw)
target_include_directories(LearnOpenGL
          PUBLIC ${PROJECT_SOURCE_DIR}/include
          )

target_link_libraries(${PROJECT_NAME} PUBLIC glfw GLAD Imgui)