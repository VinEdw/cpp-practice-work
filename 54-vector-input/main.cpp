#include <iostream>
#include <vector>

int main() {
  std::cout << "Enter 3 integers: ";
  std::vector<int> arr (3);
  std::cin >> arr[0] >> arr[1] >> arr[2];

  std::cout << "The sum is: " << arr[0] + arr[1] + arr[2] << '\n';
  std::cout << "The product is: " << arr[0] * arr[1] * arr[2] << '\n';

  return 0;
}
