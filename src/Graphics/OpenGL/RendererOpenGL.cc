#include "frames/Graphics/OpenGL/RendererOpenGL.h"
#include "frames/Graphics/OpenGL/ContextOpenGL.h"

#include <stdexcept>
#include <iostream>
#include <utility>

using namespace frames;

using namespace std::literals::string_view_literals;

RendererOpenGL::RendererOpenGL()
    : contextOpenGL("OpenGL Window", {640u, 360u}),
      shader("assets/shaders/vertex.glsl", "assets/shaders/fragment.glsl") {
  // generate and set up vertex array
  glGenVertexArrays(1, &vertexArrayHandle);
  // https://registry.khronos.org/OpenGL-Refpages/gl4/html/glBindVertexArray.xhtml
  glBindVertexArray(vertexArrayHandle);

  // generate vertex buffer
  glGenBuffers(1, &vertexBufferHandle);
  glBindBuffer(GL_ARRAY_BUFFER, vertexBufferHandle);

  // 1. Position attributes of triangulation data: Takes up 2 floats: x, y
  // https://registry.khronos.org/OpenGL-Refpages/gl4/html/glVertexAttribPointer.xhtml
  glVertexAttribPointer(0u, 2u, GL_FLOAT, GL_FALSE, 8 * sizeof(float),
                        (void*)0);
  // https://registry.khronos.org/OpenGL-Refpages/gl4/html/glEnableVertexAttribArray.xhtml
  glEnableVertexArrayAttrib(vertexArrayHandle, 0u);

  // 2. Color attributes of triangulation data: Takes up 4 floats: r, g, b, a
  glVertexAttribPointer(1u, 4u, GL_FLOAT, GL_FALSE, 8 * sizeof(float),
                        (void*)(2 * sizeof(float)));
  glEnableVertexArrayAttrib(vertexArrayHandle, 1u);

  // 3. Texture uv of triangulation data: Takes up 2 floats: u, v
  glVertexAttribPointer(2u, 2u, GL_FLOAT, GL_FALSE, 8 * sizeof(float),
                        (void*)(6 * sizeof(float)));
  glEnableVertexArrayAttrib(vertexArrayHandle, 2u);

  // generate index element buffer
  glGenBuffers(1u, &indexBufferHandle);

  glBindVertexArray(0u);
  glBindBuffer(GL_ARRAY_BUFFER, 0u);
}

RendererOpenGL::~RendererOpenGL() noexcept {
  glDeleteBuffers(1, &vertexBufferHandle);
  glDeleteVertexArrays(1, &vertexArrayHandle);
  glDeleteBuffers(1, &indexBufferHandle);
}

void RendererOpenGL::build(Context* ctx) {
  glBindVertexArray(vertexArrayHandle);

  // upload the vertex data
  glBindBuffer(GL_ARRAY_BUFFER, vertexBufferHandle);
  // https://registry.khronos.org/OpenGL-Refpages/gl4/html/glBufferData.xhtml
  glBufferData(GL_ARRAY_BUFFER, ctx->vertices.size() * sizeof(Vertex),
               &ctx->vertices.at(0), GL_DYNAMIC_DRAW);

  // upload the index element data
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferHandle);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, ctx->indices.size() * sizeof(unsigned),
               &ctx->indices.at(0), GL_DYNAMIC_DRAW);

  glBindVertexArray(0u);
}

void RendererOpenGL::draw(Context* ctx) noexcept(false) {
  glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // https://registry.khronos.org/OpenGL-Refpages/gl4/html/glDrawArrays.xhtml
  // void glDrawArrays( 	GLenum mode,
  // 	GLint first,
  // 	GLsizei count);

  // https://registry.khronos.org/OpenGL-Refpages/gl4/html/glDrawElements.xhtml
  // void glDrawElements( 	GLenum mode,
  // 	GLsizei count,
  // 	GLenum type,
  // 	const void * indices);

  shader.enable();

  glBindVertexArray(vertexArrayHandle);

  // context: iterate through all of the draw commands
  for (std::size_t i{}; i < ctx->commands.size(); i++) {
    const auto& cmd = ctx->commands.at(i);
    const unsigned mode = [](PrimitiveType type) {
      switch (type) {
        default:
        case PrimitiveType::kNone: {
          throw std::runtime_error("Invalid Primitive Type");
        }
        case PrimitiveType::kPoints: {
          return GL_POINTS;
        }
        case PrimitiveType::kLines: {
          return GL_LINES;
        }
        case PrimitiveType::kTriangles: {
          return GL_TRIANGLES;
        }
      }
    }(cmd.primitive);
    const unsigned count = (cmd.indices.end - cmd.indices.begin);
    // https://registry.khronos.org/OpenGL-Refpages/gl4/html/glDrawElements.xhtml
    glDrawElements(mode, count, GL_UNSIGNED_INT, (void*)(cmd.indices.begin * sizeof(unsigned)));
  }

  glBindVertexArray(0u);

  glfwSwapBuffers(contextOpenGL.window);
  glfwPollEvents();
}

bool frames::RendererOpenGL::isOpen() noexcept {
  return !glfwWindowShouldClose(contextOpenGL.window);
}