
#include "frames/Graphics/Vector.h"

namespace frames {
struct Vertex {
  Vertex() = default;
  Vertex(vec3f t_pos, vec3f t_col = vec3f{1.f, 1.f, 1.f}, vec2f t_tex = vec2f{0.f, 0.f})
      : position(t_pos), color(t_col), texture(t_tex) {}

  vec3f position;
  vec3f color;
  vec2f texture;
};
}  // namespace frames