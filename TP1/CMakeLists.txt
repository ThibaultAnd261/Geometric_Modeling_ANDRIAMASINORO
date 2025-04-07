cmake_minimum_required(VERSION 3.10)
project(MeshViewer)

set(CMAKE_CXX_STANDARD 17)

# GLM
find_package(glm REQUIRED)

# OpenGL
find_package(OpenGL REQUIRED)

# GLEW via config (Homebrew)
find_package(GLEW REQUIRED CONFIG)

# Force FreeGLUT depuis Homebrew (pas GLUT Apple !)
find_path(FREEGLUT_INCLUDE_DIR
    GL/freeglut.h
    PATHS /opt/homebrew/include
    NO_DEFAULT_PATH
)

find_library(FREEGLUT_glut_LIBRARY
    NAMES glut
    PATHS /opt/homebrew/lib
    NO_DEFAULT_PATH
)

if(NOT FREEGLUT_INCLUDE_DIR OR NOT FREEGLUT_glut_LIBRARY)
    message(FATAL_ERROR "❌ FreeGLUT not found in Homebrew paths. Run: brew install freeglut")
else()
    message(STATUS "✅ Using FreeGLUT from: ${FREEGLUT_glut_LIBRARY}")
endif()

# Includes
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${FREEGLUT_INCLUDE_DIR}
    ${OPENGL_INCLUDE_DIR}
)

# Fichiers sources
set(SOURCE_FILES
    main.cpp
    myHalfedge.cpp
    myVector3D.cpp
    myPoint3D.cpp
    myFace.cpp
    myMesh.cpp
    myVertex.cpp
)

# Cible exécutable
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

# Linking
target_link_libraries(${PROJECT_NAME}
    ${FREEGLUT_glut_LIBRARY}
    OpenGL::GL
    GLEW::GLEW
    glm::glm
)
