#include "point.hpp"
#include "draw.hpp"
#include "shapes/square.hpp"

#include <cmath>
#include <vector>

Square::Square(Point P, Point Q) : A(P), C(Q) {}

double Square::side() {
    return A.distance(C) / std::sqrt(2.0);
}

double Square::perimeter() {
    return 4.0 * side();
}

double Square::area() {
    double s = side();
    return s * s;
}

Point Square::center() {
    return Point((A.x + C.x) / 2.0, (A.y + C.y) / 2.0);
}

void Square::draw() {
    Point O = center();

    double vx = A.x - O.x;
    double vy = A.y - O.y;

    Point B(O.x - vy, O.y + vx);
    Point D(O.x + vy, O.y - vx);

    std::vector<Point> points = { A, B, C, D, A };
    draw_picture(points);
}

void Square::translate(Point T) {
    A.x += T.x;
    A.y += T.y;

    C.x += T.x;
    C.y += T.y;
}

void Square::resize(double ratio) {
    Point O = center();

    A.x = O.x + ratio * (A.x - O.x);
    A.y = O.y + ratio * (A.y - O.y);

    C.x = O.x + ratio * (C.x - O.x);
    C.y = O.y + ratio * (C.y - O.y);
}

void Square::rotate(double angle) {
    Point O = center();

    double cosA = std::cos(angle);
    double sinA = std::sin(angle);

    double ax = A.x - O.x;
    double ay = A.y - O.y;

    double cx = C.x - O.x;
    double cy = C.y - O.y;

    A.x = O.x + ax * cosA - ay * sinA;
    A.y = O.y + ax * sinA + ay * cosA;

    C.x = O.x + cx * cosA - cy * sinA;
    C.y = O.y + cx * sinA + cy * cosA;
}

bool Square::equals(Square square) {
    const double eps = 1e-9;

    bool sameOrder =
        std::abs(A.x - square.A.x) < eps &&
        std::abs(A.y - square.A.y) < eps &&
        std::abs(C.x - square.C.x) < eps &&
        std::abs(C.y - square.C.y) < eps;

    bool reverseOrder =
        std::abs(A.x - square.C.x) < eps &&
        std::abs(A.y - square.C.y) < eps &&
        std::abs(C.x - square.A.x) < eps &&
        std::abs(C.y - square.A.y) < eps;

    return sameOrder || reverseOrder;
}

Circle Square::inscribedCircle() {
    return Circle(side() / 2.0, center());
}

Circle Square::circumscribedCircle() {
    return Circle(A.distance(C) / 2.0, center());
}