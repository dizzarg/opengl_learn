cmake_minimum_required(VERSION 3.28)
project(gl_test)

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME} main.cpp)

include_directories(submodule/glfw/include/)

# GLFW include
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)
add_subdirectory(submodule/glfw)

target_link_libraries(${PROJECT_NAME} PRIVATE glfw)

# GLAD
add_subdirectory(submodule/glad)
target_link_libraries(${PROJECT_NAME} PRIVATE glad)



