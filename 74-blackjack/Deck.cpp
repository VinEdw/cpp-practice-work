#include <array>
#include <algorithm>
#include <cassert>
#include "Random.h"
#include "Deck.h"
#include "Card.h"

Deck::Deck() {
  std::size_t i { 0 };
  for (auto suit : Card::all_suits) {
    for (auto rank : Card::all_ranks) {
      m_cards[i] = Card { rank, suit };
      ++i;
    }
  }
}

void Deck::shuffle() {
  std::shuffle(m_cards.begin(), m_cards.end(), Random::mt);
  m_next_card_index = 0;
}

Card Deck::deal_card() {
  assert(m_next_card_index < s_deck_size && "Deck::deal_card ran out of cards");
  return m_cards[m_next_card_index++];
}
