#include <iostream>
#include <vector>

template <typename T>
void print_stack_contents(const std::vector<T>& stack) {
  std::cout << "\t(Stack:";

  if (stack.empty()) {
    std::cout << " empty";
  }
  else {
    for (const T& val : stack) {
      std::cout << ' ' << val;
    }
  }

  std::cout << ")\n";
}

template <typename T>
void push_and_print(std::vector<T>& stack, const T& val) {
  stack.push_back(val);
  std::cout << "Push " << val << ' ';
  print_stack_contents(stack);
}

template <typename T>
void pop_and_print(std::vector<T>& stack) {
  stack.pop_back();
  std::cout << "Pop ";
  print_stack_contents(stack);
}

int main() {
  std::vector<int> stack{};
  print_stack_contents(stack);

  push_and_print(stack, 1);
  push_and_print(stack, 2);
  push_and_print(stack, 3);
  pop_and_print(stack);
  push_and_print(stack, 4);
  pop_and_print(stack);
  pop_and_print(stack);
  pop_and_print(stack);

  return 0;
}
