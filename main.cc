
#include <memory>
#include <iostream>

#include "frames/Graphics/OpenGL/RendererOpenGL.h"

int main() {
  // this creates a window
  frames::RendererOpenGL renderer{};
  // create a context object
  frames::Context ctx;

  ctx.clear();

  ctx.beginTriangles();
  ctx.drawRect({0, 0}, {1, 1});
  ctx.drawRect({-1, -1}, {0, 0});
  ctx.endTriangles();

  ctx.beginLines();
  ctx.drawLine({-0.5f, 0.5f}, {0, 0});
  ctx.endLines();

  renderer.build(&ctx);

  while (renderer.isOpen()) {
    renderer.draw(&ctx);
  }

  return 0;
};