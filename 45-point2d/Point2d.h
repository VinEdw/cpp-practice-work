#ifndef POINT2D_H
#define POINT2D_H

class Point2d {
  private:
    double m_x { 0.0 };
    double m_y { 0.0 };

  public:
    Point2d() = default;

    Point2d(double x, double y);

    void print() const;

    double distanceTo(const Point2d& p) const;
};

#endif
