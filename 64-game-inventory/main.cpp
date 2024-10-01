#include <iostream>
#include <cassert>
#include <vector>
#include <string_view>

namespace Items {
  enum Type {
    health_potion,
    torch,
    arrow,
    max_items
  };
}

std::string_view get_item_name_singular(Items::Type item) {
  switch (item) {
    case Items::health_potion:
      return "health potion";
    case Items::torch:
      return "torch";
    case Items::arrow:
      return "arrow";
    default:
      return "???";
  }
}

std::string_view get_item_name_plural(Items::Type item) {
  switch (item) {
    case Items::health_potion:
      return "health potions";
    case Items::torch:
      return "torches";
    case Items::arrow:
      return "arrows";
    default:
      return "???";
  }
}

template <typename T>
constexpr std::size_t toUZ(T value) {
  static_assert(std::is_integral<T>() || std::is_enum<T>());
  return static_cast<std::size_t>(value);
}

int count_total_items(const std::vector<int>& inventory) {
  int total { 0 };
  for (auto count : inventory) {
    total += count;
  }
  return total;
}

void print_total_items(const std::vector<int>& inventory) {
  std::cout << "You have " << count_total_items(inventory) << " total items\n";
}

void print_inventory_item(const std::vector<int>& inventory, Items::Type item) {
  int count { inventory[toUZ(item)] };
  bool plural { count != 1 };
  std::cout << "You have " << count << ' ' << (plural ? get_item_name_plural(item) : get_item_name_singular(item)) << '\n';
}

void print_full_inventory(const std::vector<int>& inventory) {
  for (int i { 0 }; i < Items::max_items; ++i) {
    auto item { static_cast<Items::Type>(i) };
    print_inventory_item(inventory, item);
  }
  print_total_items(inventory);
}

int main() {
  std::vector inventory { 1, 5, 10 };
  assert(inventory.size() == Items::max_items);

  print_full_inventory(inventory);

  return 0;
}
