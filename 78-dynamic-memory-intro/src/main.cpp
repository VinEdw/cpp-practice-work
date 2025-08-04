#include <iostream>
#include <new>

int main() {
  int* ptr { new int{} }; // Dynamically allocate an integer and assign the address to ptr
  *ptr = 7;               // Assign a value to the allocated memory

  std::cout << *ptr << '\n';

  delete ptr;             // Return the memory pointed to by ptr to the operating system
  ptr = nullptr;          // Set ptr to be a null pointer

  // In case the operating system does not have any memory to grant the request with
  int* value { new (std::nothrow) int{} }; // value will be set to a null pointer if the integer allocation fails
  // Handle case where new returned null
  if (!value) {
    std::cerr << "Could not allocate memory\n";
  }
  delete value;
  value = nullptr;

  return 0;
}
