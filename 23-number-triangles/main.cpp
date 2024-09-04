#include <iostream>

void print_upper_left_triangle(int max_val) {
  int outer { max_val };
  while (outer >= 1) {
    int inner { outer };
    while (inner >= 1) {
      std::cout << inner << ' ';
      --inner;
    }
    std::cout << '\n';
    --outer;
  }
}

void print_lower_right_triangle(int max_val, char filler) {
  int outer { 1 };
  while (outer <= max_val) {
    int inner { max_val };
    while (inner >= 1) {
      if (inner <= outer) {
        std::cout << inner << ' ';
      }
      else {
        std::cout << filler << ' ';
      }
      --inner;
    }
    std::cout << '\n';
    ++outer;
  }
}

int main() {
  constexpr int max_val { 5 };
  
  print_upper_left_triangle(max_val);
  std::cout << '\n';
  print_lower_right_triangle(max_val, ' ');
  std::cout << '\n';
  print_lower_right_triangle(max_val, 'X');

  return 0;
}
