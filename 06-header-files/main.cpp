#include "add.h"
#include "input.h"
#include <iostream>

int main() {
  int x { getInteger() };
  int y { getInteger() };

  std::cout << x << " + " << y << " = " << add(x, y) << '\n';
  return 0;
}
