#include <iostream>
#include <vector>
#include <string_view>
#include "Random.h"

namespace WordList {
  std::vector<std::string_view> words {
    "mystery",
    "broccoli",
    "account",
    "almost",
    "spaghetti",
    "opinion",
    "beautiful",
    "distance",
    "luggage",
  };

  std::string_view get_random_word() {
    return words[Random::get<std::size_t>(0, words.size() - 1)];
  }
}

class Session {
  private:
    std::string_view m_word { WordList::get_random_word() };
    std::vector<bool> m_letter_guessed { std::vector<bool>(26) };
    int m_lives { 6 };

    std::size_t to_index(char c) const { return static_cast<std::size_t>((c % 32) - 1); }

  public:
    Session() = default;

    Session(int lives)
      : m_lives { lives }
    {
    }

    std::string_view get_word() const { return m_word; }
    int get_lives() const { return m_lives; };

    void set_letter_guessed(char c) {
      if (c < 'a' || c > 'z') {
        return;
      }
      m_letter_guessed[to_index(c)] = true;
    }

    bool is_letter_guessed(char c) const {
      if (c < 'a' || c > 'z') {
        return false;
      }
      return m_letter_guessed[to_index(c)];
    }

    bool is_letter_in_word(char c) const {
      for (auto letter : m_word) {
        if (letter == c) {
          return true;
        }
      }
      return false;
    }

    bool is_solved() {
      for (auto letter : m_word) {
        if (!is_letter_guessed(letter)) {
          return false;
        }
      }
      return true;
    }

    bool check_guess(char c) {
      set_letter_guessed(c);
      bool letter_in_word { is_letter_in_word(c) };
      if (!letter_in_word) {
        --m_lives;
      }
      return letter_in_word;
    }

};

void draw(const Session& s) {
  std::cout << '\n';
  std::cout << "The word: ";
  for (auto c : s.get_word() ) {
    if (s.is_letter_guessed(c)) {
      std::cout << c;
    }
    else {
      std::cout << '_';
    }
  }

  std::cout << "   Wrong guesses: ";
  for (int i { 0 }; i < s.get_lives(); ++i) {
    std::cout << '+';
  }
  for (char c { 'a' }; c <= 'z'; ++c) {
    if (s.is_letter_guessed(c) && !s.is_letter_in_word(c)) {
      std::cout << c;
    }
  }

  std::cout << '\n';
}

char get_guess(const Session& s) {
  while (true) {
    std::cout << "Enter your next letter: ";
    char c{};
    std::cin >> c;

    if (!std::cin) {
      std::cin.clear();
      std::cout << "That wasn't a valid input.  Try again.\n";
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      continue;
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (c < 'a' || c > 'z') {
      std::cout << "That wasn't a valid input.  Try again.\n";
      continue;
    }

    if (s.is_letter_guessed(c)) {
      std::cout << "You already guessed that.  Try again.\n";
      continue;
    }

    return c;
  }
}

int main() {
  std::cout << "Welcome to C++man (a variant of Hangman)\n";
  std::cout << "To win: guess the word.  To lose: run out of pluses\n";

  Session s{ 6 };

  while (s.get_lives() && !s.is_solved()) {
    draw(s);
    char c { get_guess(s) };
    if (s.check_guess(c)) {
      std::cout << "Yes, '" << c << "' is in the word!\n";
    }
    else {
      std::cout << "No, '" << c << "' is not in the word!\n";
    }
  }

  draw(s);

  if (s.is_solved()) {
    std::cout << "You won!\n";
  }
  else {
    std::cout << "You lost!  The word was: " << s.get_word() << '\n';
  }

  return 0;
}
