
#include "frames/Graphics/Vertex.h"

#include <vector>

namespace frames {
struct DrawList {
public:
  DrawList() = default;

public:
  // everything is a rectangle lol
  void constructRect(vec2f tl, vec2f br);
  void constructQuad(vec2f p0, vec2f p1, vec2f p2, vec2f p3);
  void constructColoredQuad();
  void constructTexturedQuad();
  void constructLine(vec2f p1, vec2f p2, float thickness);
  void constructCircle(vec2f center, float radius, unsigned int count = 8u);

  using IndexType = unsigned int;
  IndexType currentIndex;
  IndexType currentVertex;

  std::vector<IndexType> indices;
  std::vector<Vertex> vertices;
};
}  // namespace frames
