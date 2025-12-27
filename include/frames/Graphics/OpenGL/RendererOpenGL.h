#pragma once

#include "frames/Graphics/Context.h"
#include "frames/Graphics/OpenGL/ShaderOpenGL.h"
#include "frames/Graphics/OpenGL/ContextOpenGL.h"
#include "frames/Graphics/OpenGL/RendererOpenGL.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <string_view>

namespace frames {
class RendererOpenGL {
 public:
  RendererOpenGL();
  ~RendererOpenGL() noexcept;

 public:
  virtual void build(Context* ctx);
  virtual void draw(Context* ctx) noexcept(false);
  virtual bool isOpen() noexcept;

 protected:
  ContextOpenGL contextOpenGL;
  ShaderOpenGL shader;

  unsigned vertexBufferHandle;
  unsigned vertexArrayHandle;

  unsigned indexBufferHandle;
};
}  // namespace frames