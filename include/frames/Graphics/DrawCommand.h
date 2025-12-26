#pragma once

#include "frames/Graphics/Primitives/Primitive.h"

struct DrawCommand {
  PrimitiveType primitive;
  unsigned int indexStart, indexEnd;
};