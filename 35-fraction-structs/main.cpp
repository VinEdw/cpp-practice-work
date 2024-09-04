#include <iostream>

constexpr int min(int x, int y) {
  return (x < y) ? x : y;
}

struct Fraction {
  int numerator { 0 };
  int denominator { 1 };
};

std::ostream& operator<<(std::ostream& out, const Fraction& frac) {
  out << frac.numerator << '/' << frac.denominator;
  return out;
}

Fraction get_fraction() {
  Fraction temp{};

  std::cout << "Enter a value for the numerator: ";
  std::cin >> temp.numerator;

  std::cout << "Enter a value for the denominator: ";
  std::cin >> temp.denominator;

  return temp;
}

constexpr Fraction simplify_fraction(Fraction frac) {
  int divisor { 2 };
  while (divisor <= min(frac.numerator, frac.denominator)) {
    if ((frac.numerator % divisor == 0) && (frac.denominator % divisor == 0)) {
      frac.numerator /= divisor;
      frac.denominator /= divisor;
    }
    else {
      ++divisor;
    }
  }
  return frac;
}

constexpr Fraction multiply_fractions(const Fraction& x, const Fraction& y, bool simplify=true) {
  Fraction product{};
  product.numerator = x.numerator * y.numerator;
  product.denominator = x.denominator * y.denominator;

  return simplify ? simplify_fraction(product) : product;
}

int main() {
  Fraction frac_1 { get_fraction() };
  std::cout << '\n';
  Fraction frac_2 { get_fraction() };
  std::cout << '\n';

  std::cout << "Your fractions multiplied together: " << multiply_fractions(frac_1, frac_2) << '\n';

  return 0;
}
