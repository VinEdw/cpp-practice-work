#include <iostream>

int read_int() {
  std::cout << "Enter an integer: ";
  int x{};
  std::cin >> x;
  return x;
}

char read_operator() {
  std::cout << "Enter a mathematical operator (+, -, *, /, or %): ";
  char c{};
  std::cin >> c;
  return c;
}

int calculate(int x, int y, char operation) {
  switch(operation) {
    case '+':
      return x + y;
    case '-':
      return x - y;
    case '*':
      return x * y;
    case '/':
      return x / y;
    case '%':
      return x % y;
    default:
      std::cout << "Invalid operator\n";
      return 0;
  }
}

int main() {
  int x { read_int() };
  int y { read_int() };

  char operation { read_operator() };

  int result { calculate(x, y, operation) };

  std::cout << x << ' ' << operation << ' ' << y << " = " << result << '\n';

  return 0;
}
