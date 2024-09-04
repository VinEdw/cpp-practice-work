#include <iostream>
#include <string>
#include <string_view>

class Ball
{
  private:
    static constexpr std::string_view default_color { "black" };
    static constexpr double default_radius { 10.0 };

    std::string m_color { default_color };
    double m_radius { default_radius };

  public:
    Ball(double radius)
      : Ball { default_color, radius }
    {
    }

    Ball(std::string_view color=default_color, double radius=default_radius)
      : m_color { color }
      , m_radius { radius }
    {
      print();
    }

    void print() const
    {
      std::cout << "Ball(" << m_color << ", " << m_radius << ")\n";
    }

};

int main()
{
  Ball def{};
  Ball blue{ "blue" };
  Ball twenty{ 20.0 };
  Ball blueTwenty{ "blue", 20.0 };

  return 0;
}
