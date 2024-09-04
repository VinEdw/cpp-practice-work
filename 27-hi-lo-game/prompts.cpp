#include <iostream>
#include "prompts.h"
#include "extraction.h"

// Print a description at the start of the game
void start_prompt(int min, int max, int attempts) {
  std::cout << "Let's play a game. ";
  std::cout << "I'm thinking of a number between " << min << " and " << max << ". ";
  std::cout << "You have " << attempts << " tries to guess what it is.\n";
}

// Prompt the user for a guess
int guess_prompt(int min, int max, int attempt) {
  while (true) {
    std::cout << "Guess #" << attempt << ": ";
    int guess{};
    std::cin >> guess;

    if (clear_failed_extraction()) {
      std::cout << "Input is invalid. Please try again.\n";
      continue;
    }

    ignore_line();

    if (guess < min || guess > max) {
      std::cout << "Input is out of bounds. Please try again.\n";
      continue;
    }

    return guess;
  }
}

// Prompt the user whether they want to continue
bool continue_prompt() {
  while (true) {
    std::cout << "Would you like to play again (y/n)? ";
    char response{};
    std::cin >> response;

    if (clear_failed_extraction()) {
      std::cout << "Input is invalid. Please try again.\n";
      continue;
    }

    ignore_line();

    switch (response) {
      case 'y':
        return true;
      case 'n':
        return false;
      default:
        std::cout << "Input is invaid. Please try again.\n";
    }
  }
}
