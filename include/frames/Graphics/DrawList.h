
#include <vector>

#include "frames/Graphics/DrawCommand.h"
#include "frames/Graphics/Primitives/Primitive.h"
#include "frames/Graphics/Primitives/Rectangle.h"
#include "frames/Graphics/Vertex.h"

namespace frames {
struct DrawList {
 public:
  DrawList() = default;

 public:
  void clear();

  void beginPoints();
  void endPoints();

  void beginTriangles();
  void endTriangles();

  void beginLines();
  void endLines();

  void pushTexture(unsigned textureHandle);
  void popTexture();

 protected:
  void begin(PrimitiveType type);
  void end();

 public:
  void constructRect(vec2f tl, vec2f br);
  void constructRect(vec2f tl, vec2f br, Rectangle sp);
  void constructRect(vec2f tl, vec2f br, Color c);
  void constructRect(vec2f tl, vec2f br, Color c, Rectangle sp);

 protected:
  // counter-clockwise winding order
  // v0---v1
  // |t0/t1|
  // v3---v2
  void constructQuad(Vertex v0, Vertex v1, Vertex v2, Vertex v3);

 public:
  void constructLine(vec2f p0, vec2f p1);
  void constructLine(vec2f p0, vec2f p1, Color c);

 protected:
  void constructLine(vec2f p1, vec2f p2, Color c, float thickness);

 public:
  void constructCircle(vec2f center, float radius, unsigned int count = 8u);

 protected:
  unsigned currentIndex = 0;
  unsigned currentVertex = 0;

 public:
  std::vector<unsigned> indices;
  std::vector<Vertex> vertices;
  std::vector<DrawCommand> commands;
};
}  // namespace frames
