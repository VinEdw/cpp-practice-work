#include <cstdlib>
#include <iostream>
#include "Random.h"
#include "prompts.h"

// Play the hi-lo game.
// Return true if the player wins and false otherwise.
bool play_hi_lo(int min, int max, int attempts) {
  const int solution { Random::get(min, max) };
  start_prompt(min, max, attempts);

  for (int i { 1 }; i <= attempts; ++i) {
    const int guess { guess_prompt(min, max, i) };

    if (guess > solution) {
      std::cout << "Your guess is too high.\n";
    }
    else if (guess < solution) {
      std::cout << "Your guess is too low.\n";
    }
    else {
      std::cout << "Correct! You win!\n";
      return true;
    }
  }

  std::cout << "Sorry, you lose. The correct number was " << solution << ".\n";
  return false;
}


int main() {
  constexpr int min_value { 1 };
  constexpr int max_value { 100 };
  constexpr int max_attempts { 7 };

  do {
    play_hi_lo(min_value, max_value, max_attempts);
  } while (continue_prompt());

  std::cout << "Thank you for playing.\n";

  return 0;
}
