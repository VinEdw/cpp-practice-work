#include <iostream>
#include <array>

template <typename T, std::size_t N>
void printArray(const std::array<T, N>& arr) {
  std::cout << "The array (";
  bool first { true };
  for (const auto& e: arr) {
    std::cout << (first ? "" : ", ");
    std::cout << e;
    first = false;
  }
  std::cout << ") has length " << N << '\n';
}

int main() {
    constexpr std::array arr1 { 1, 4, 9, 16 };
    printArray(arr1);

    constexpr std::array arr2 { 'h', 'e', 'l', 'l', 'o' };
    printArray(arr2);

    return 0;
}
