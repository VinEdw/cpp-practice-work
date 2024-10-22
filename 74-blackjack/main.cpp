#include <iostream>
#include <limits>
#include "Settings.h"
#include "Card.h"
#include "Deck.h"

void ignore_line() {
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

struct Player {
  int score{};
  int ace_count{};
};

void update_player_score(Player& player, const Card& card) {
  if (card.rank == Card::rank_ace) {
    ++player.ace_count;
  }

  player.score += card.value();

  while (player.score > Settings::bust && player.ace_count > 0) {
    player.score -= 10;
    --player.ace_count;
  }
}

// Return true if the player chose to hit. False otherwise
bool hit_or_stand() {
  std::cout << "(h) to hit, or (s) to stand: ";
  while (true) {
    char c{};
    std::cin >> c;

    if (!std::cin) {
      std::cin.clear();
      ignore_line();
      continue;
    }
    ignore_line();

    switch (c) {
      case 'h':
        return true;
      case 's':
        return false;
    }

    std::cout << "Invalid input.  Try again: ";
  }
}

// Return true if the player went bust. False otherwise.
bool player_turn(Deck& deck, Player& player) {
  while (player.score < Settings::bust && hit_or_stand()) {
    Card card { deck.deal_card() };
    update_player_score(player, card);
    std::cout << "You were delt a " << card << ".  You now have: " << player.score << '\n';
  }

  if (player.score > Settings::bust) {
    std::cout << "You went bust!\n";
    return true;
  }

  return false;
}

// Return true if the dealer went bust. False otherwise.
bool dealer_turn(Deck& deck, Player& dealer) {
  while (dealer.score < Settings::dealer_stops_at) {
    Card card { deck.deal_card() };
    update_player_score(dealer, card);
    std::cout << "The dealer flips a " << card << ".  They now have: " << dealer.score << '\n';
  }

  if (dealer.score > Settings::bust) {
    std::cout << "The dealer went bust!\n";
    return true;
  }

  return false;
}

enum class GameResult {
  player_won,
  dealer_won,
  tie
};

// Return true if the player won. False otherwise
GameResult play_blackjack() {
  Deck deck{};
  deck.shuffle();

  Player dealer{};
  Card card_1 { deck.deal_card() };
  update_player_score(dealer, card_1);
  std::cout << "The dealer is showing " << card_1 << " (" << dealer.score << ")\n";

  Player player{};
  Card card_2 { deck.deal_card() };
  Card card_3 { deck.deal_card() };
  update_player_score(player, card_2);
  update_player_score(player, card_3);
  std::cout << "You are showing " << card_2 << ' ' << card_3 << " (" << player.score << ")\n";

  if (player_turn(deck, player)) {
    return GameResult::dealer_won;
  }

  if (dealer_turn(deck, dealer)) {
    return GameResult::player_won;
  }

  if (player.score == dealer.score) {
    return GameResult::tie;
  }

  return (player.score > dealer.score) ? GameResult::player_won : GameResult::dealer_won;
}

int main() {
  switch(play_blackjack()) {
    case GameResult::player_won:
      std::cout << "You win!\n";
      return 0;
    case GameResult::dealer_won:
      std::cout << "You lose!\n";
      return 0;
    case GameResult::tie:
      std::cout << "It's a tie.\n";
      return 0;
  }

  return 0;
}
