#include <iostream>

int get_integer() {
  std::cout << "Enter an integer: ";
  int x {};
  std::cin >> x;
  return x;
}

constexpr int factorial(int n) {
  if (n <= 0) return 1;
  return n * factorial(n - 1);
}

constexpr int digit_sum(int x) {
  if (x <= 10) return x;
  int digit { x % 10 };
  return digit + digit_sum(x / 10);
}

void print_binary(unsigned int x) {
  if (x < 1) return;
  print_binary(x / 2);
  std::cout << x % 2;
}

int main() {
  int x { get_integer() };
  print_binary(static_cast<unsigned int>(x));
  std::cout << '\n';

  return 0;
}
