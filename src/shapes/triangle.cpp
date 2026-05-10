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

	return std::sqrt(p*(p-d1)*(p-d2)*(p-d3)); //la formule de Héron
}

Point Triangle::center() {
    // La coordonnée X du centre est la moyenne des X 
    double centerX = (A.x + B.x + C.x) / 3.0;
    
    // La coordonnée Y du centre est la moyenne des Y 
    double centerY = (A.y + B.y + C.y) / 3.0;
    
    return Point(centerX, centerY);
}