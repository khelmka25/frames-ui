
#include "frames/Graphics/Vector.h"

namespace frames {
struct Vertex {
  Vertex() = default;
  Vertex(vec2f t_pos, vec4f t_col = vec4f{1.f, 1.f, 1.f, 1.f}, vec2f t_tex = vec2f{0.f, 0.f})
      : position(t_pos), color(t_col), texture(t_tex) {}

  vec2f position;
  vec4f color;
  vec2f texture;
};
}  // namespace frames