#pragma once

#include "frames/Graphics/Primitives/Primitive.h"

struct DrawCommand {
  PrimitiveType primitive;
  struct Range {
    unsigned begin, end;
  } vertices, indices;
};