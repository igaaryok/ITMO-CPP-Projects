//
// Created by Igor on 12.03.2022.
//

#pragma once

#include <vector>
#include <sstream>
#include <cmath>


class Polynomial {
    std::vector<std::pair<double, int>> pol_;

public:

    Polynomial();

    explicit Polynomial(int degree, const std::vector<double> &coefficients);

    friend std::stringstream &operator<<(std::stringstream &out, const Polynomial &other);

    friend bool operator==(const Polynomial &lhs, const Polynomial &rhs);

    friend bool operator!=(const Polynomial &lhs, const Polynomial &rhs);

    Polynomial operator+();

    Polynomial operator-();

    friend Polynomial operator+(const Polynomial &lhs, const Polynomial &rhs);

    friend Polynomial operator-(const Polynomial &lhs, const Polynomial &rhs);

    friend Polynomial operator*(const Polynomial &lhs, int rhs);

    friend Polynomial operator*(int lhs, const Polynomial &rhs);

    friend Polynomial operator*(const Polynomial &lhs, const Polynomial &rhs);

    Polynomial operator+=(const Polynomial &other);

    Polynomial operator-=(const Polynomial &other);


};




