#include <iostream>

void fizzbuzz(int end) {
  for (int i { 1 }; i <= end; ++i) {
    const bool divisible_3 { i % 3 == 0 };
    const bool divisible_5 { i % 5 == 0 };

    if (divisible_3 && divisible_5) {
      std::cout << "fizzbuzz";
    }
    else if (divisible_3) {
      std::cout << "fizz";
    }
    else if (divisible_5) {
      std::cout << "buzz";
    }
    else {
      std::cout << i;
    }

    std::cout << '\n';
  }

}

int main() {
  fizzbuzz(15);

  return 0;
}
