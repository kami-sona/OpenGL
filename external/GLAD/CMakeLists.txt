add_libaray(GLAD ${PROJECT_SOURCE_DIR}/src/glad.c)

target_include_directories(GLAD
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR/includes}
          )	