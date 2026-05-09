#include "point.hpp"
#include "shapes/triangle.hpp"

Triangle::Triangle(Point P, Point Q, Point R) : A(P), B(Q), C(R) {}


double Triangle::perimeter() {

	double d1 = A.distance(B);
	double d2 = B.distance(C);
	double d3 = C.distance(A);

	return d1 + d2 + d3; //on somme les 3 cotés pour obtenir le perimetre
}