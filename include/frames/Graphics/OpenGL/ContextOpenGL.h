#pragma once

#include "frames/Graphics/Vector.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <string_view>

namespace frames {
struct ContextOpenGL {
 public:
  ContextOpenGL(std::string_view title, vec2u size) noexcept(false);
  ~ContextOpenGL() noexcept;

  GLFWwindow* window;
};
}  // namespace frames