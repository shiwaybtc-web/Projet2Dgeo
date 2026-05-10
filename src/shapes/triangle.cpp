#include "point.hpp"
#include "shapes/triangle.hpp"
#include <cmath>


Triangle::Triangle(Point P, Point Q, Point R) : A(P), B(Q), C(R) {}


double Triangle::perimeter() {

	double d1 = A.distance(B);
	double d2 = B.distance(C);
	double d3 = C.distance(A);

	return d1 + d2 + d3; //on somme les 3 cotés pour obtenir le perimetre
}

double Triangle::area(){

	double d1 = A.distance(B);
	double d2 = B.distance(C);
	double d3 = C.distance(A);
	//on cacule de demie perimetre
	double p= perimeter()/2;

	return std::sqrt(p*(p*d1)+(p*d3)+(p*d2)); //la formule de Héron 
}