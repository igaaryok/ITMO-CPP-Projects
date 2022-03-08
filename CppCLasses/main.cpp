//
// Created by Igor on 15.02.2022.
//
#include "shapes.h"


int main() {
    // points test
    Point x(0, 0);
    Point y(1, 1);
    Point z{1, 2};
    Point w{50, 20};
    x.getInformation();
    y.getInformation();
    z.getInformation();
    // polyline test
    Polyline p({x, y, z});
    p.getInformation();
    std::cout << p.getPerimeter() << std::endl;
    // closed polyline test
    ClosedPolyline c({x, y, z, w});
    c.getInformation();
    std::cout << c.getPerimeter() << std::endl;
    std::cout << c.getSquare() << std::endl;
    Triangle tri({x, y, z});
//    try {
//        Triangle tri(x, y, w);
//        tri.getInformation();
//    }
//    catch (std::runtime_error &e) {
//        std::cerr << e.what() << std::endl;
//        return -1;
//    }
    return 0;
}

