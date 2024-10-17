#include <iostream>

void print(const char str[]) {
  while (*str != '\0') {
    std::cout << *str;
    ++str;
  }
}

void print_reverse(const char str[]) {
  const char* start { str };
  while (*str != '\0') {
    ++str;
  }
  while (str >= start) {
    std::cout << *str;
    --str;
  }
}

int main() {
  print("Hello, world!");
  std::cout << '\n';
  print_reverse("Hello, world!");
  std::cout << '\n';

  return 0;
}
