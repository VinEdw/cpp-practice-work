#include <iostream>
#include <vector>

int main() {
  std::vector<char> arr { 'h', 'e', 'l', 'l', 'o' };

  std::cout << "The array has " << std::size(arr) << " elements.\n";
  std::cout << "Yep, " << arr.size() << " elements.\n";

  std::cout << "The second character is " << arr[1] << ".\n";
  std::cout << "That's right, " << arr.at(1) << ".\n";

  return 0;
}
