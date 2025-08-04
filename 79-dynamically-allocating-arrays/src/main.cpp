#include <algorithm>
#include <iostream>
#include <string>

std::size_t get_name_count() {
  std::cout << "How many names would you like to enter? ";
  std::size_t count{};
  std::cin >> count;
  return count;
}

void get_names(std::string* names, std::size_t length) {
  for (std::size_t i { 0 }; i < length; ++i) {
    std::cout << "Enter name #" << i + 1 << ": ";
    std::getline(std::cin >> std::ws, names[i]);
  }
}

void print_names(std::string* names, std::size_t length) {
  std::cout << "\nHere is your sorted list\n";
  for (std::size_t i { 0 }; i < length; ++i) {
    std::cout << "Name #" << i + 1 << ": " << names[i] << '\n';
  }
}

int main() {
  std::size_t name_count { get_name_count() };
  auto* names { new std::string[name_count]{} };

  get_names(names, name_count);
  std::sort(names, names + name_count);
  print_names(names, name_count);

  delete[] names;
  return 0;
}
