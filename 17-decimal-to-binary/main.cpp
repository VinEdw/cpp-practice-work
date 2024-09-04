#include <iostream>
#include <cstdint>

std::uint8_t get_8_bit_int() {
  std::cout << "Enter a number between 0 and 255: ";
  int x{};
  std::cin >> x;
  return static_cast<std::uint8_t>(x);
}

void print_bits(std::uint8_t x) {
  // Start the place_value with the value of the most significant bit
  std::uint8_t place_value { 128 };
  // Iterate through each bit location
  for (int i { 0 }; i < 8; ++i) {
    // Print a space every 4 bits, except on the first bit
    if (i != 0 && i % 4 == 0)
      std::cout << ' ';
    // If x is greater than the place_value, then the current bit should be set
    // Afterwards, x should be reduced by the place_value
    if (x >= place_value) {
      x -= place_value;
      std::cout << '1';
    }
    // Otherwise, the current bit should not be set
    else {
      std::cout << '0';
    }
    // Half the place_value to move to the next bit
    place_value /= 2;
  }
  // Print a final newline
  std::cout << '\n';
}

int main() {
  std::uint8_t x { get_8_bit_int() };
  print_bits(x);
  return 0;
}
