#include <iostream>

double read_double() {
  std::cout << "Enter a double value: ";
  double x{};
  std::cin >> x;
  return x;
}

char read_operator() {
  std::cout << "Enter +, -, *, or /: ";
  char c{};
  std::cin >> c;
  return c;
}

void print_result(double x, double y, char operation) {
  double result;
  if (operation == '+')
    result = x + y;
  else if (operation == '-')
    result = x - y;
  else if (operation == '*')
    result = x * y;
  else if (operation == '/')
    result = x / y;
  else
    return;

  std::cout << x << ' ' << operation << ' ' << y << " is " << result << '\n';

}

int main() {
  double x { read_double() };
  double y { read_double() };

  char operation { read_operator() };

  print_result(x, y, operation);

  return 0;
}
