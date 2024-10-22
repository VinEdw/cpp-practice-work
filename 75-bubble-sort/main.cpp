#include <iostream>
#include <iterator>

int main() {
  int array[] { 6, 3, 2, 9, 7, 1, 5, 4, 8 };
  constexpr int length { std::size(array) };

  for (int end { length - 1 }; end >= 0; --end) {
    bool swapped { false };
    for (int i { 0 }; i < end; ++i) {
      if (array[i] > array[i + 1]) {
        std::swap(array[i], array[i + 1]);
        swapped = true;
      }
    }

    if (!swapped) {
      break;
    }
  }

  for (int e : array) {
    std::cout << e << ' ';
  }
  std::cout << '\n';

  return 0;
}
