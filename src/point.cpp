#include "point.hpp"
#include <cmath>

Point::Point(double x_val, double y_val) : x(x_val), y(y_val) {}

double Point::distance(Point B) {
    return std::sqrt((x - B.x) * (x - B.x) + (y - B.y) * (y - B.y));
}