#include <iostream>
#include <string>
#include "Player.h"
#include "Potion.h"

bool Player::buy(Potion::Type p) {
  int cost { Potion::cost[p] };
  if (cost > m_gold) {
    return false;
  }

  m_gold -= cost;
  ++m_inventory[p];
  return true;
}

std::string get_name() {
  std::cout << "Enter your name: ";
  std::string name{};
  std::getline(std::cin >> std::ws, name);
  return name;
}

void print_inventory(const Player& player) {
  std::cout << "Your inventory contains:\n";

  for (const auto p : Potion::types) {
    int count { player.inventory(p) };
    if (count > 0) {
      std::cout << count << "x potion of " << Potion::name[p] << '\n';
    }
  }

  std::cout << "You escaped with " << player.gold() << " remaining.\n";
}
