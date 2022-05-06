//
// Created by Igor on 03.05.2022.
//

#pragma once
#include <iostream>
#include <cstring>
#include <vector>


class RCube {
private:
    std::vector<unsigned char> colors_;
    unsigned int cube_[6][3][3];
public:
    RCube(std::vector<unsigned char> colors = {'g', 'r', 'w', 'o', 'y', 'b'});

    friend std::ostream &operator<<(std::ostream &stream, const RCube &other);

    void r();

    void l();
};



