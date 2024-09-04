#include <iostream>
#include <optional>
#include <string_view>

enum class Animal {
  pig,
  chicken,
  goat,
  cat,
  dog,
  duck,
};

std::optional<std::string_view> get_animal_name(Animal animal) {
  switch (animal) {
    case Animal::pig:
      return "pig";
    case Animal::chicken:
      return "chicken";
    case Animal::goat:
      return "goat";
    case Animal::cat:
      return "cat";
    case Animal::dog:
      return "dog";
    case Animal::duck:
      return "duck";

    default:
      return {};
  }
}

std::ostream& operator<<(std::ostream& out, Animal animal) {
  std::optional<std::string_view> name { get_animal_name(animal) };
  out << (name ? *name : "???");

  return out;
}

std::optional<int> get_leg_count(Animal animal) {
  switch (animal) {
    case Animal::pig:
    case Animal::goat:
    case Animal::cat:
    case Animal::dog:
      return 4;

    case Animal::chicken:
    case Animal::duck:
      return 2;

    default:
      return {};
  }
}

void print_number_of_legs(Animal animal) {
  std::cout << "A " << animal << " has ";

  std::optional<int> leg_count { get_leg_count(animal) };
  if (leg_count) {
    std::cout << *leg_count;
  }
  else {
    std::cout << "???";
  }

  std::cout << " legs.\n";
}

int main() {
  print_number_of_legs(Animal::pig);
  print_number_of_legs(Animal::chicken);
  print_number_of_legs(Animal::goat);
  print_number_of_legs(Animal::cat);
  print_number_of_legs(Animal::dog);
  print_number_of_legs(Animal::duck);

  Animal unknown { static_cast<Animal>(7) };
  print_number_of_legs(unknown);

  return 0;
}
