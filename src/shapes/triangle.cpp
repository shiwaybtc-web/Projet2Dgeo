#include "point.hpp"
#include "shapes/triangle.hpp"
#include <cmath>
#include "draw.hpp"


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
void Triangle::draw() {
	// On crée un  (vector) de points
	std::vector<Point> points_du_triangle = {A, B, C,A}; //correction j'avais oublié de fermer le triangle en mettant Un autre A à la fin
	draw_picture(points_du_triangle);
}

void Triangle::translate(Point T) {
    // On déplace le point A
    A.x += T.x;
    A.y += T.y;

    // On déplace le point B
    B.x += T.x;
    B.y += T.y;

    // On déplace le point C
    C.x += T.x;
    C.y += T.y;
}

void Triangle::resize(double ratio) {
    Point G = center(); // On récupère ton centre de gravité 
    //correction le centre changais avec l'ancienne methode

    // On redimensionne l'écart par rapport au centre
    A.x = G.x + (A.x - G.x) * ratio;
    A.y = G.y + (A.y - G.y) * ratio;
    
    B.x = G.x + (B.x - G.x) * ratio;
    B.y = G.y + (B.y - G.y) * ratio;
    
    C.x = G.x + (C.x - G.x) * ratio;
    C.y = G.y + (C.y - G.y) * ratio;
}

void Triangle::rotate(double angle) {
    Point G = center();

    // ROTATION DU POINT A 
    // Calcul de l'écart par rapport au centre
    double dxA = A.x - G.x;
    double dyA = A.y - G.y;
    // Formule mathématique appliquée directement à A
    A.x = G.x + dxA * std::cos(angle) - dyA * std::sin(angle);
    A.y = G.y + dxA * std::sin(angle) + dyA * std::cos(angle);

    // ROTATION DU POINT B 
    double dxB = B.x - G.x;
    double dyB = B.y - G.y;
    B.x = G.x + dxB * std::cos(angle) - dyB * std::sin(angle);
    B.y = G.y + dxB * std::sin(angle) + dyB * std::cos(angle);


    // ROTATION DU POINT C
    double dxC = C.x - G.x;
    double dyC = C.y - G.y;
    C.x = G.x + dxC * std::cos(angle) - dyC * std::sin(angle);
    C.y = G.y + dxC * std::sin(angle) + dyC * std::cos(angle);
}

//cmparaison 2 triangles
bool Triangle::equals(Triangle triangle) {
	//création d'un epsilon pour la comparaison
	double eps=1e-6;

	return(std::abs(A.x - triangle.A.x) < eps && std::abs(A.y - triangle.A.y) < eps &&
		   std::abs(B.x - triangle.B.x) < eps && std::abs(B.y - triangle.B.y) < eps &&
		   std::abs(C.x - triangle.C.x) < eps && std::abs(C.y - triangle.C.y));
}

bool triangle::isRightAngled(){
	double a2=std::pow(B.distance(C),2); //A^2
	double b2=std::pow(A.distance(C),2); //B^2
	double c2=std::pow(A.distance(B),2); //c^2
	double eps=1e-6;
	
	return(a2+b2-c2<eps || a2+c2-b2<eps || c2+a2+-b2<eps); //reciproque du théoreme de Pythagore
}