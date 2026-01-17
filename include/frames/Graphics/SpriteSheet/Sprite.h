#pragma once

#include "frames/Graphics/Primitives/Rectangle.h"

namespace frames {
struct Sprite {
 public:
  Sprite() = default;
  Rectangle uv;
};
}  // namespace frames