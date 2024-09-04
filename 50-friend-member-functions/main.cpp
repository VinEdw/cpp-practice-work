#include "Vector3d.h"
#include "Point3d.h"
#include <iostream>

int main() {
  Point3d p { 1.0, 2.0, 3.0 };
  Vector3d v { 2.0, 2.0, -3.0 };

  p.print();
  std::cout << "+\n";
  v.print();
  std::cout << "=\n";
  p.move_by_vector(v);
  p.print();
}
