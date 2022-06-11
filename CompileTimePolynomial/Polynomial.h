//
// Created by Igor on 03.06.2022.
//

#ifndef ITMO_CPP_PROJECTS_POLYNOMIAL_H
#define ITMO_CPP_PROJECTS_POLYNOMIAL_H

#include <string>
#include <sstream>


template<long value, long ...coefficients>
class Polynomial {

public:

    long &operator[](size_t index) const {
        return coefficients_array_[index];
    }


    long long get_result() const noexcept {
        static constexpr long long result = polynomial_sum();
        return result;
    }

private:
    static constexpr long point_value_ = value;

    static constexpr long coefficients_array_[] = {coefficients...};

    static constexpr size_t size_ = sizeof...(coefficients);


    static constexpr long long polynomial_sum() noexcept {
        long long answer = 0;
        for (int i = 0; i < size_; ++i) {
            answer += pow(point_value_, size_ - 1 - i) * coefficients_array_[i];
        }
        return answer;
    };

    static constexpr long pow(long index, size_t degree) noexcept {
        if (degree == 0) {
            return 1;
        } else if (degree % 2 == 0) {
            return pow(index, degree / 2) * pow(index, degree / 2);
        } else {
            return pow(index, degree - 1) * index;
        }
    }

    friend std::ostream &operator<<(std::ostream &stream, Polynomial<value, coefficients...> const &other) {
        stream << other.get_result();
        return stream;
    }
};

template<long value, long ...coefficients>
std::string str(Polynomial<value, coefficients...>) {
    std::string str;
    long temp[] = {coefficients...};
    size_t tempSize = sizeof...(coefficients);
    for (int i = 0; i < tempSize; ++i) {
        str += std::to_string(temp[i]) + " * ";
        if (value > 0) {
            str += std::to_string(abs(value)) + "^" + std::to_string(tempSize - i) + " ";
        } else {
            str += "(-" + std::to_string(abs(value)) + ")" + "^" + std::to_string(tempSize - i) + " ";
        }

        if (i != tempSize - 1) {
            if (temp[i + 1] > 0) str += "+ ";
            else str += "- ";
        }
    }
    return str;
}

#endif //ITMO_CPP_PROJECTS_POLYNOMIAL_H
