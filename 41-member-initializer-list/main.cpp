#include <iostream>
#include <string>
#include <string_view>

class Ball {
  private:
    std::string m_color { "none" };
    double m_radius { 0.0 };

  public:
    Ball(std::string_view color, double radius)
      : m_color { color }
      , m_radius { radius }
    {
    }

    const std::string& get_color() const {
      return m_color;
    }
    void set_color(std::string_view color) {
      m_color = color;
    }

    double get_radius() const {
      return m_radius;
    }
    void set_radius(double radius) {
      m_radius = radius;
    }
};

void print(const Ball& ball) {
  std::cout << "Ball(" << ball.get_color() << ", " << ball.get_radius() << ")\n";
}

int main() {
	Ball blue { "blue", 10.0 };
	print(blue);

	Ball red { "red", 12.0 };
	print(red);

	return 0;
}
