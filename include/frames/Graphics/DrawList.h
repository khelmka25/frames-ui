
#include "frames/Graphics/Vertex.h"
#include "frames/Graphics/Primitives/Primitive.h"
#include "frames/Graphics/DrawCommand.h"
#include "frames/Graphics/SpriteSheet/Sprite.h"

#include <vector>

namespace frames {
struct DrawList {
 public:
  DrawList() = default;

 public:
  void constructRect(vec2f tl, vec2f br);
  void constructRect(vec2f tl, vec2f br, Sprite sp);
  void constructQuad(vec2f p0, vec2f p1, vec2f p2, vec2f p3);
  void constructQuad(Vertex v0, Vertex v1, Vertex v2, Vertex v3);
  void constructColoredQuad();
  void constructTexturedQuad();
  void constructLine(vec2f p1, vec2f p2, float thickness);
  void constructCircle(vec2f center, float radius, unsigned int count = 8u);

public:
  void clear();

  void beginPoints();
  void endPoints();

  void beginTriangles();
  void endTriangles();

  void beginLines();
  void endLines();

  void begin(PrimitiveType type);
  void end();

  void pushTexture(unsigned textureHandle);
  void popTexture();

  unsigned currentIndex = 0;
  unsigned currentVertex = 0;

  std::vector<unsigned> indices;
  std::vector<Vertex> vertices;
  std::vector<DrawCommand> commands;
};
}  // namespace frames
