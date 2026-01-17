#include "frames/Graphics/DrawList.h"

#include <cassert>

#include "frames/Graphics/Primitives/Primitive.h"

using namespace frames;

void DrawList::clear() {
  currentIndex = 0;
  currentVertex = 0;

  indices.clear();
  vertices.clear();
  commands.clear();
}

void DrawList::beginPoints() {
  begin(PrimitiveType::kPoints);
}

void DrawList::endPoints() {
  end();
}

void DrawList::beginTriangles() {
  begin(PrimitiveType::kTriangles);
}

void DrawList::endTriangles() {
  end();
}

void DrawList::beginLines() {
  begin(PrimitiveType::kLines);
}

void DrawList::endLines() {
  end();
}

void DrawList::begin(PrimitiveType primitiveType) {
  DrawCommand command;
  switch (primitiveType) {
    case PrimitiveType::kLines:
      command.action = Action::kSwapPrimitiveLines;
      break;
    case PrimitiveType::kPoints:
      command.action = Action::kSwapPrimitivePoints;
      break;
    case PrimitiveType::kTriangles:
      command.action = Action::kSwapPrimitiveTriangles;
      break;
    default:
      command.action = Action::kNone;
      break;
  }
  command.indices.begin = indices.size();
  command.vertices.begin = vertices.size();
  commands.push_back(command);
}

void DrawList::end() {
  auto& command = commands.back();
  command.indices.end = indices.size();
  command.vertices.end = vertices.size();
}

void DrawList::pushTexture(unsigned textureHandle) {
  DrawCommand command;
  command.action = Action::kSwapTexture;
  command.texture = textureHandle;
  command.vertices.begin = vertices.size();
  commands.push_back(command);
}

void DrawList::popTexture() {
  auto& command = commands.back();
  command.indices.end = indices.size();
  command.vertices.end = vertices.size();
}

void DrawList::constructRect(vec2f bl, vec2f tr) {
  const Rectangle uv{};
  const Color color(1, 1, 1, 1);
  constructRect(bl, tr, color, uv);
}

void DrawList::constructRect(vec2f bl, vec2f tr, Rectangle uv) {
  const Color color(1, 1, 1, 1);
  constructRect(bl, tr, color, uv);
}

void DrawList::constructRect(vec2f bl, vec2f tr, Color color) {
  const Rectangle uv{};
  constructRect(bl, tr, color, uv);
}

void DrawList::constructRect(vec2f bl, vec2f tr, Color color, Rectangle uv) {
  // clockwise winding order
  // tr---tl
  // |t0/t1|
  // br---bl

  auto const uv_tr = uv.topright();
  auto const uv_bl = uv.bottomleft();

  Vertex v0({tr.x, tr.y}, color, {uv_tr.x, uv_tr.y});  // top right     (+ 0)
  Vertex v1({tr.x, bl.y}, color, {uv_tr.x, uv_bl.y});  // bottom right  (+ 1)
  Vertex v2({bl.x, bl.y}, color, {uv_bl.x, uv_bl.y});  // bottom left   (+ 2)
  Vertex v3({bl.x, tr.y}, color, {uv_bl.x, uv_tr.y});  // top left      (+ 3)

  constructQuad(v0, v1, v2, v3);
}

void frames::DrawList::constructQuad(Vertex v0, Vertex v1, Vertex v2,
                                     Vertex v3) {
  // counter-clockwise winding order
  // v0---v1
  // |t0/t1|
  // v3---v2

  // append 4 vertices:
  std::initializer_list<Vertex> nextVertices = {
      v0,  // + 0
      v1,  // + 1
      v2,  // + 2
      v3,  // + 3
  };
  std::copy(nextVertices.begin(), nextVertices.end(),
            std::back_inserter(vertices));

  currentVertex = currentVertex + nextVertices.size();

  // append 6 indices
  std::initializer_list<unsigned> nextIndices = {
      // triangle 0
      currentIndex + 0u,
      currentIndex + 1u,
      currentIndex + 3u,
      // triangle 1
      currentIndex + 1u,
      currentIndex + 2u,
      currentIndex + 3u,
  };

  std::copy(nextIndices.begin(), nextIndices.end(),
            std::back_inserter(indices));

  currentIndex = currentIndex + nextVertices.size();
}

void DrawList::constructLine(vec2f p0, vec2f p1) {
  const Color color(0xffff'ffff);
  const float thickness = 1.f;
  constructLine(p0, p1, color, thickness);
}

void DrawList::constructLine(vec2f p0, vec2f p1, Color color) {
  const float thickness = 1.f;
  constructLine(p0, p1, color, thickness);
}

void DrawList::constructLine(vec2f p1, vec2f p2, Color c, float thickness) {
  std::initializer_list<Vertex> nextVertices = {
      Vertex{p1},  // + 0
      Vertex{p2},  // + 1
  };
  std::copy(nextVertices.begin(), nextVertices.end(),
            std::back_inserter(vertices));

  currentVertex = currentVertex + nextVertices.size();

  // append 6 indices
  std::initializer_list<unsigned> nextIndices = {
      currentIndex + 0u,
      currentIndex + 1u,
  };

  std::copy(nextIndices.begin(), nextIndices.end(),
            std::back_inserter(indices));

  currentIndex = currentIndex + nextVertices.size();
}

void DrawList::constructCircle(vec2f center, float radius, unsigned int count) {

}
