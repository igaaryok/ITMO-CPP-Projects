//
// Created by Igor on 03.05.2022.
//

#include "RCube.h"

#include <utility>

RCube::RCube(std::vector<unsigned char> colors) : colors_(std::move(colors)) {
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                cube_[i][j][k] = colors_[i];
            }
        }
    }
}

std::ostream &operator<<(std::ostream &stream, const RCube &other) {
    for (int i = 0; i < 3; ++i) {
        stream << "         | ";
        for (int j = 0; j < 3; ++j) {
            stream << (char) other.cube_[0][i][j] << " ";
        }
        stream << "|\n";
    }
    for (int k = 0; k < 3; ++k) {
        for (int i = 0; i < 4; ++i) {
            stream << "| ";
            for (int j = 0; j < 3; ++j) {
                stream << (char) other.cube_[i+1][k][j] << " ";
            }
            stream << "|";
        }
        stream << "\n";
    }

    for (int i = 0; i < 3; ++i) {
        stream << "         | ";
        for (int j = 0; j < 3; ++j) {
            stream << (char) other.cube_[5][i][j] << " ";
        }
        stream << "|\n";
    }
    return stream;
}

void RCube::r() {
    unsigned int temp[3][3];
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            temp[j][2-i] = cube_[4][i][j];
        }
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cube_[4][i][j] = temp[i][j];
        }
    }
    unsigned int temp2[3];
    for (int i = 0; i < 3; ++i) {
        temp2[i] = cube_[4][i][0];
        cube_[4][i][0] = cube_[0][i][2];
    }
    for (int i = 0; i < 3; ++i) {
        cube_[0][i][2] = cube_[2][i][2];
    }
    for (int i = 0; i < 3; ++i) {
        cube_[2][i][2] = cube_[5][i][2];
    }
    for (int i = 0; i < 3; ++i) {
        cube_[5][i][2] = temp2[i];
    }
}

void RCube::l() {
    unsigned int temp[3][3];
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            temp[j][2-i] = cube_[1][i][j];
        }
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cube_[1][i][j] = temp[i][j];
        }
    }
    unsigned int temp2[3];
    for (int i = 0; i < 3; ++i) {
        temp2[i] = cube_[4][i][2];
        cube_[4][i][2] = cube_[5][i][0];
    }
    for (int i = 0; i < 3; ++i) {
        cube_[5][i][0] = cube_[2][i][0];
    }
    for (int i = 0; i < 3; ++i) {
        cube_[2][i][0] = cube_[0][i][0];
    }
    for (int i = 0; i < 3; ++i) {
        cube_[0][i][0] = temp2[i];
    }
}


