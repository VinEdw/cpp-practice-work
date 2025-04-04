#ifndef CARD_H
#define CARD_H

#include <array>
#include <iostream>

struct Card {
  enum Rank {
    rank_ace,
    rank_2,
    rank_3,
    rank_4,
    rank_5,
    rank_6,
    rank_7,
    rank_8,
    rank_9,
    rank_10,
    rank_jack,
    rank_queen,
    rank_king,

    max_ranks
  };

  enum Suit {
    suit_club,
    suit_diamond,
    suit_spade,
    suit_heart,

    max_suits
  };

  static constexpr std::array all_ranks { rank_ace, rank_2, rank_3, rank_4, rank_5, rank_6, rank_7, rank_8, rank_9, rank_10, rank_jack, rank_queen, rank_king };
  static constexpr std::array rank_names { 'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K' };
  static constexpr std::array rank_values { 11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10 };
  static constexpr std::array all_suits { suit_club, suit_diamond, suit_spade, suit_heart };
  static constexpr std::array suit_names { 'C', 'D', 'S', 'H' };

  static_assert(all_ranks.size() == max_ranks);
  static_assert(rank_names.size() == max_ranks);
  static_assert(rank_values.size() == max_ranks);
  static_assert(all_suits.size() == max_suits);
  static_assert(suit_names.size() == max_suits);

  Rank rank{};
  Suit suit{};

  friend std::ostream& operator<<(std::ostream& out, const Card& card);

  int value() const { return rank_values[rank]; }

};

#endif
