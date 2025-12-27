#pragma once

#include <array>

#include "frames/Graphics/Primitives/Rectangle.h"

namespace frames {
class FontDescriptor {
 public:
  FontDescriptor(std::string_view t_name) : name(t_name) {}

  // constructor with who knows what
  virtual float getCharacterWidth(char c) const noexcept = 0;
  virtual float getCharacterHeight() const noexcept = 0;
  virtual Rectangle getCharactureUv() const noexcept = 0;

  virtual ~FontDescriptor() noexcept = default;

  std::string_view name;
};
}  // namespace frames