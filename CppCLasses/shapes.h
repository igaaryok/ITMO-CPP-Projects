//
// Created by Igor on 23.02.2022.
//

#pragma once

#include <iostream>
#include <cmath>
#include <set>
#include <vector>
#include <cstdarg>
#include <string>
#include <sstream>


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

    std::string getInformation() const;

    Point &operator=(const Point &other);

};

bool operator==(const Point &lhs, const Point &rhs);

bool operator&&(const Point &lhs, const Point &rhs);

std::ostream &operator<<(std::ostream &stream, const Point &point);

double distanceBetweenPoints(const Point &a, const Point &b);

bool onOneLine(const std::vector<Point> &points);


class Polyline {
protected:
    std::vector<Point> points_;
public:
    explicit Polyline(const std::vector<Point> &points);

    Polyline(const Polyline &object);

    unsigned int howManyPoints();

    virtual double getPerimeter();

    virtual std::string getInformation();

};


class ClosedPolyline : public Polyline {
public:
    explicit ClosedPolyline(const std::vector<Point> &points);

    ClosedPolyline(const ClosedPolyline &object);

    double getPerimeter() override;

    double getSquare();

    std::string getInformation() override;
};


class Triangle : public ClosedPolyline {
public:
    explicit Triangle(const std::vector<Point> &points);

    std::string getInformation() override;
};


class Polygon : public ClosedPolyline {
public:
    explicit Polygon(const std::vector<Point> &points);
};
