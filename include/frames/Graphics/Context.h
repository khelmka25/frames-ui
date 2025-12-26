#pragma once

#include <string_view>
#include <memory>

#include "frames/Graphics/DrawList.h"
#include "frames/Graphics/Font/FontDescriptor.h"
#include "frames/Graphics/Primitives/Primitive.h"
#include "frames/Graphics/DrawCommand.h"

namespace frames {
// Graphics Context
class Context : protected DrawList {
 public:
  Context() = default;

 public:
  // draw the following objects
  // Rectangle
  void drawRect(vec2f tl, vec2f br);
  // void drawRect(vec2f tl, vec2f dims);
  // Rectangle outline (uses lines)
  void drawRectOutline(vec2f tl, vec2f br);
  void drawRectOutline();
  // Rounded Rectangle (uses textures)
  void drawRectRounded(vec2f tl, vec2f br);
  void drawRectRounded();
  // Lines
  void drawLine(vec2f p1, vec2f p2);
  void drawLine(vec2f* points, unsigned int count);
  // Quads
  void drawQuad(vec2f tl, vec2f tr, vec2f br, vec2f bl);
  void drawQuadOutline(vec2f tl, vec2f tr, vec2f br, vec2f bl);
  // Text (use font texture)
  void drawCharacter(vec2f pos, char c);
  void drawString(vec2f pos, std::string_view text);
  void drawStringWrapped(vec2f pos, std::string_view text, float width);

 protected:
  std::vector<DrawCommand> commands;

 public:
  void beginPoints();
  void endPoints();

  void beginTriangles();
  void endTriangles();

  void beginLines();
  void endLines();

  void beginPrimitive(PrimitiveType type);
  void endPrimitive();

 public:
  // current font descriptor
  std::unique_ptr<FontDescriptor> fontDescriptor;

  void pushFont();
  void popFont();

  void pushTexture();
  void popTexture();
};
}  // namespace frames