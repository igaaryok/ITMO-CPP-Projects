//
// Created by Igor on 12.03.2022.
//

#pragma once

#include <vector>
#include <sstream>



class Polynomial {
private:
    std::vector<std::pair<double, int>> pol_;
public:
    Polynomial();

    explicit Polynomial(std::vector<std::pair<double, int>> pol);

    friend std::stringstream &operator<<(std::stringstream &out, const Polynomial &other);

    friend bool operator==(const Polynomial &other1, const Polynomial &other2);

    friend bool operator!=(const Polynomial &other1, const Polynomial &other2);

    friend Polynomial operator+(Polynomial &other1, Polynomial &other2);

    Polynomial operator-();
};




