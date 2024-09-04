// Make sure that assert triggers even if we compile in release mode
#undef NDEBUG

#include <iostream>
#include <cmath>
#include <cassert>

constexpr bool is_prime(int x) {
  if (x <= 1)
    return false;
  if (x == 2)
    return true;
  if (x % 2 == 0)
    return false;

  for (int i { 3 }; i * i <= x; i += 2) {
    if (x % i == 0) {
      return false;
    }
  }
  
  return true;
}

void print_whether_prime(int x) {
  if (is_prime(x))
    std::cout << x << " is prime." << '\n';
  else
    std::cout << x << " is not prime." << '\n';
}

void test_is_prime() {
  assert(!is_prime(0)); // terminate program if is_prime(0) is true
  assert(!is_prime(1));
  assert(is_prime(2));  // terminate program if is_prime(2) is false
  assert(is_prime(3));
  assert(!is_prime(4));
  assert(is_prime(5));
  assert(is_prime(7));
  assert(!is_prime(9));
  assert(is_prime(11));
  assert(is_prime(13));
  assert(!is_prime(15));
  assert(!is_prime(16));
  assert(is_prime(17));
  assert(is_prime(19));
  assert(is_prime(97));
  assert(!is_prime(99));
  assert(is_prime(13417));
}

int main() {
  test_is_prime();

  std::cout << "Enter two space separated numbers: ";
  int x{};
  int y{};
  std::cin >> x >> y;


  print_whether_prime(x);
  print_whether_prime(y);

  return 0;
}
