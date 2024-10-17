#include <iostream>
#include <array>
#include <cstddef>

template <typename T, std::size_t Row, std::size_t Col>
using Array2d = std::array<std::array<T, Col>, Row>;

template <typename T, std::size_t Row, std::size_t Col>
constexpr std::ptrdiff_t row_length(const Array2d<T, Row, Col>&) {
  return Row;
}

template <typename T, std::size_t Row, std::size_t Col>
constexpr std::ptrdiff_t col_length(const Array2d<T, Row, Col>&) {
  return Col;
}

template <typename T, std::size_t Row, std::size_t Col>
void print_array(const Array2d<T, Row, Col>& arr) {
  for (const auto& row : arr) {
    for (const auto& e : row) {
      std::cout << e << ' ';
    }
    std::cout << '\n';
  }
}

int main() {
  Array2d<int, 3, 4> arr {{
    { 1, 2, 3, 4 },
    { 5, 6, 7, 8 },
    { 9, 10, 11, 12 },
  }};

  std::cout << "Rows: " << row_length(arr) << '\n';
  std::cout << "Columns: " << col_length(arr) << '\n';
  std::cout << "Array:\n";
  print_array(arr);

  return 0;
}
