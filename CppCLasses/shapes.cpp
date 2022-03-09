//
// Created by Igor on 23.02.2022.
//

#include "shapes.h"


// Point class
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

std::string Point::getInformation() const {
    std::ostringstream oss;
    oss << "Point (" << getValueX() << ", " << getValueY() << ")";
    return oss.str();
}

Point &Point::operator=(const Point &other) = default;

bool operator==(const Point &lhs, const Point &rhs) {
    return (lhs.getValueX() == rhs.getValueX()) && (lhs.getValueY() == rhs.getValueY());
}

std::ostream &operator<<(std::ostream &stream, const Point &point) {
    stream << "(" << point.getValueX() << ", " << point.getValueY() << ")";
    return stream;
}

double distanceBetweenPoints(const Point &a, const Point &b) {
    return sqrt(pow(b.getValueX() - a.getValueX(), 2) + pow(b.getValueY() - a.getValueY(), 2));
}

bool onOneLine(const std::vector<Point> &points) {
    double x = points[0].getValueX();
    double y = points[0].getValueY();
    bool sameX = true;
    bool sameY = true;
    for (int i = 1; i < points.size(); ++i) {
        if (points[i].getValueX() != x) {
            sameX = false;
        }
        if (points[i].getValueY() != y) {
            sameY = false;
        }
    }
    return sameX or sameY;
}

bool isIntersection(std::pair<Point, Point>, std::pair<Point, Point>){

}

// Polyline class
Polyline::Polyline(const std::vector<Point> &points) {
    if (points.size() < 2) throw std::runtime_error("This is not a polyline.");
    for (int i = 0; i < points.size(); ++i) {
        for (int j = i + 1; j < points.size(); ++j) {
            if (points[i] == points[j]) {
                throw std::runtime_error("This is not a polyline.");
            }
        }
    }
    points_ = points;
}

Polyline::Polyline(const Polyline &object) {
    points_ = object.points_;
}

unsigned int Polyline::howManyPoints() {
    return points_.size();
}

std::string Polyline::getInformation() {
    std::ostringstream oss;
    oss << "Polyline: ";
    for (const auto &v: points_) {
        oss << v << " ";
    }
    return oss.str();
};

double Polyline::getPerimeter() {
    double perimeter = 0;
    for (int i = 1; i < points_.size(); ++i) {
        perimeter += distanceBetweenPoints(points_[i], points_[i - 1]);
    }
    return perimeter;
}


// Closed polyline
ClosedPolyline::ClosedPolyline(const std::vector<Point> &points) : Polyline(points) {}

ClosedPolyline::ClosedPolyline(const ClosedPolyline &object) = default;

double ClosedPolyline::getPerimeter() {
    double perimeter = Polyline::getPerimeter() + distanceBetweenPoints(points_[0], points_[points_.size() - 1]);
    return perimeter;
}

double ClosedPolyline::getSquare() {
    double square = 0;
    for (int i = 1; i < points_.size(); ++i) {
        square += points_[i - 1].getValueX() * points_[i].getValueY() -
                  points_[i].getValueX() * points_[i - 1].getValueY();
    }
    square = 1. / 2. * std::abs(square);
    return square;
}

std::string ClosedPolyline::getInformation() {
    return "Closed" + Polyline::getInformation();
}


// Triangle
Triangle::Triangle(const std::vector<Point> &points) : ClosedPolyline(points) {
    if (points.size() != 3 or onOneLine(points)) {
        throw std::runtime_error("This is not a triangle");
    }
}

std::string Triangle::getInformation() {
    std::ostringstream oss;
    oss << "Triangle: " << points_[0] << " " << points_ [1] << " " << points_ [2];
    return oss.str();
}

// Polygon
Polygon::Polygon(const std::vector<Point> &points) : ClosedPolyline(points) {

}