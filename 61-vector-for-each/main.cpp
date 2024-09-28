#include <iostream>
#include <vector>
#include <string>
#include <string_view>

std::string get_name() {
  std::cout << "Enter a name: ";
  std::string name{};
  std::getline(std::cin >> std::ws, name);
  return name;
}

template <typename T>
bool is_value_in_array(const std::vector<T>& arr, const T& value) {
  for (const auto& item : arr) {
    if (item == value) {
      return true;
    }
  }
  return false;
}

int main() {
  std::vector<std::string_view> names {
    "Alex",
    "Betty",
    "Caroline",
    "Dave",
    "Emily",
    "Fred",
    "Greg",
    "Holly",
  };

  std::string username { get_name() };
  bool found { is_value_in_array<std::string_view>(names, username) };

  if (found) {
    std::cout << username << " was found.\n";
  }
  else {
    std::cout << username << " was not found.\n";
  }

  return 0;
}
