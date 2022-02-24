//
// Created by Igor on 15.02.2022.
//
#include "shapes.h"





int main() {
    Point x(0, 0);
    Point y(0, 1);
    Point w(1, 1);
    Point z;

//    Polyline{x, y, w};
    x.getInformation();
    y.getInformation();
    w.getInformation();
    z.getInformation();
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

