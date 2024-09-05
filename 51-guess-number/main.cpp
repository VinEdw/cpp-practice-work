#include <iostream>
#include <iomanip>

constexpr int g_bit_count { 5 };
constexpr int g_max_val { 32 };
constexpr int g_max_num_width { 2 };
constexpr int g_nums_per_row { 4 };

bool get_y_or_n() {
  while (true) {
    std::cout << "(y/n): ";
    char c{};
    std::cin >> c;

    if (c == 'y') {
      return true;
    }
    else if (c == 'n') {
      return false;
    }
  }
}

void print_num(int num) {
  std::cout << std::setw(g_max_num_width) << num;
}

bool num_uses_bit(int num, int bit) {
  return num & (1 << bit);
}

void print_grid(int bit) {
  int count { 0 };
  for (int num { 0 }; num < g_max_val; ++num) {
    if (num_uses_bit(num, bit)) {
      ++count;
      print_num(num);
      if ((count != 0) && (count % g_nums_per_row == 0)) {
        std::cout << '\n';
      }
      else {
        std::cout << ' ';
      }
    }
  }
}

int main() {
  std::cout << "Think of a number between 0 and " << g_max_val - 1 << ".\n";

  int result { 0 };
  for (int bit { 0 }; bit < g_bit_count; ++bit) {
    std::cout << "Is the number in the following set?\n\n";
    print_grid(bit);
    std::cout << '\n';
    bool y_or_n { get_y_or_n() };
    result |= (y_or_n << bit);
  }

  std::cout << "Your number is " << result << '\n';
  return 0;
}
