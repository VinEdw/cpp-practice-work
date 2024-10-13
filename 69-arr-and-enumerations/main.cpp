#include <iostream>
#include <array>
#include <string>
#include <string_view>

namespace Animal {
  enum Type {
    chicken,
    dog,
    cat,
    elephant,
    duck,
    snake,
    max_animals
  };

  struct Data {
    std::string_view name{};
    int legs{};
    std::string_view sound{};
  };

  constexpr std::array types { chicken, dog, cat, elephant, duck, snake };
  constexpr std::array data {
    Data { "chicken",  2, "cluck" },
    Data { "dog",      4, "woof" },
    Data { "cat",      4, "meow" },
    Data { "elephant", 4, "pawoo" },
    Data { "duck",     2, "quack" },
    Data { "snake",    0, "hissss" },
  };

  static_assert(std::size(types) == max_animals);
  static_assert(std::size(data) == max_animals);
}

void print_animal_data(Animal::Type animal) {
  const Animal::Data data { Animal::data[animal] };
  std::cout << "A " << data.name << " has " << data.legs << " legs and says " << data.sound << ".\n";
}

std::ostream& operator<<(std::ostream& out, Animal::Type animal) {
  return out << Animal::data[animal].name;
}

std::istream& operator>>(std::istream& in, Animal::Type& animal) {
  std::string input{};
  std::getline(in >> std::ws, input);

  for (std::size_t i { 0 }; i < Animal::data.size(); ++i) {
    if (input == Animal::data[i].name) {
      animal = static_cast<Animal::Type>(i);
      return in;
    }
  }

  in.setstate(std::ios_base::failbit);
  return in;
}

int main() {
  std::cout << "Enter an animal: ";
  Animal::Type animal{};
  std::cin >> animal;

  if (std::cin) {
    print_animal_data(animal);
  }
  else {
    std::cin.clear();
    std::cout << "That animal couldn't be found.\n";
    animal = Animal::max_animals;
  }

  std::cout << "\nHere is the data for the rest of the animals:\n";
  for (auto a: Animal::types) {
    if (a != animal) {
      print_animal_data(a);
    }
  }

  return 0;
}
