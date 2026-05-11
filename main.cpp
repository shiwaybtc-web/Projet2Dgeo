#include "draw.hpp"
#include "point.hpp"
#include "shapes.hpp"
#include <vector>
#include <iostream>


int main() {
	
	// Define points in a vector
	std::vector<Point> points = {
		Point(0, 0),
		Point(100, 0),
		Point(100, 100),
		Point(0, 100),
		Point(0, 0)
		
	};
 
    // Create a Point object representing the center
    Point p1(2.5, 3.0);

        // Create a Circle object using the constructor
    Circle c1(50, p1);

        // Print circle details
    c1.draw();

        // Print the area of the circle
    std::cout << "Area of circle: " << c1.area();
        // Another test with default point
        Circle c2(30, Point(0, 0));
        c2.draw();
        std::cout << "Area of circle: " << c2.area();

        return 0;
    }