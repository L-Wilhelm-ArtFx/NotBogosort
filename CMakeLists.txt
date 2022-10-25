cmake_minimum_required(VERSION 3.15)
project(NotBogosort VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)

# add_subdirectory( src )

file( GLOB SOURCEFILES src/*.cpp )

add_executable(NotBogosort ${SOURCEFILES})

# target_link_libraries(OpenGLTraining game engine maths input ${GLEW_LIBRARIES} ${SDL2_LIBRARIES} OpenGL::GL OpenGL::GLU)
target_link_libraries(NotBogosort ${CMAKE_DL_LIBS})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)