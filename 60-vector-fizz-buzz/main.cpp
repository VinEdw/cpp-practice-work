#include <iostream>
#include <cassert>
#include <vector>
#include <string_view>

void fizzbuzz(int count) {
  static const std::vector divisors { 3, 5, 7, 11, 13, 17, 19 };
  static const std::vector<std::string_view> words { "fizz", "buzz", "pop", "bang", "jazz", "pow", "boom" };
  assert(divisors.size() == words.size() && "fizzbuzz: array sizes don't match");

  for (int i { 1 }; i <= count; ++i) {
    bool printed { false };

    for (std::size_t j { 0 }; j < divisors.size(); ++j) {
      if (i % divisors[j] == 0) {
        std::cout << words[j];
        printed = true;
      }
    }

    if (!printed) {
      std::cout << i;
    }

    std::cout << '\n';
  }
}

int main() {
  fizzbuzz(150);

  return 0;
}
