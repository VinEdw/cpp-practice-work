#include <iostream>

// Sum all the integers from 1 to value
constexpr int sumTo(int value) {
  int sum { 0 };

  for (int i { 1 }; i <= value; ++i) {
    sum += i;
  }

  return sum;
}

int main() {
  std::cout << sumTo(5) << '\n';

  return 0;
}

