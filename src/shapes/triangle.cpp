#include "point.hpp"
#include "shapes/triangle.hpp"
#include <cmath>
#include "draw.hpp"


Triangle::Triangle(Point P, Point Q, Point R) : A(P), B(Q), C(R) {}

double d1 = A.distance(B);
double d2 = B.distance(C);
double d3 = C.distance(A);
double eps=1e-6; 	//création d'un epsilon pour la comparaison

double Triangle::perimeter() {

	return A.distance(B) +  B.distance(C) + C.distance(A); //on somme les 3 cotés pour obtenir le perimetre
}

double Triangle::area(){

	//on cacule de demie perimetre
	double p= perimeter()/2;

	return std::sqrt(p*(p-A.distance(B))*(p-B.distance(C))*(p-C.distance(A))); //la formule de Héron
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

	return(std::abs(A.x - triangle.A.x) < eps && std::abs(A.y - triangle.A.y) < eps &&
		   std::abs(B.x - triangle.B.x) < eps && std::abs(B.y - triangle.B.y) < eps &&
		   std::abs(C.x - triangle.C.x) < eps && std::abs(C.y - triangle.C.y));
}
//fonction qui teste si le triangle est un triangle rectangle
bool Triangle::isRightAngled(){
	double a2=std::pow(d1,2); //A^2
	double b2=std::pow(d2,2); //B^2
	double c2=std::pow(d3,2); //c^2
	
	return(a2+b2-c2<eps || a2+c2-b2<eps || c2+a2+-b2<eps); //reciproque du théoreme de Pythagore
}

bool Triangle::isEquilateral(){

	return (std::abs(A.distance(B) - B.distance(C)) < eps && std::abs(B.distance(C) - C.distance(A)) < eps);//comparaison des 3 côtés
}

bool Triangle::isIsoceles(){

 return (std::abs(A.distance(B) - B.distance(C)) < eps || std::abs(A.distance(B) - C.distance(A)) < eps || std::abs(C.distance(A) - B.distance(C)) < eps);//comparaison de 2côté minimum
}


Circle Triangle::inscribedCircle() {
  
    double p_sum = A.distance(B)+B.distance(C)+C.distance(A);

    // Centre du cercle (barycentre des sommets)
    double Ix = (A.distance(B) * A.x + B.distance(C) * B.x + C.distance(A) * C.x) / p_sum;
    double Iy = (A.distance(B) * A.y + B.distance(C) * B.y + C.distance(A) * C.y) / p_sum;
    
    // Rayon = Aire / demi-périmètre
    double radius = area() / (perimeter() / 2.0);

    return Circle( radius, Point(Ix, Iy));
}

Circle Triangle::circumscribedCircle() {
    // On calcule les carrés des distances à l'origine pour simplifier les lignes suivantes
    double sqA = A.x * A.x + A.y * A.y;
    double sqB = B.x * B.x + B.y * B.y;
    double sqC = C.x * C.x + C.y * C.y;

    // Le dénominateur commun D
    double D = 2 * (A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y));

    if (std::abs(D) < 1e-6) return Circle(A, 0);

    double Ux = (sqA * (B.y - C.y) + sqB * (C.y - A.y) + sqC * (A.y - B.y)) / D;
    double Uy = (sqA * (C.x - B.x) + sqB * (A.x - C.x) + sqC * (B.x - A.x)) / D;

    Point center_pt(Ux, Uy);

    // On crée le cercle avec ce centre et la distance vers le sommet A comme rayon
    return Circle(center_pt, center_pt.distance(A));
}