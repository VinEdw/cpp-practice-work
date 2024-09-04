#include <iostream>
#include <string>

std::string get_full_name() {
  std::cout << "Enter your full name: ";
  std::string full_name{};
  std::getline(std::cin >> std::ws, full_name);
  return full_name;
}

int get_age() {
  std::cout << "Enter your age: ";
  int age{};
  std::cin >> age;
  return age;
}

int main() {
  std::string full_name { get_full_name() };
  int age { get_age() };

  int character_count { static_cast<int>(full_name.length()) };
  std::cout << "Your age + length of name is: " << age + character_count << '\n';

  return 0;
}
