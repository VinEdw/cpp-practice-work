#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <string_view>
#include "Random.h"
#include "Potion.h"

class Player {
  private:
    static constexpr int s_min_starting_gold { 80 };
    static constexpr int s_max_starting_gold { 120 };

    std::string m_name{};
    int m_gold{};
    std::array<int, Potion::max_potions> m_inventory{};

  public:
    explicit Player(std::string_view name)
      : m_name { name }
      , m_gold { Random::get(s_min_starting_gold, s_max_starting_gold) }
    {
    }

    const std::string& name() const { return m_name; };
    int gold() const { return m_gold; }
    int inventory(Potion::Type p) const { return m_inventory[p]; }
    bool buy(Potion::Type p);
};

std::string get_name();

void print_inventory(const Player& player);

#endif
