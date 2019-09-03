cmake_minimum_required(VERSION 3.13)
project(LAB_1)

set(CMAKE_CXX_STANDARD 14)

add_executable(LAB_1 main.cpp)

SET(GLUT_INCLUDE_DIR %WINDIR%\\system32)
SET(GLUT_LIBRARY %WINDIR%\\system32)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )

target_link_libraries(LAB_1 ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )