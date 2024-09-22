// Write a program that reads at most 100 positive integers and counts the occurrence of each number.
// Assume the input ends with 0 or a negative integer.
#include <iostream>

int get_integers(int arr[], int length) {
  std::cout << "Enter a list of positive integers (up to 100 integers). Stop input with a non-positive integer such as 0:\n";
  int count { 0 };
  for (int i { 0 }; i < length; ++i) {
    int temp{};
    std::cin >> temp;
    if (temp <= 0) {
      break;
    }
    arr[i] = temp;
    ++count;
  }
  return count;
}

void swap(int arr[], int i, int j) {
  int temp { arr[i] };
  arr[i] = arr[j];
  arr[j] = temp;
}

int partition(int arr[], int lo, int hi) {
  int pivot { arr[hi] };
  int i { lo };
  for (int j { lo }; j < hi; ++j) {
    if (arr[j] <= pivot) {
      swap(arr, i, j);
      ++i;
    }
  }
  swap(arr, i, hi);
  return i;
}

void quicksort(int arr[], int lo, int hi) {
  if (lo >= hi || lo < 0) {
    return;
  }
  int p { partition(arr, lo, hi) };
  quicksort(arr, lo, p - 1);
  quicksort(arr, p + 1, hi);
}

void print_value_and_occurrences(int val, int occurrences) {
  std::cout << val << " occurs " << occurrences << (occurrences > 1 ? " times" : " time") << '\n';
}

int main() {
  constexpr int max_length { 100 };
  int arr[max_length] {};

  int nums_entered { get_integers(arr, max_length) };
  if (nums_entered <= 0) {
    std::cout << "No integers entered.\n";
    return 0;
  }

  quicksort(arr, 0, max_length - 1);

  int val { arr[max_length - nums_entered] };
  int val_count { 1 };
  for (int i { max_length - nums_entered + 1 }; i < max_length; ++i) {
    if (arr[i] == val) {
      ++val_count;
    }
    else {
      print_value_and_occurrences(val, val_count);
      val = arr[i];
      val_count = 1;
    }
  }
  print_value_and_occurrences(val, val_count);

  return 0;
}
