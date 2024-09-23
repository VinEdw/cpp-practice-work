#include <iostream>
#include <limits>
#include <string_view>
#include <vector>

void ignore_line() {
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool clear_failed_extraction() {
  // Check for failed extraction
  // If the previous extraction failed
  if (!std::cin) { 
    // If the stream was closed
    if (std::cin.eof()) {
      std::exit(0); // Shut down the program now
    }

    // Handle the failure
    std::cin.clear(); // Put it back in 'normal' operation mode
    ignore_line();    // Remove the bad input

    return true;
  }

  return false;
}

template <typename T>
T get_valid_number(std::string_view prompt, T low, T high) {
  while (true) {
    std::cout << prompt;
    T x{};
    std::cin >> x;
    
    if (clear_failed_extraction()) {
      continue;
    }
    ignore_line();

    if (x < low || x > high) {
      continue;
    }

    return x;
  }
}

template <typename T>
void print_array(const std::vector<T>& arr) {
  for (std::size_t i { 0 }; i < arr.size(); ++i) {
    std::cout << arr[i] << ' ';
  }

  if (arr.size() > 0) {
    std::cout << '\n';
  }
}

template <typename T>
int find_index(const std::vector<T>& arr, T val) {
  for (std::size_t i { 0 }; i < arr.size(); ++i) {
    if (arr[i] == val) {
      return static_cast<int>(i);
    }
  }
  return -1;
}

template <typename T>
void print_value_and_index(const std::vector<T>& arr, T x) {
  int idx { find_index(arr, x) };
  if (idx != -1) {
    std::cout << "The number " << x << " has index " << idx << '\n';
  }
  else {
    std::cout << "The number " << x << " was not found\n";
  }
}

int main() {
  std::vector arr { 4, 6, 7, 3, 8, 2, 1, 9 };
  int x { get_valid_number("Enter a value between 1 and 9: ", 1, 9) };
  print_array(arr);
  print_value_and_index(arr, x);

  std::vector vec { 4.4, 6.6, 7.7, 3.3, 8.8, 2.2, 1.1, 9.9 };
  double y { get_valid_number("Enter a value between 1 and 9: ", 1.0, 9.0) };
  print_array(vec);
  print_value_and_index(vec, y);

  return 0;
}
