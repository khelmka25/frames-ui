#pragma once

#include "frames/Graphics/Vector.h"

namespace frames {
struct Rectangle {
 public:
  vec2f origin;
  float width, height;

 public:
  vec2f topleft() const noexcept { return origin; }
  vec2f topright() const noexcept { return vec2f{origin.x + width, origin.y}; }

  vec2f bottomright() const noexcept {
    return vec2f{origin.x + width, origin.y + height};
  }
  vec2f bottomleft() const noexcept {
    return vec2f{origin.x, origin.y + height};
  }

  vec2f left() const noexcept {
    return vec2f{origin.x, origin.y + height / 2.0f};
  }
  vec2f right() const noexcept {
    return vec2f{origin.x + width, origin.y + height / 2.0f};
  }

  vec2f top() const noexcept {
    return vec2f{origin.x + width / 2.0f, origin.y};
  }
  vec2f bottom() const noexcept {
    return vec2f{origin.x + width / 2.0f, origin.y + height};
  }

  vec2f center() const noexcept {
    return vec2f{origin.x + width / 2.0f, origin.y + height / 2.0f};
  }
};
}  // namespace frames