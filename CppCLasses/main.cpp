//
// Created by Igor on 15.02.2022.
//
#include "shapes.h"


int main() {
    Point x(0, 0);
    Point y(1, 1);
    Point w(1, 1);
    Point z{1, 2};
    x.getInformation();
    y.getInformation();
    w.getInformation();
    z.getInformation();
    Polyline p({x, y, z});
    p.getInformation();
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

