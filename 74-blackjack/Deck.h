#ifndef DECK_H
#define DECK_H

#include <array>
#include "Card.h"

class Deck {
  private:
    static constexpr std::size_t s_deck_size { 52 };
    std::array<Card, s_deck_size> m_cards{};
    std::size_t m_next_card_index { 0 };

  public:
    Deck();

    void shuffle();

    Card deal_card();

};

#endif
