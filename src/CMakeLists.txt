
# collect all source files for frames
file(GLOB_RECURSE FRAMES_SOURCE ${CMAKE_SOURCE_DIR}/src/*.cc)
# create a library object with these sources
add_library(frames STATIC ${FRAMES_SOURCE})
# add the header files
target_include_directories(frames 
  PUBLIC
  ${CMAKE_SOURCE_DIR}/include
  ${CMAKE_SOURCE_DIR}/deps/glfw/include
  ${CMAKE_SOURCE_DIR}/deps/glad/include
  ${CMAKE_SOURCE_DIR}/deps/glm/
)

target_compile_options(frames PUBLIC -g)