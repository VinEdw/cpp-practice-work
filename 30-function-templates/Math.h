#ifndef MATH_H
#define MATH_H

template <typename T>
T add(T x, T y) {
  return x + y;
}

template <typename T>
T mult(T x, int y) {
  return x * y;
}

template <typename T, typename U>
auto sub(T x, U y) {
  return x - y;
}

#endif
