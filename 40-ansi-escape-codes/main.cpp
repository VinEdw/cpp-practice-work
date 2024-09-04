#include <iostream>

namespace Codes {
  enum Color {
    black = 30,
    red = 31,
    green = 32,
    yellow = 33,
    blue = 34,
    magenta = 35,
    cyan = 36,
    white = 37,
    default_color = 39,
  };

  enum Format {
    reset = 0,
    bold = 1,
    italic = 3,
    underline = 4,
    blink_slow = 5,
    blink_rapid = 6,
    inverse = 7,
    crossed_out = 9,
    double_underline = 21,
    bold_off = 22,
    italic_off = 23,
    underline_off = 24,
    blink_off = 25,
    inverse_off = 27,
    crossed_out_off = 29,
  };
}

// Control formatting

void set_formatting(Codes::Format format) {
  std::cout << "\033[" << static_cast<int>(format) << 'm';
}

// Control foreground color

void set_foreground_color(Codes::Color color) {
  std::cout << "\033[" << static_cast<int>(color) << 'm';
}

void set_foreground_color(int r, int g, int b) {
  std::cout << "\033[38;2;" << r << ";" << g << ";" << b << 'm';
}

// Control background color

void set_background_color(Codes::Color color) {
  std::cout << "\033[" << 10 + static_cast<int>(color) << 'm';
}

void set_background_color(int r, int g, int b) {
  std::cout << "\033[48;2;" << r << ";" << g << ";" << b << 'm';
}

int main() {
  set_foreground_color(0, 255, 255);
  set_background_color(Codes::magenta);
  set_formatting(Codes::blink_slow);
  std::cout << "Hello there!\n";

  set_formatting(Codes::blink_off);
  set_formatting(Codes::italic);
  set_background_color(20, 20, 20);
  set_foreground_color(245, 161, 66);
  std::cout << "-Vincent\n";

  set_formatting(Codes::reset);

  return 0;
}
