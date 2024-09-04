#include <iostream>
#include <string_view>

class Point3d {
  private:
    int m_x {};
    int m_y {};
    int m_z {};

  public:
    void setValues(int x, int y, int z) {
      m_x = x;
      m_y = y;
      m_z = z;
    }

    void print() const {
      std::cout << '<' << m_x << ", " << m_y << ", " << m_z << '>';
    }

    bool isEqual(const Point3d& p) const {
      return (m_x == p.m_x) && (m_y == p.m_y) && (m_z == p.m_z);
    }
};

void printPointWithLabel(std::string_view s, const Point3d& p) {
  std::cout << s;
  p.print();
  std::cout << '\n';
}

int main() {
  Point3d point1 {};
  point1.setValues(1, 2, 3);
  printPointWithLabel("Point 1: ", point1);

  Point3d point2 {};
  point2.setValues(1, 2, 3);
  printPointWithLabel("Point 2: ", point2);

  Point3d point3 {};
  point3.setValues(3, 4, 5);
  printPointWithLabel("Point 3: ", point3);

  std::cout << "point 1 and point 2 are" << (point1.isEqual(point2) ? "" : " not") << " equal\n";

  std::cout << "point 1 and point 3 are" << (point1.isEqual(point3) ? "" : " not") << " equal\n";
  return 0;
}
