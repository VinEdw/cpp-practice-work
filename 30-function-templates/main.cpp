#include <iostream>
#include "Math.h"

int main() {
  // Add two values of the same type
  std::cout << "add()\n";
  std::cout << add(2, 3) << '\n';
  std::cout << add(1.2, 3.4) << '\n';

  // Multiply one value of any type (first parameter) and an integer (second parameter)
  // Return the same type as the first parameter
  std::cout << "mult()\n";
  std::cout << mult(2, 3) << '\n';
  std::cout << mult(1.2, 3) << '\n';

  // Subtract two values of different types
  std::cout << "sub()\n";
  std::cout << sub(3, 2) << '\n';
  std::cout << sub(3.5, 2) << '\n';
  std::cout << sub(4, 1.5) << '\n';

  return 0;
}
