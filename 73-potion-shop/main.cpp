#include <iostream>
#include "Potion.h"
#include "Player.h"

void shop(Player& player) {
  while (true) {
    std::cout << "Here is our selection for today:\n";

    for (const auto p : Potion::types) {
      std::cout << p << ") " << Potion::name[p] << " costs " << Potion::cost[p] << '\n';
    }

    Potion::Type p { which_potion() };

    if (p == Potion::max_potions) {
      return;
    }

    if (player.buy(p)) {
      std::cout << "You purchased a potion of " << Potion::name[p] << ".  You have " << player.gold() << " gold left.\n\n";
    }
    else {
      std::cout << "You cannot affort that.\n\n";
    }
  }
}

int main() {
  std::cout << "Welcome to Roscoe's potion emporium!\n";

  Player player { get_name() };
  std::cout << "Hello, " << player.name() << ", you have " << player.gold() << " gold.\n\n";

  shop(player);
  std::cout << '\n';

  print_inventory(player);

  std::cout << "\nThanks for shopping at Roscoe's potion emporium!\n";

  return 0;
}
