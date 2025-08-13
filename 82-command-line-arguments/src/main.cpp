#include <iostream>
#include <sstream>

int parse(char str[]) {
  std::stringstream convert { str };
  int num {};
  if (!(convert >> num)) {
    num = 0;
  }
  return num;
}

// Sum the entered command line arguments
int main(int argc, char* argv[]) {
  int sum { 0 };

  for (int i { 1 }; i < argc; ++i) {
    int x { parse(argv[i]) };
    sum += x;
  }

  std::cout << sum << '\n';

  return 0;
}
