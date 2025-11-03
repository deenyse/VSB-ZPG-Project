cmake_minimum_required(VERSION 3.15)
project(VSB-ZPG-Project)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ------------------------------------------------------------------
# STEP A: FIND LIBRARIES (macOS / Homebrew)
# ------------------------------------------------------------------
find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)
find_package(GLM REQUIRED)

# ------------------------------------------------------------------
# STEP B: SOURCE FILES
# ------------------------------------------------------------------
# Собираем все .cpp из корня и подпапок Classes
file(GLOB_RECURSE SOURCES
        "${CMAKE_CURRENT_SOURCE_DIR}/Source.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/tinyobjloader.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/Classes/*.cpp"
)

# Заголовки (.h, если нужно IDE-подсветке)
file(GLOB_RECURSE HEADERS
        "${CMAKE_CURRENT_SOURCE_DIR}/Classes/*.h"
)

# ------------------------------------------------------------------
# STEP C: EXECUTABLE
# ------------------------------------------------------------------
add_executable(ZPG_App ${SOURCES} ${HEADERS})

# ------------------------------------------------------------------
# STEP D: INCLUDE DIRECTORIES
# ------------------------------------------------------------------
target_include_directories(ZPG_App PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/Classes"
        "${CMAKE_CURRENT_SOURCE_DIR}/External"
        "${CMAKE_CURRENT_SOURCE_DIR}/External/tinyobjloader-release"
        ${GLEW_INCLUDE_DIRS}
        ${glfw3_INCLUDE_DIRS}
        ${GLM_INCLUDE_DIRS}
)

# ------------------------------------------------------------------
# STEP E: LINK LIBRARIES
# ------------------------------------------------------------------
target_link_libraries(ZPG_App PRIVATE
        GLEW::GLEW
        glfw
        "-framework OpenGL"
)

# ------------------------------------------------------------------
# STEP F: COPY SHADERS AND MODELS
# ------------------------------------------------------------------
add_custom_command(TARGET ZPG_App POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${CMAKE_CURRENT_SOURCE_DIR}/ShaderSource"
        $<TARGET_FILE_DIR:ZPG_App>/ShaderSource
        COMMENT "Copying shaders to output directory"
)

add_custom_command(TARGET ZPG_App POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${CMAKE_CURRENT_SOURCE_DIR}/Models"
        $<TARGET_FILE_DIR:ZPG_App>/Models
        COMMENT "Copying models to output directory"
)
