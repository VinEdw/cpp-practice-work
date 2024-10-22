#include "Card.h"

std::ostream& operator<<(std::ostream& out, const Card& card) {
  std::cout << Card::rank_names[card.rank] << Card::suit_names[card.suit];
  return out;
}

