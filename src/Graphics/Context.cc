#include "frames/Graphics/Context.h"

#include <stdexcept>
#include <utility>

#include "frames/Graphics/Primitives/Rectangle.h"

using namespace frames;

void Context::drawRect(vec2f tl, vec2f br) {
  constructRect(tl, br);
}

void Context::drawRectOutline(vec2f tl, vec2f br) {
  throw std::runtime_error("Not implemented");
}

void Context::drawRectOutline() {
  throw std::runtime_error("Not implemented");
}

void Context::drawRectRounded(vec2f tl, vec2f br) {}

void Context::drawRectRounded() {
  throw std::runtime_error("Not implemented");
}

void Context::drawLine(vec2f p1, vec2f p2) {
  constructLine(p1, p2, 1.f);
}

void Context::drawLine(vec2f* points, unsigned int count) {
  if (std::cmp_less(count, 2u)) {
    throw std::runtime_error("Count must be gte 2");
  }

  for (unsigned i{}; i < (count - 1u); i++) {
    auto& p1 = points[i + 0u];
    auto& p2 = points[i + 1u];
    constructLine(p1, p2, 1.f);
  }
}

void Context::drawQuad(vec2f tl, vec2f tr, vec2f br, vec2f bl) {
  constructQuad(tl, tr, br, bl);
}

void Context::drawQuadOutline(vec2f tl, vec2f tr, vec2f br, vec2f bl) {
  throw std::runtime_error("Not implemented");
}

void Context::drawCharacter(vec2f pos, char c) {
  // draw a quad at the given position with a texture uv of the given character
  std::unique_ptr<FontDescriptor>& descriptor = this->fontDescriptor;
  // Rectangle shown on screen
  Rectangle rect{};
  rect.origin = pos;
  // width and height of the character
  rect.width = descriptor->getCharacterWidth(c);
  rect.height = descriptor->getCharacterHeight();
  // UV coordinates of character texture
  Rectangle uv = descriptor->getCharactureUv();
  // Construct a textured rect
}

void Context::drawString(vec2f pos, std::string_view str) {
  std::unique_ptr<FontDescriptor>& descriptor = this->fontDescriptor;
  // iterate over the string here, incrementing the position
  for (std::size_t i{}; i < str.size(); i++) {
    auto& c = str.at(i);
    drawCharacter(pos, c);
  }
}

void Context::drawStringWrapped(vec2f pos, std::string_view text, float width) {
  throw std::runtime_error("Not implemented");
}

