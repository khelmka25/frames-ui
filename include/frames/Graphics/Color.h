#pragma once

#include <cstdint>

namespace frames {
struct Color {
  float r, g, b, a;

  Color(std::uint32_t hex) {
    r = float((hex & 0x0000fful) >> 0x00) / 255.f;
    g = float((hex & 0x00ff00ul) >> 0x08) / 255.f;
    b = float((hex & 0xff0000ul) >> 0x10) / 255.f;
    a = float((hex & 0xff0000ul) >> 0x18) / 255.f;
  }

  Color(float red, float green, float blue, float alpha)
      : r(red), g(green), b(blue), a(alpha) {}
};
}  // namespace frames