#pragma once

#include "frames/Graphics/Color.h"
#include "frames/Graphics/Vector.h"

namespace frames {
struct Vertex {
  Vertex() = default;
  Vertex(vec2f t_pos, Color t_col = Color{1.f, 1.f, 1.f, 1.f}, vec2f t_tex = vec2f{0.f, 0.f})
      : position(t_pos), color(t_col), texture(t_tex) {
    texture.x = position.x;
    texture.y = position.y;
  }

  Vertex(vec2f t_pos, vec2f t_tex) : position(t_pos), color{1.f, 1.f, 1.f, 1.f}, texture(t_tex) {}

  vec2f position;
  Color color;
  vec2f texture;
};
}  // namespace frames