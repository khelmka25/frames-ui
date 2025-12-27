#pragma once

namespace frames {
template <typename T>
struct vec2 {
  vec2() = default;
  vec2(T t_x, T t_y) : x(t_x), y(t_y) {}

  T x,y;
  // union {
  //   T x, r, s;
  // };
  // union {
  //   T y, g, t;
  // };
};

using vec2f = vec2<float>;
using vec2i = vec2<signed int>;
using vec2u = vec2<unsigned int>;

template <typename T>
struct vec3 {
  vec3() = default;
  vec3(T t_x, T t_y, T t_z) : x(t_x), y(t_y), z(t_z) {}
  vec3(vec2<T> t_vec2) : x(t_vec2.x), y(t_vec2.y), z(T{}) {}

  T x,y,z;
  // union {
  //   T x, r, s;
  // };
  // union {
  //   T y, g, t;
  // };
  // union {
  //   T z, b, u;
  // };
};

using vec3f = vec3<float>;
using vec3i = vec3<signed int>;
using vec3u = vec3<unsigned int>;

template <typename T>
struct vec4 {
  vec4() = default;
  vec4(T t_x, T t_y, T t_z, T t_w) : x(t_x), y(t_y), z(t_z), w(t_w) {}

  T x,y,z,w;
};

using vec4f = vec4<float>;
using vec4i = vec4<signed int>;
using vec4u = vec4<unsigned int>;

}  // namespace frames
