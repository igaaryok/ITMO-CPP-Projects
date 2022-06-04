//
// Created by Igor on 03.06.2022.
//

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Polynomial.h"

int main(int argc, char *argv[])
{
    std::cout << "Polynomial test" << "\n";
    std::cout << "_______________" << "\n";
    Polynomial<100, 1, 2, 3, 4, 5> pol;
    Polynomial<10, 1, 2, 3, 4, 5> pol1;
    Polynomial<5, 1, 2, 3, 4, 5> pol2;
    Polynomial<1, 1, 2, 3, 4, 5> pol3;
    std :: cout << "Polynomial sum: " << pol << "\n";
    std :: cout << "Polynomial sum: " << pol1 << "\n";
    std :: cout << "Polynomial sum: " << pol2 << "\n";
    std :: cout << "Polynomial sum: " << pol3 << "\n";
    return 0;
}