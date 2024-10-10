#include <iostream>
#include <array>
#include <string_view>

struct Item {
  std::string_view name{};
  int gold{};
};

void print_item(const Item& item) {
  std::cout << "A " << item.name << " costs " << item.gold << " gold.\n";
}

template <std::size_t N>
void print_store(const std::array<Item, N>& store) {
  for (const auto& e: store) {
    print_item(e);
  }
}

int main() {
  std::array store_1 {
    Item { "sword", 5 },
    Item { "dagger", 3 },
    Item { "club", 2 },
    Item { "spear", 7 },
  };

  std::cout << "Weapon Store:\n";
  print_store(store_1);
  std::cout << '\n';

  std::array<Item, 4> store_2 {{
    { "steak", 5 },
    { "carrot", 3 },
    { "melon", 2 },
    { "golden apple", 7 },
  }};

  std::cout << "Food Store:\n";
  print_store(store_2);

  return 0;
}
