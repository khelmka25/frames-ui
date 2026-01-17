
#include <iostream>
#include <memory>

#include "frames/Graphics/OpenGL/RendererOpenGL.h"
#include "frames/Graphics/OpenGL/TextureOpenGL.h"
#include "frames/Graphics/Texture/TextureDescriptor.h"
#include "frames/Graphics/SpriteSheet/SpriteSheet.h"
#include "tools/image.h"

int main() {
  // this creates a window
  frames::RendererOpenGL renderer{};
  // create a context object
  frames::Context ctx;

  frames::vec2f size{};

  // an openGL texture object
  frames::TextureOpenGL texture(1200u, 800u, 3u, const_cast<char*>(data));
  const auto& descriptor = texture.getTextureDescriptor();

  // create a sprite from the 
  const auto sprite1 = descriptor.createSprite({100, 100}, {600, 600});
  
  ctx.clear();

  // ctx.beginTriangles();
  // ctx.drawRect({0, 0}, {1, 1});
  // ctx.drawRect({-1, -1}, {0, 0});
  // ctx.endTriangles();

  // ctx.beginLines();
  // ctx.drawLine({-0.5f, 0.5f}, {0, 0});
  // ctx.endLines();

  // ctx.beginTriangles();
  // ctx.drawRect({0, 0}, {20, 20});
  // ctx.drawRect({20, 20}, {40, 40});
  // ctx.drawRect({0,0}, {1, 1});
  // ctx.constructRect({0, 0}, {20, 20}, sprite1);
  // ctx.endTriangles();

  using namespace std::literals::string_view_literals;

  renderer.shader.registerUniform("projection"sv);
  renderer.shader.registerUniform("sprite_sheet"sv);

  // steps to use a texture...

  int textureSlot = 0;

  // this step is not necessary in a loop
  // 1. activate texture slot 0
  glActiveTexture(GL_TEXTURE0 + textureSlot);
  // 2. bind the target texture to texture 0
  glBindTexture(GL_TEXTURE_2D, texture.getNativeHandle());

  // this step is only necessary if using more than one texture...
  // 3. set the uniform variable to use texture slot 0
  renderer.shader.setInt("sprite_sheet"sv, textureSlot);

  ctx.pushTexture(0);
  ctx.beginTriangles();
  // using namespace std::string_view_literals;
  // ctx.drawString({60.f, 60.f}, "string_view"sv);
  ctx.constructRect({0, 0}, {200, 200}, frames::Color(1,1,1,1), sprite1);
  ctx.endTriangles();
  // ctx.popTexture();

  renderer.build(&ctx);

  while (renderer.isOpen()) {
    renderer.draw(&ctx);
  }

  return 0;
};