//
// Created by Igor on 15.02.2022.
//
#include <iostream>
#include "shapes.h"
#include "polynomial.h"



int main() {
    std::stringstream ss;
    // Points test
    Point x(-2, 0);
    Point y(2, 0);
    Point z{1, 3};
    Point w{-1, 3};
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
    // Polygon test
    Polygon pol({x, y, z, w});
    std::cout << pol.getInformation() << std::endl;
    std::cout << pol.getPerimeter() << std::endl;
    std::cout << pol.getSquare() << std::endl;
    // Regular polygon test
//    RegularPolygon rp({x, y, z});
//    std::cout << rp.getInformation() << std::endl;
    // Trapezoid test
    Trapezoid tr({x, y, z, w});
    std::cout << tr.getInformation() << std::endl;
    std::cout << tr.getSquare() << std::endl;
    // Polynomial test
    Polynomial pole({{2, 2}, {4, 3}});
    Polynomial poly({{1, 2}, {2, 3}, {10, 0}, {0, 200}});
    ss << poly + pole << std::endl;
    std::cout << ss.str();
    return 0;
}

