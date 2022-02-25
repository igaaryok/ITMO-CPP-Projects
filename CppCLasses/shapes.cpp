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

void Point::getInformation() const {
    std::cout << "This is point (" << getValueX() << ", " << getValueY() << ")" << std::endl;
}

Point &Point::operator=(const Point &other) = default;

bool operator==(const Point &lhs, const Point &rhs) {
    return (lhs.getValueX() == rhs.getValueX()) && (lhs.getValueY() == rhs.getValueY());
}

std::ostream& operator<<(std::ostream& stream, const Point& point){
    stream << "(" << point.getValueY() << ", " << point.getValueY() << ")";
    return stream;
}

Polyline::Polyline() {
    Point a;
    points_.push_back(a);
}

Polyline::Polyline(const std::vector<Point> &points) {
    for (int i = 0; i < points.size(); ++i) {
        for (int j = i + 1; j < points.size(); ++j) {
            if (points[i] == points[j]) {
                throw std::runtime_error("This is not a polyline.");
            }
        }
    }
    points_ = points;
}

int Polyline::howManyPoints() {
    return points_.size();
}

void Polyline::getInformation() {
    std::cout << "This is polyline: ";
    for (const auto& v: points_) {
        std::cout << v << ", ";
    }
    std::cout << std::endl;
};