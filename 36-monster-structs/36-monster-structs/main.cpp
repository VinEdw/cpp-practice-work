#include <iostream>
#include <string_view>

struct Monster {
  enum Type {
    ogre,
    dragon,
    orc,
    giant_spider,
    slime,
  };

  Type type {};
  std::string_view name {};
  int health {};
};

std::string_view get_monster_type_string(Monster::Type type) {
  switch (type) {
    case Monster::ogre:
      return "Ogre";
    case Monster::dragon:
      return "Dragon";
    case Monster::orc:
      return "Orc";
    case Monster::giant_spider:
      return "Giant Spider";
    case Monster::slime:
      return "Slime";

    default:
      return "???";
  }
}

std::ostream& operator<<(std::ostream& out, Monster::Type type) {
  out << get_monster_type_string(type);
  return out;
}

void print_monster(const Monster& mon) {
  std::cout << "This " << mon.type <<
    " is named " << mon.name <<
    " and has " << mon.health << " health.\n";
}

int main() {
  Monster mon1 { Monster::ogre, "Torg", 145 };
  Monster mon2 { Monster::slime, "Blurp", 23 };

  print_monster(mon1);
  print_monster(mon2);

  return 0;
}
