#include <iostream>
#include <limits>
#include <utility>
#include <vector>

template <typename T>
std::pair<std::size_t, std::size_t>find_min_max_indices(const std::vector<T>& arr) {
  std::size_t min_idx { 0 };
  std::size_t max_idx { 0 };
  for (std::size_t idx { 0 }; idx < arr.size(); ++idx) {
    if (arr[idx] > arr[max_idx]) {
      max_idx = idx;
    }
    else if (arr[idx] < arr[min_idx]) {
      min_idx = idx;
    }
  }
  return { min_idx, max_idx };
}

template <typename T>
void print_vector(const std::vector<T>& arr) {
  std::cout << "( ";
  for (std::size_t i { 0 }; i < arr.size(); ++i) {
    if (i == 0) {
      std::cout << arr[i];
    }
    else {
      std::cout << ", " << arr[i];
    }
  }
  std::cout << " )";
}

template <typename T>
void print_min_max(const std::vector<T>& arr) {
  std::cout << "With array ";
  print_vector(arr);
  std::cout << ":\n";

  auto indices { find_min_max_indices(arr) };
  std::cout << "The min element has index " << indices.first << " and value " << arr[indices.first] << '\n';
  std::cout << "The max element has index " << indices.second << " and value " << arr[indices.second] << '\n';
}

int main() {
  std::vector v1 { 3, 8, 2, 5, 7, 8, 3 };
  print_min_max(v1);

  std::cout << '\n';

  std::vector v2 { 5.5, 2.7, 3.3, 7.6, 1.2, 8.8, 6.6 };
  print_min_max(v2);

  std::cout << '\n';

  std::vector<int> v3{};
  std::cout << "Enter numbers to add (use -1 to stop): ";
  while (true) {
    int x{};
    std::cin >> x;
    if (x == -1) {
      break;
    }

    if (!std::cin) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      continue;
    }

    v3.push_back(x);
  }

  if (v3.empty()) {
    std::cout << "The array has no elements\n";
  }
  else {
    print_min_max(v3);
  }

  return 0;
}
