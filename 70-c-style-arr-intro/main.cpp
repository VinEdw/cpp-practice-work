#include <iostream>

namespace ProgramData {
  constexpr int perfect_squares[] { 0, 1, 4, 9 }; 
}

bool check_if_perfect_square(int x) {
  for (const auto& e : ProgramData::perfect_squares) {
    if (x == e) {
      return true;
    }
  }
  return false;
}

int main() {
  while (true) {
    std::cout << "Enter a single digit integer, or -1 to quit: ";
    int x{};
    std::cin >> x;

    if (x == -1) {
      break;
    }
    
    std::cout << x << " is ";
    std::cout << (check_if_perfect_square(x) ? "" : "not");
    std::cout << " a perfect square\n\n";
  }

  std::cout << "Bye\n";

  return 0;
}
