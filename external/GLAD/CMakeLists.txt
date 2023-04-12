add_libaray(GLAD ${CMAKE_CURRENT_SOURCE_DIR}/src/glad.c)

target_include_directories(GLAD
          PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/includes
          )	