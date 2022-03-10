//
// Created by Igor on 15.02.2022.
//
#include <iostream>
#include "shapes.h"


int main() {
    // Points test
    Point x(0, 0);
    Point y(1, 1);
    Point z{1, 2};
    Point w{50, 20};
    std::cout << x.getInformation() << std::endl;
    std::cout << y.getInformation() << std::endl;
    std::cout << z.getInformation() << std::endl;
    // Polyline test
    Polyline p({x, y, z});
    std::cout << p.getInformation() << std::endl;
    std::cout << p.getPerimeter() << std::endl;
    // Closed polyline test
    ClosedPolyline c({x, y, z, w});
    std::cout << c.getInformation() << std::endl;
    std::cout << c.getPerimeter() << std::endl;
    std::cout << c.getSquare() << std::endl;
    // Triangle test
    Triangle tri({x, y, z});
    std::cout << tri.getInformation() << std::endl;
    std::cout << tri.getPerimeter() << std::endl;
    std::cout << tri.getSquare() << std::endl;
    // Polygon
    Polygon pol({x, y, w, z});
    std::cout << pol.getInformation() << std::endl;
    std::cout << pol.getPerimeter() << std::endl;
    std::cout << pol.getSquare() << std::endl;

    return 0;
}

