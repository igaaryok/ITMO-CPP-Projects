//
// Created by Igor on 12.03.2022.
//

#include "polynomial.h"
#include <iostream>


// Polynomial
Polynomial::Polynomial() {
    pol_ = {};
}

Polynomial::Polynomial(int degree, const std::vector<double> &coefficients) {
    for (auto v: coefficients) {
        pol_.emplace_back(v, degree--);
        if (degree < 0) return;
    }
}

std::stringstream &operator<<(std::stringstream &stream, const Polynomial &other) {
    if (other.pol_.empty()) {
        stream << 0;
        return stream;
    }
    if (other.pol_.size() == 1) {
        if (other.pol_[0].first == 0) {
            stream << 0;
            return stream;
        }
    }
    if (other.pol_[0].first < 0) {
        stream << "- ";
    }
    bool allZeroes = true;
    for (int i = 0; i < other.pol_.size(); ++i) {
        if (other.pol_[i].first == 0) continue;
        allZeroes = false;
        if (i > 0) {
            if (other.pol_[i].first > 0) {
                stream << " + ";
            } else stream << " - ";
        }
        if (other.pol_[i].first != 1) stream << fabs(other.pol_[i].first);
        if (other.pol_[i].second == 0) continue;
        if (other.pol_[i].second == 1) {
            stream << "x";
            continue;
        }
        stream << "x^" << other.pol_[i].second;

    }
    if (allZeroes) stream << 0;
    return stream;
}

bool operator==(const Polynomial &lhs, const Polynomial &rhs) {
    std::stringstream ss1, ss2;
    ss1 << lhs;
    ss2 << rhs;
    return ss1.str() == ss2.str();
}

bool operator!=(const Polynomial &lhs, const Polynomial &rhs) {
    return !(lhs == rhs);
}

Polynomial Polynomial::operator+() {
    Polynomial temp = *this;
    return temp;
}

Polynomial Polynomial::operator-() {
    Polynomial temp = *this;
    for (auto &i: temp.pol_) {
        i.first = -i.first;
    }
    return temp;
}

Polynomial operator+(const Polynomial &lhs, const Polynomial &rhs) {
    if (lhs.pol_.empty() or rhs.pol_.empty()) {
        return lhs.pol_.empty() ? rhs : lhs;
    }
    Polynomial result;
    int max = std::max(rhs.pol_[0].second, lhs.pol_[0].second);
    int min = std::min(rhs.pol_[rhs.pol_.size() - 1].second, lhs.pol_[lhs.pol_.size() - 1].second);
    int degree = max;
    for (int i = 0; i < (max - min + 1); ++i) {
        result.pol_.emplace_back(0, degree);
        for (auto &j: lhs.pol_) {
            if (j.second == degree) {
                result.pol_[max - degree].first += j.first;
                break;
            }
        }
        for (auto &j: rhs.pol_) {
            if (j.second == degree) {
                result.pol_[max - degree].first += j.first;
                break;
            }
        }
        --degree;
    }
    return result;
}

Polynomial operator-(const Polynomial &lhs, const Polynomial &rhs) {
    Polynomial temp = rhs;
    temp = -temp;
    return lhs + temp;
}

Polynomial operator*(const Polynomial &lhs, double rhs) {
    Polynomial temp;
    std::pair<double, int> tempPair;
    for (auto i:lhs.pol_) {
        tempPair = i;
        tempPair.first *= rhs;
        temp.pol_.emplace_back(tempPair);
    }
    return temp;
}

Polynomial operator*(double lhs, const Polynomial &rhs){
    return rhs * lhs;
}

Polynomial operator*(const Polynomial &lhs, const Polynomial &rhs){
    Polynomial temp1;
    Polynomial temp2;
    for (const auto & i : lhs.pol_) {
        for (const auto & j : rhs.pol_) {
            temp1.pol_ = {i};
            temp1.pol_[0].first *= j.first;
            temp1.pol_[0].second += j.second;
            temp2 += temp1;
        }
    }
    return temp2;
}

Polynomial operator/(const Polynomial &lhs, double rhs){
    Polynomial temp = lhs;
    for (auto & i : temp.pol_) {
        i.first /= rhs;
    }
    return temp;
}

Polynomial Polynomial::operator+=(const Polynomial &other) {
    *this = other + *this;
    return *this;
}

Polynomial Polynomial::operator-=(const Polynomial &other) {
    *this = *this - other;
    return *this;
}

Polynomial Polynomial::operator*=(const Polynomial &other) {
    *this = *this * other;
    return *this;
}

Polynomial Polynomial::operator*=(double &other) {
    *this = *this * other;
    return *this;
}

Polynomial Polynomial::operator/=(double other) {
    *this = *this / other;
    return *this;
}

int Polynomial::operator[](int number) const {
    return pol_[number].second;
}

std::pair<double, int> &Polynomial::operator[](int number){
    return pol_[number];
}




