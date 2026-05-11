#include "point.hpp"
#include "shapes/circle.hpp"

Circle::Circle(double r, Point c) : radius(r), center(c) {};
double Circle::circumference() {
	return 3.14 * 2 * radius;
}
double Circle::area() {
	return 3.14 * radius * radius;
}