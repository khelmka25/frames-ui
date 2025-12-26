#pragma once

namespace frames {
template <typename T>
struct Vector2 {
  Vector2() = default;
  Vector2(T t_x, T t_y) : x(t_x), y(t_y) {}

  union {
    T x, r, s;
  };
  union {
    T y, g, t;
  };
};

using vec2f = Vector2<float>;
using vec2i = Vector2<int>;

template <typename T>
struct Vector3 {
  Vector3() = default;
  Vector3(T t_x, T t_y, T t_z) : x(t_x), y(t_y), z(t_z) {}
  Vector3(Vector2<T> t_vec2) : x(t_vec2.x), y(t_vec2.y), z(T{}) {}

  union {
    T x, r, s;
  };
  union {
    T y, g, t;
  };
  union {
    T z, b, u;
  };
};

using vec3f = Vector3<float>;
using vec3i = Vector3<int>;
}  // namespace frames
