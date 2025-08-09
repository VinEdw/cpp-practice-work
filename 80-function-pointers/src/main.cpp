#include <functional>
#include <iostream>

// using ArithmeticFunction = int (*)(int, int);
using ArithmeticFunction = std::function<int(int, int)>;

int read_int() {
  std::cout << "Enter an integer: ";
  int x{};
  std::cin >> x;
  return x;
}

bool valid_operation(char operation) {
  switch(operation) {
    case '+':
    case '-':
    case '*':
    case '/':
      return true;
  }
  return false;
}

char read_operation() {
  std::cout << "Enter a mathematical operation (+, -, *, or /): ";
  char c{};
  std::cin >> c;
  while (!valid_operation(c)) {
    std::cout << "Invalid operation. Try again: ";
    std::cin >> c;
  }
  return c;
}

int add(int x, int y) {
  return x + y;
}

int subtract(int x, int y) {
  return x - y;
}

int multiply(int x, int y) {
  return x * y;
}

int divide(int x, int y) {
  return x / y;
}

ArithmeticFunction get_arithmetic_function(char operation) {
  switch(operation) {
    case '+':
      return &add;
    case '-':
      return &subtract;
    case '*':
      return &multiply;
    case '/':
      return &divide;
  }
  return nullptr;
}

int main() {
  int x { read_int() };
  int y { read_int() };

  char operation { read_operation() };

  ArithmeticFunction fcn { get_arithmetic_function(operation) };

  std::cout << x << ' ' << operation << ' ' << y << " = " << fcn(x, y) << '\n';

  return 0;
}
