# Set the minimum required version of CMake
cmake_minimum_required(VERSION 3.15)

# Project name
project(ZPGCV1)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ------------------------------------------------------------------
# STEP A: FIND LIBRARIES (The macOS / Homebrew way)
# ------------------------------------------------------------------
# This tells CMake to find the libraries you installed with "brew install"
find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)
find_package(GLM REQUIRED) # This finds the include path

# ------------------------------------------------------------------
# STEP B: FIND YOUR SOURCE FILES
# ------------------------------------------------------------------
# This fixes your "No SOURCES" error from before.
# We are now inside ZPG_CV_1, so we just look for "*.cpp".
file(GLOB SOURCES "*.cpp")
file(GLOB HEADERS "*.h" "Models/*.h")

# ------------------------------------------------------------------
# STEP C: CREATE THE EXECUTABLE
# ------------------------------------------------------------------
# Create an executable "ZPG_App" from your sources
add_executable(ZPG_App ${SOURCES} ${HEADERS})

# ------------------------------------------------------------------
# STEP D: SPECIFY INCLUDE DIRECTORIES
# ------------------------------------------------------------------
# We tell the compiler where to find all .h files
target_include_directories(ZPG_App PRIVATE
        # --- Your project's includes (in this folder and /Models) ---
        "${CMAKE_CURRENT_SOURCE_DIR}"
        "${CMAKE_CURRENT_SOURCE_DIR}/Models"

        # --- Header-only libs from External ---
        "${CMAKE_CURRENT_SOURCE_DIR}/External/tinyobjloader-release"

        # --- Includes from Homebrew libs (found by find_package) ---
        ${GLEW_INCLUDE_DIRS}
        ${glfw3_INCLUDE_DIRS}
        ${GLM_INCLUDE_DIRS}  # <-- This is all GLM needs!
)

# ------------------------------------------------------------------
# STEP E: LINK LIBRARIES
# ------------------------------------------------------------------
# We link GLEW, GLFW, and OpenGL.
# GLM::GLM has been REMOVED because it is header-only.
target_link_libraries(ZPG_App PRIVATE
        # Libraries from Homebrew
        GLEW::GLEW
        glfw

        # Standard OpenGL framework on macOS
        "-framework OpenGL"
)

# ------------------------------------------------------------------
# STEP F: COPY SHADERS
# ------------------------------------------------------------------
# Copies your "ShaderSource" folder to the build folder
# (Path is now relative to this folder)
# ------------------------------------------------------------------
add_custom_command(TARGET ZPG_App POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${CMAKE_CURRENT_SOURCE_DIR}/ShaderSource"
        $<TARGET_FILE_DIR:ZPG_App>/ShaderSource
        COMMENT "Copying shaders to output directory"
)


# ------------------------------------------------------------------
# STEP G: COPY MODELS
# ------------------------------------------------------------------
# Copies your "Models" folder (containing .obj files)
# to the build directory so the app can find them.
# ------------------------------------------------------------------
add_custom_command(TARGET ZPG_App POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${CMAKE_CURRENT_SOURCE_DIR}/Models"
        $<TARGET_FILE_DIR:ZPG_App>/Models
        COMMENT "Copying models to output directory"
)