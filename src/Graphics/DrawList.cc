#include "frames/Graphics/DrawList.h"

#include <cassert>

using namespace frames;

void DrawList::constructRect(vec2f tl, vec2f br) noexcept {
  // counter-clockwise winding order
  // v0---v3
  // |t0/t1|
  // v1---v2
  const vec2f p0{tl.x, tl.y};  // + 0
  const vec2f p1{tl.x, br.y};  // + 1
  const vec2f p2{br.x, br.y};  // + 2
  const vec2f p3{br.x, tl.y};  // + 3

  constructQuad(p0, p1, p2, p3);
}

void frames::DrawList::constructQuad(vec2f p0, vec2f p1, vec2f p2, vec2f p3) {
  // counter-clockwise winding order
  // v0---v3
  // |t0/t1|
  // v1---v2

  // append 4 vertices:
  std::initializer_list<Vertex> nextVertices = {
      Vertex{p0},  // + 0
      Vertex{p1},  // + 1
      Vertex{p2},  // + 2
      Vertex{p3},  // + 3
  };
  std::copy(nextVertices.begin(), nextVertices.end(),
            std::next(std::begin(vertices), currentVertex));
  currentVertex = currentVertex + 4u;

  // append 6 indices
  std::initializer_list<IndexType> nextIndices = {
      // triangle 0
      currentIndex + 0u,
      currentIndex + 1u,
      currentIndex + 3u,
      // triangle 1
      currentIndex + 3u,
      currentIndex + 1u,
      currentIndex + 2u,
  };

  std::copy(nextIndices.begin(), nextIndices.end(),
            std::next(std::begin(indices), currentIndex));
  currentIndex = currentIndex + 6u;
}

void DrawList::constructLine(vec2f p1, vec2f p2, float thickness) {
  // build a rectangle between the two points for now lol
  constructRect(p1, p2);
}

void DrawList::constructCircle(vec2f center, float radius, unsigned int count) {

}
