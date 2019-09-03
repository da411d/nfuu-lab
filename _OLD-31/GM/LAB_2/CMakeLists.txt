cmake_minimum_required(VERSION 3.14)
project(LAB_2)

set(CMAKE_CXX_STANDARD 14)

add_executable(LAB_2 main.cpp)

SET(GLUT_INCLUDE_DIR %WINDIR%\\system32)
SET(GLUT_LIBRARY %WINDIR%\\system32)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )

target_link_libraries(LAB_2 ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )