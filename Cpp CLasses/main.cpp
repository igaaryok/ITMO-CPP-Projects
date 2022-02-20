//
// Created by Igor on 15.02.2022.
//
#include <iostream>
#include <cmath>
#include <set>

class Point {
private:
    double coordinateX{},
            coordinateY{};
public:
    explicit Point(double date_x = 0, double date_y = 0) {
        setPointPosition(date_x, date_y);
    }

    Point(Point &object) {
        coordinateX = object.coordinateX;
        coordinateY = object.coordinateY;
    }

    void setPointPosition(double date_x, double date_y) {
        coordinateX = date_x;
        coordinateY = date_y;
    }

    double getValueX() const {
        return coordinateX;
    }

    double getValueY() const {
        return coordinateY;
    }

    void printPointPosition() const {
        std::cout << "(" << coordinateX << ", " << coordinateY << ")," << std::endl;
    }

    void getInformation() const {
        std::cout << "This is point ";
        printPointPosition();
    }
};

bool isOnePoint(const Point &a, const Point &b) {
    return (a.getValueX() == b.getValueX()) && (a.getValueY() == b.getValueY());
}

class Triangle {
private:
    Point pointA,
            pointB,
            pointC;
public:
    Triangle(const Point &a, const Point &b, const Point &c) {
        setPoints(a, b, c);
    }

    static int checkTriangle(const Point &a, const Point &b, const Point &c) {
        std::set<double> setX, setY;
        setX.insert(a.getValueX());
        setX.insert(b.getValueX());
        setX.insert(c.getValueX());
        setY.insert(a.getValueY());
        setY.insert(b.getValueY());
        setY.insert(c.getValueY());
        return (setX.set::size() > 1 && setY.set::size() > 1) &&
               !(isOnePoint(a, b) || isOnePoint(a, c) || isOnePoint(b, c));
    }

    void setPoints(const Point &a, const Point &b, const Point &c) {
        if (checkTriangle(a, b, c)) {
            pointA = a;
            pointB = b;
            pointC = c;
        } else {
            throw std::runtime_error("This is not triangle.");
        }
    }

    double getArea() {
        return 1. / 2. * fabs((pointB.getValueX() - pointA.getValueX()) * (pointC.getValueY() - pointA.getValueY()) -
                              (pointC.getValueX() - pointA.getValueX()) * (pointB.getValueY() - pointA.getValueY()));
    }

    double getPerimeter() {
        return sqrt(pow(pointB.getValueX() - pointA.getValueX(), 2) + pow(pointB.getValueY() - pointA.getValueY(), 2)) +
               sqrt(pow(pointC.getValueX() - pointA.getValueX(), 2) + pow(pointC.getValueY() - pointA.getValueY(), 2)) +
               sqrt(pow(pointB.getValueX() - pointC.getValueX(), 2) + pow(pointB.getValueY() - pointC.getValueY(), 2));
    }

    void getInformation() {
        std::cout << "Triangle[" << std::endl;
        std::cout << "  ";
        pointA.printPointPosition();
        std::cout << "  ";
        pointB.printPointPosition();
        std::cout << "  ";
        pointC.printPointPosition();
        std::cout << "], with area: " << getArea() << ", with perimeter: " << getPerimeter() << std::endl;
    }
};


int main() {
    Point x(1000, 0.5);
    Point y(1, 0.4789);
    Point w(111, 10);
    x.getInformation();
    y.getInformation();
    w.getInformation();
    try {
        Triangle tri(x, y, w);
        tri.getInformation();
    }
    catch (std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
        return -1;
    }
    return 0;
}

