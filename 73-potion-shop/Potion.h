#ifndef POTION_H
#define POTION_H

#include <array>
#include <string_view>

void ignore_line();

namespace Potion {
  enum Type {
    healing,
    mana,
    speed,
    invisibility,
    max_potions
  };

  constexpr std::array types { healing, mana, speed, invisibility };
  constexpr std::array cost { 20, 30, 12, 50 };
  constexpr std::array<std::string_view, max_potions> name { "healing", "mana", "speed", "invisibility" };

  static_assert(types.size() == max_potions);
  static_assert(cost.size() == max_potions);
  static_assert(name.size() == max_potions);
}

Potion::Type which_potion();

#endif
