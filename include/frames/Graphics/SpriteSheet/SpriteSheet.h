#pragma once

#include "frames/Graphics/SpriteSheet/Sprite.h"

// utility to map sprites to
namespace frames {
struct SpriteSheet {
 public:
  SpriteSheet() = default;
  SpriteSheet(float t_width, float t_height) : width(t_width), height(t_height) {}

  // 2 position creation
  Sprite createSprite2p(vec2f bl, vec2f tr) {
    Sprite output{};
    // convert to unit coords
    output.uv.origin.x = bl.x / width;
    output.uv.origin.y = bl.y / height;
    output.uv.width = (tr.x - bl.x) / width;
    output.uv.height = (tr.y - bl.y) / height;
    return output;
  }

  // position and size creation
  Sprite createSpritePs(vec2f bl, vec2f size) { 
    Sprite output{};
    // convert to unit coords
    output.uv.origin.x = bl.x / width;
    output.uv.origin.y = bl.y / height;
    output.uv.width = size.x / width;
    output.uv.height = size.y / height;
    return output;
  }

  float width, height;
};
}  // namespace frames