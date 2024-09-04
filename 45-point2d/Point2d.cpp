#include <iostream>
#include <cmath>
#include "Point2d.h"

Point2d::Point2d(double x, double y)
  : m_x { x }
  , m_y { y }
{
}

void Point2d::print() const {
  std::cout << "Point2d(" << m_x << ", " << m_y << ")\n";
}

double Point2d::distanceTo(const Point2d& p) const {
  double delta_x { m_x - p.m_x };
  double delta_y { m_y - p.m_y };
  return std::sqrt(std::pow(delta_x, 2) + std::pow(delta_y, 2));
}
