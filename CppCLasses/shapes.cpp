//
// Created by Igor on 23.02.2022.
//

#include "shapes.h"
#include <iostream>

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
    double x1 = points[0].getValueX();
    double y1 = points[0].getValueY();
    double x2 = points[1].getValueX();
    double y2 = points[1].getValueY();
    bool onOneLine = true;
    for (int i = 2; i < points.size(); ++i) {
        if (x1 == x2 or y1 == y2){
            if (x2 == points[i].getValueX() or y2 == points[i].getValueY()){
                continue;
            }
            return false;
        }
        onOneLine = (((points[i].getValueX() - x1)/(x2-x1) - (points[i].getValueY()-y1)/(y2-y1)) < EPS);
        if (!onOneLine) break;
    }
    return onOneLine;
}

std::pair<double, double> vectorFromPoints(const Point &a, const Point &b) {
    std::pair<double, double> p;
    p.first = b.getValueX() - a.getValueX();
    p.second = b.getValueY() - a.getValueY();
    return p;
}

double cosBetweenVectors(const std::pair<double, double> &a, const std::pair<double, double> &b) {
    return (a.first * b.first + a.second * b.second) /
           (sqrt(pow(a.first, 2) + pow(a.second, 2)) * sqrt(pow(b.first, 2) +
                                                            pow(b.second, 2)));
}

bool isParallel(const std::pair<double, double> &a, const std::pair<double, double> &b) {
    return fabs(a.first * b.second - a.second * b.first) < EPS;
}


// Polyline class
Polyline::Polyline() = default;

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

Polyline::~Polyline() = default;

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
}

double Polyline::getPerimeter() {
    double perimeter = 0;
    for (int i = 1; i < points_.size(); ++i) {
        perimeter += distanceBetweenPoints(points_[i], points_[i - 1]);
    }
    return perimeter;
}


// Closed polyline
ClosedPolyline::ClosedPolyline() : Polyline() {}

ClosedPolyline::ClosedPolyline(const std::vector<Point> &points) : Polyline(points) {}

ClosedPolyline::~ClosedPolyline() = default;

ClosedPolyline::ClosedPolyline(const ClosedPolyline &object) = default;

double ClosedPolyline::getPerimeter() {
    double perimeter = 0;
    if (points_.size() > 1) {
        perimeter = Polyline::getPerimeter() + distanceBetweenPoints(points_[0], points_[points_.size() - 1]);
    }
    return perimeter;
}

double ClosedPolyline::getSquare() {
    double square = 0;
    for (int i = 1; i < points_.size(); ++i) {
        square += points_[i - 1].getValueX() * points_[i].getValueY() -
                  points_[i].getValueX() * points_[i - 1].getValueY();
    }
    square += points_[points_.size() - 1].getValueX() * points_[0].getValueY() -
              points_[0].getValueX() * points_[points_.size() - 1].getValueY();
    square = 1. / 2. * std::abs(square);
    return square;
}

std::string ClosedPolyline::getInformation() {
    return "Closed" + Polyline::getInformation();
}


// Triangle
Triangle::Triangle() : ClosedPolyline() {}

Triangle::Triangle(const std::vector<Point> &points) : ClosedPolyline(points) {
    if (points.size() != 3 or onOneLine(points)) {
        throw std::runtime_error("This is not a triangle");
    }
}

Triangle::~Triangle() = default;

Triangle::Triangle(const Triangle &object) = default;

std::string Triangle::getInformation() {
    std::ostringstream oss;
    oss << "Triangle: ";
    if (points_.size() == 3) {
        oss << points_[0] << " " << points_[1] << " " << points_[2];
    }
    return oss.str();
}

// Polygon
Polygon::Polygon() : ClosedPolyline() {}

Polygon::Polygon(const std::vector<Point> &points) : ClosedPolyline(points) {}

Polygon::~Polygon() = default;

Polygon::Polygon(const Polygon &object) = default;

std::string Polygon::getInformation() {
    std::ostringstream oss;
    oss << "Polygon: ";
    for (const auto &point: points_) {
        oss << point << " ";
    }
    return oss.str();
}


// Regular polygon
RegularPolygon::RegularPolygon() : Polygon() {}

RegularPolygon::RegularPolygon(const std::vector<Point> &points) : Polygon(points) {
    double degree = (points_.size() - 2) * 180. / points_.size();
    double side = distanceBetweenPoints(points_[0], points_[points.size() - 1]);
    for (int i = 0; i < points_.size(); ++i) {
        if (fabs(distanceBetweenPoints(points_[i], points_[i + 1]) - side) > EPS
            or fabs(cosBetweenVectors(vectorFromPoints(points_[i - 1], points_[i]),
                                      vectorFromPoints(points_[i], points_[i + 1])) -
                    cos(degree * PI / 180)) > EPS)
            throw std::runtime_error("This is not a regular polygon.");


    }
}

RegularPolygon::~RegularPolygon() = default;

RegularPolygon::RegularPolygon(const RegularPolygon &object) = default;

std::string RegularPolygon::getInformation() {
    std::ostringstream oss;
    oss << "Regular polygon: ";
    for (const auto &point: points_) {
        oss << point << " ";
    }
    return oss.str();
}


// Trapezoid
Trapezoid::Trapezoid() : Polygon() {}

Trapezoid::Trapezoid(const std::vector<Point> &points) : Polygon(points) {
    if (points_.size() != 4 or
        (isParallel(vectorFromPoints(points_[0], points_[1]), vectorFromPoints(points[2], points[3])) and
         isParallel(vectorFromPoints(points_[0], points_[3]), vectorFromPoints(points[2], points[1]))) or
        !(isParallel(vectorFromPoints(points_[0], points_[1]), vectorFromPoints(points[2], points[3])) or
          isParallel(vectorFromPoints(points_[0], points_[3]), vectorFromPoints(points[2], points[1]))))
        throw std::runtime_error("This is not a regular trapezoid.");
}

Trapezoid::~Trapezoid() = default;

Trapezoid::Trapezoid(const Trapezoid &object) = default;

std::string Trapezoid::getInformation() {
    std::ostringstream oss;
    oss << "Trapezoid: ";
    for (const auto &point: points_) {
        oss << point << " ";
    }
    return oss.str();
}
