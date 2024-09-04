#include <iostream>

void fizzbuzzpop(int end) {
  for (int i { 1 }; i <= end; ++i) {
    const bool divisible_3 { i % 3 == 0 };
    const bool divisible_5 { i % 5 == 0 };
    const bool divisible_7 { i % 7 == 0 };
    bool printed { false };

    if (divisible_3) {
      std::cout << "fizz";
      printed = true;
    }
    if (divisible_5) {
      std::cout << "buzz";
      printed = true;
    }
    if (divisible_7) {
      std::cout << "pop";
      printed = true;
    }
    if (!printed) {
      std::cout << i;
    }

    std::cout << '\n';
  }

}

int main() {
  fizzbuzzpop(150);

  return 0;
}
