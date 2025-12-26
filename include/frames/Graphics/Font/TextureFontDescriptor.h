#pragma once

#include "frames/Graphics/Vector.h"
#include "frames/Graphics/Font/FontDescriptor.h"

#include <array>
#include <memory>

namespace frames {
class TextureFontDescriptor : public FontDescriptor {
 public:
  TextureFontDescriptor() : FontDescriptor("default"), characterHeight(8.f) {
    std::uninitialized_fill(std::begin(characterWidths), std::end(characterWidths), 8.0f);
    std::uninitialized_fill(std::begin(spriteOrigins), std::end(spriteOrigins), vec2f{});
  }

  virtual float getCharacterWidth(char c) const noexcept override {
    return characterWidths.at(c);
  }

  virtual float getCharacterHeight() const noexcept override {
    return characterHeight;
  }

 protected:
  std::array<float, 255> characterWidths;
  std::array<vec2f, 255> spriteOrigins;
  float characterHeight;
};
}  // namespace frames