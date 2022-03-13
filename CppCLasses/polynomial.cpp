//
// Created by Igor on 12.03.2022.
//

#include "polynomial.h"



// Polynomial
Polynomial::Polynomial() {
    pol_ = {{0, 1}};
}

Polynomial::Polynomial(std::vector<std::pair<double, int>> pol) {
    pol_ = std::move(pol);
}

std::stringstream &operator<<(std::stringstream &stream, const Polynomial &other) {
    for (auto v:other.pol_) {
        if (v.first == 0) continue;
        if (!stream.str().empty()){
            if (v.first > 0) {
                stream << " + ";
            } else{
                stream << " ";
            }
        }
        if (v.first != 1) stream << v.first;
        if (v.second == 0) continue;
        stream << "x^";
        if (v.second != 1) stream << v.second;
    }
    return stream;
}

bool operator==(const Polynomial &other1, const Polynomial &other2) {
    std::stringstream ss1, ss2;
    ss1 << other1;
    ss2 << other2;
    return ss1.str() == ss2.str();
}

bool operator!=(const Polynomial &other1, const Polynomial &other2) {
    return !(other1 == other2);
}

Polynomial Polynomial::operator-(){
    Polynomial temp = *this;
    for (auto & i : temp.pol_) {
        i.first = -i.first;
    }
    return temp;
}

Polynomial operator+(Polynomial &other1, Polynomial &other2) {
    Polynomial other;
    std::pair<double, int> p;
    for (auto v:other1.pol_) {
        bool pairPushed = false;
        for (auto u:other2.pol_) {
            if (v.second == u.second){
                p = {v.first + u.first, v.second};
                other.pol_.push_back(p);
                pairPushed = true;
                break;
            }
        }
        if (!pairPushed){
            other.pol_.push_back(v);
        }
    }
    return other;
}


