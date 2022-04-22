//
// Created by Igor on 15.04.2022.
//

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <queue>
#include "CircularBuffer.h"



int main(int argc, char *argv[])
{
    std::vector<int> v(3);
    CircularBuffer<int> c(3);
    c.push_back(1);
    c.push_back(2);
    c.push_back(1);
    c.push_front(4);
    for (int i = 0; i < 3; ++i) {
        std::cout << c[i] << " ";
    }
    v.pop_back();

    return 0;
}



