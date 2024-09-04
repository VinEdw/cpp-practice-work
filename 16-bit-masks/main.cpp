#include <bitset>
#include <cstdint>
#include <iostream>

int main()
{
    [[maybe_unused]] constexpr std::uint8_t option_viewed{ 0x01 };
    [[maybe_unused]] constexpr std::uint8_t option_edited{ 0x02 };
    [[maybe_unused]] constexpr std::uint8_t option_favorited{ 0x04 };
    [[maybe_unused]] constexpr std::uint8_t option_shared{ 0x08 };
    [[maybe_unused]] constexpr std::uint8_t option_deleted{ 0x10 };

    std::uint8_t myArticleFlags{ option_favorited };

    // Set the article as viewed
    myArticleFlags |= option_viewed;
    // Check if the article was deleted
    if (myArticleFlags & option_deleted)
      std::cout << "The article was deleted.\n";
    else
      std::cout << "The article was not deleted.\n";
    // Clear the article as a favorite
    myArticleFlags &= static_cast<std::uint8_t>(~option_favorited);

    std::cout << std::bitset<8>{ myArticleFlags } << '\n';

    return 0;
}
