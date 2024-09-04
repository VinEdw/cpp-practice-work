#include <iostream>

char char_input() {
  std::cout << "Enter a single character: ";
  char x{};
  std::cin >> x;
  return x;
}

int main() {
  char ch { char_input() };
  std::cout << "You entered '" << ch << "', which has ASCII code " << static_cast<int>(ch) << ".\n";

  return 0;
}
