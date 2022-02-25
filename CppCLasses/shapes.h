//
// Created by Igor on 23.02.2022.
//

#pragma once

#include <iostream>
#include <cmath>
#include <set>
#include <vector>
#include <cstdarg>

class Point {
private:
    double coordinateX_;
    double coordinateY_;
public:

    explicit Point(double date_x = 0, double date_y = 0);

    Point(const Point &object);

    virtual ~Point();

    void setPointPosition(double date_x, double date_y);

    double getValueX() const;

    double getValueY() const;

    void getInformation() const;

    Point &operator=(const Point &other);

};

bool operator==(const Point& lhs, const Point& rhs);
bool operator&&(const Point& lhs, const Point& rhs);
std::ostream& operator<<(std::ostream& stream, const Point& point);

//class Triangle {
//private:
//    Point pointA_,
//            pointB_,
//            pointC_;
//public:
//    Triangle(const Point &a, const Point &b, const Point &c) {
//        setPoints(a, b, c);
//    }
//
//    static int checkTriangle(const Point &a, const Point &b, const Point &c) {
//        std::set<double> setX, setY;
//        setX.insert(a.getValueX());
//        setX.insert(b.getValueX());
//        setX.insert(c.getValueX());
//        setY.insert(a.getValueY());
//        setY.insert(b.getValueY());
//        setY.insert(c.getValueY());
//        return (setX.set::size() > 1 && setY.set::size() > 1) &&
//               !(isOnePoint(a, b) || isOnePoint(a, c) || isOnePoint(b, c));
//    }
//
//    void setPoints(const Point &a, const Point &b, const Point &c) {
//        if (checkTriangle(a, b, c)) {
//            pointA_ = a;
//            pointB_ = b;
//            pointC_ = c;
//        } else {
//            throw std::runtime_error("This is not triangle.");
//        }
//    }
//
//    double getArea() {
//        return 1. / 2. * fabs((pointB_.getValueX() - pointA_.getValueX()) * (pointC_.getValueY() - pointA_.getValueY()) -
//                              (pointC_.getValueX() - pointA_.getValueX()) * (pointB_.getValueY() - pointA_.getValueY()));
//    }
//
//    double getPerimeter() {
//        return sqrt(pow(pointB_.getValueX() - pointA_.getValueX(), 2) + pow(pointB_.getValueY() - pointA_.getValueY(), 2)) +
//               sqrt(pow(pointC_.getValueX() - pointA_.getValueX(), 2) + pow(pointC_.getValueY() - pointA_.getValueY(), 2)) +
//               sqrt(pow(pointB_.getValueX() - pointC_.getValueX(), 2) + pow(pointB_.getValueY() - pointC_.getValueY(), 2));
//    }
//
//    void getInformation() {
//        std::cout << "Triangle[" << std::endl;
//        std::cout << "  ";
//        pointA_.printPointPosition();
//        std::cout << "  ";
//        pointB_.printPointPosition();
//        std::cout << "  ";
//        pointC_.printPointPosition();
//        std::cout << "], with area: " << getArea() << ", with perimeter: " << getPerimeter() << std::endl;
//    }
//};

class Polyline {
private:
    std::vector<Point> points_;
public:
    Polyline();

    explicit Polyline(const std::vector<Point> &points);

    int howManyPoints();

    void getInformation();

};


