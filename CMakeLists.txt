cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)



project(LearnOpenGL)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})


aux_source_directory(${PROJECT_SOURCE_DIR}/src DIR_SRCS)
add_executable(${PROJECT_NAME} ${DIR_SRCS})

add_subdirectory(${PROJECT_SOURCE_DIR}/external/glfw)
add_subdirectory(${PROJECT_SOURCE_DIR}/external/eigen)
add_subdirectory(${PROJECT_SOURCE_DIR}/external)

find_package (Eigen3 3.3 REQUIRED NO_MODULE)

add_dependencies(Imgui glfw)

target_include_directories(LearnOpenGL
          PUBLIC ${PROJECT_SOURCE_DIR}/include
          )

target_link_libraries(${PROJECT_NAME} PUBLIC glfw GLAD Imgui Eigen3::Eigen)