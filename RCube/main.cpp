//
// Created by Igor on 03.05.2022.
//

#include <iostream>
#include "RCube.h"
#include <fstream>
#include <cstdlib>

int main(int argc, char *argv[])
{
    RCube cube;
    cube.r();
    cube.l();
    cube.r();
    std::cout << cube;
    return 0;
}