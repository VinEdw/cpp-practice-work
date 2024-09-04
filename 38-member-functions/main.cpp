#include <iostream>

struct IntPair {
  int first {};
  int second {};

  void print() const {
    std::cout << "Pair(" << first << ", " << second << ")\n";
  }

  constexpr bool isEqual(const IntPair& a) const {
    return (first == a.first) && (second == a.second);
  }

  void swap() {
    const int temp { first };
    first = second;
    second = temp;
  }
};

int main() {
  IntPair p1 {1, 2};
  IntPair p2 {3, 4};
  IntPair p3 {4, 3};

  std::cout << "p1: ";
  p1.print();

  std::cout << "p2: ";
  p2.print();

  std::cout << "p3: ";
  p3.print();

  std::cout << "p1 and p1 " << (p1.isEqual(p1) ? "are equal\n" : "are not equal\n");
  std::cout << "p1 and p2 " << (p1.isEqual(p2) ? "are equal\n" : "are not equal\n");

  std::cout << "p2 and p3 " << (p2.isEqual(p3) ? "are equal\n" : "are not equal\n");
  std::cout << "Swapping ints of p3...\n";
  p3.swap();
  std::cout << "p2 and p3 " << (p2.isEqual(p3) ? "are equal\n" : "are not equal\n");

  return 0;
}
