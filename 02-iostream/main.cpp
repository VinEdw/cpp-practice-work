#include <iostream>

int main() {
  std::cout << "Enter a number: ";

  int x{};
  int y{};
  std::cin >> x >> y;

  std::cout << "Your first number, " << x << ", equals " << x*x << " when squared.\n";
  std::cout << "When you subtract your second number, " << y << ", it equals " << x*x - y << "\n.";

  return 0;
}
