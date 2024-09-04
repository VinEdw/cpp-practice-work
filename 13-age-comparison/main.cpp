#include <iostream>
#include <string>
#include <string_view>

std::string get_name(int person_number) {
  std::cout << "Enter the name of person #" << person_number << ": ";
  std::string full_name{};
  std::getline(std::cin >> std::ws, full_name);

  return full_name;
}

int get_age(std::string_view name) {
  std::cout << "Enter the age of " << name << ": ";
  int age{};
  std::cin >> age;

  return age;
}

void print_older_person(std::string_view name_1, int age_1, std::string_view name_2, int age_2) {
  if (age_1 > age_2)
    std::cout << name_1 << " (age " << age_1 << ") is older than " << name_2 << " (age " << age_2 << ").\n";
  else if (age_2 > age_1)
    std::cout << name_2 << " (age " << age_2 << ") is older than " << name_1 << " (age " << age_1 << ").\n";
  else
    std::cout << name_1 << " (age " << age_1 << ") is the same age as " << name_2 << " (age " << age_2 << ").\n";
}

int main() {
  const std::string name_1 { get_name(1) };
  const int age_1 { get_age(name_1) };

  const std::string name_2 { get_name(2) };
  const int age_2 { get_age(name_2) };

  print_older_person(name_1, age_1, name_2, age_2);

  return 0;
}
