#pragma once

#include "frames/Graphics/Primitives/Primitive.h"

namespace frames {
enum class Action : unsigned {
  kNone,
  kSwapPrimitivePoints,
  kSwapPrimitiveLines,
  kSwapPrimitiveTriangles,
  kSwapTexture,
};

struct DrawCommand {
  Action action;
  unsigned texture;
  struct ElementRange {
    unsigned begin, end;
  } vertices, indices;
};
}  // namespace frames
