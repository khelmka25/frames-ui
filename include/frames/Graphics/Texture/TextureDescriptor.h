#pragma once

#include "frames/Graphics/Primitives/Rectangle.h"

namespace frames {
struct TextureDescriptor {
 public:
  TextureDescriptor() = default;
  TextureDescriptor(float t_width, float t_height)
      : width(t_width), height(t_height) {}

  // 2 position creation
  Rectangle createSprite(vec2f bl, vec2f tr) const {
    Rectangle output{};
    // convert to unit coords
    output.origin.x = bl.x / width;
    output.origin.y = bl.y / height;
    output.width = (tr.x - bl.x) / width;
    output.height = (tr.y - bl.y) / height;
    return output;
  }

  // position and size creation
  Rectangle createSpritePs(vec2f bl, vec2f size) const {
    Rectangle output{};
    // convert to unit coords
    output.origin.x = bl.x / width;
    output.origin.y = bl.y / height;
    output.width = size.x / width;
    output.height = size.y / height;
    return output;
  }

  float width, height;
};
}  // namespace frames
