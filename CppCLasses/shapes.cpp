//
// Created by Igor on 23.02.2022.
//

#include "shapes.h"

Point::Point(double date_x, double date_y) {
    coordinateX_ = date_x;
    coordinateY_ = date_y;
}

Point::Point(const Point &object) {
    coordinateX_ = object.coordinateX_;
    coordinateY_ = object.coordinateY_;
}

Point::~Point() = default;

void Point::setPointPosition(double date_x, double date_y) {
    coordinateX_ = date_x;
    coordinateY_ = date_y;
}

double Point::getValueX() const {
    return coordinateX_;
}

double Point::getValueY() const {
    return coordinateY_;
}

void Point::printPointPosition() const {
    std::cout << "(" << coordinateX_ << ", " << coordinateY_ << ")," << std::endl;
}

void Point::getInformation() const {
    std::cout << "This is point ";
    printPointPosition();
}

Point &Point::operator=(const Point &other) = default;

bool isOnePoint(Point &a, Point &b) {
    return (a.getValueX() == b.getValueX()) && (a.getValueY() == b.getValueY());
}

Polyline::Polyline(int n, Point points[]) {
    pointsNumber = n;
    for (int i = 0; i < n; ++i) {
        points_.push_back(points[i]);
    }
    for (auto v:points_) {
        v.printPointPosition();
    }
}