#include <iostream>
#include <algorithm>
#include <cmath>

bool is_close(double x, double y, double rel_tol=1e-8, double abs_tol=1e-12) {
  double abs_diff { std::abs(x - y) };
  double rel_diff { std::abs(x - y) / std::max(std::abs(x), std::abs(y)) };
  return (abs_diff <= abs_tol) || (rel_diff <= rel_tol);
}

int main() {
  std::cout << std::boolalpha;
  std::cout << "(0.1 + 0.2 == 0.3): " << (0.1 + 0.2 == 0.3) << '\n';
  std::cout << "is_close(0.1 + 0.2, 0.3): " << is_close(0.1 + 0.2, 0.3) << '\n';

  return 0;
}
