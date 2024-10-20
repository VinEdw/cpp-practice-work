#include <iostream>
#include <limits>
#include "Potion.h"

void ignore_line() {
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

Potion::Type which_potion() {
  std::cout << "Enter the number of the potion you would like to buy, or 'q' to quit: ";
  int choice {};

  while (true) {
    std::cin >> choice;

    if (!std::cin) {
      std::cin.clear();
      if (std::cin.peek() == 'q') {
        ignore_line();
        return Potion::max_potions;
      }
      std::cout << "That is invalid input.  Try again: ";
      ignore_line();
      continue;
    }

    ignore_line();
    
    if (choice < 0 || choice >= Potion::max_potions) {
      std::cout << "That is invalid input.  Try again: ";
      continue;
    }

    return static_cast<Potion::Type>(choice);
  }
}
