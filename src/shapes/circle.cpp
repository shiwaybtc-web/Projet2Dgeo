#include "point.hpp"
#include "shapes/circle.hpp"
#include <vector>
#include <math.h>
#include "draw.hpp"

Circle::Circle(double r, Point c) : radius(r), center(c) {};
double Circle::circumference() {
	return 3.14 * 2 * radius;
}
double Circle::area() {
	return 3.14 * radius * radius;
}
void Circle::draw() {
	std::vector<Point> points;
	for (int i = 0; i < 360; i = i + 10) {
		double a = i * 3.14 / 180;
		double x = center.x + radius * cos(a); //abscisse du point appartenant au cercle
		double y = center.y + radius * sin(a); //ordonnée du point appartenant au cercle
		points.push_back(Point(x, y)); //ajout du point pour le tracé
	}
	draw_picture(points);
}
void Circle::translate(Point T) {
	Point s;
	s.x = center.x + T.x;
	s.y = center.y + T.y;
}