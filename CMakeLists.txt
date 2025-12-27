cmake_minimum_required(VERSION 3.20)
project(test_project)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(${CMAKE_SOURCE_DIR}/src)

# glfw
add_subdirectory(${CMAKE_SOURCE_DIR}/deps/glfw/)

# glad
add_library(glad STATIC ${CMAKE_SOURCE_DIR}/deps/glad/src/glad.c)
target_include_directories(glad PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/deps/glad/include
)

enable_testing()
add_subdirectory(${CMAKE_SOURCE_DIR}/tests)

add_executable(a main.cc)
target_link_libraries(a PUBLIC 
    frames
    glfw
    glad
)

target_compile_options(a PUBLIC -g)