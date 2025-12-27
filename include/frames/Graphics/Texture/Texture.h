#pragma once

#include <string>

namespace frames {
using TextureHandle =
    decltype(std::declval<std::hash<std::string>>().operator()(""));

struct Texture {
 public:
  unsigned int width, height;
  std::string name;
};
}  // namespace frames
