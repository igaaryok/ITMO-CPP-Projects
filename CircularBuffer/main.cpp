//
// Created by Igor on 15.04.2022.
//

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <queue>
#include <algorithm>
#include "CircularBuffer.h"
#include "algorithms.h"


bool isZero(int i){
    return i == 0;
}

int main(int argc, char *argv[])
{
    std::cout << "Circular buffer test: \n";
    CircularBuffer<int> c(3);
    c.push_back(1);
    c.push_back(2);
    c.push_back(0);
    c.push_back(3);

    std::vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    std::sort(c.begin(), c.end());

    for (int i = 0; i < 3; ++i) {
        std::cout << c[i] << " ";
    }
    std::cout << "\n___________\n";

    std::cout << "algo test:\n";

    std::cout << "All is 0: " << algo::all_of(c.begin(), c.end(), isZero) << "\n";

    std::cout << "Is zero in buffer: " << algo::any_of(c.begin(), c.end(), isZero) << "\n";

    std::cout << "No zero in buffer: " << algo::none_of(c.begin(), c.end(), isZero) << "\n";

    std::cout << "Is one zero in buffer: " << algo::one_of(c.begin(), c.end(), isZero) << "\n";

    std::cout << "Is sorted: " << algo::is_sorted(v.begin(), v.end()) << "\n";

    std::cout << "Is partitioned: " << algo::is_partitioned(v.begin(), v.end(), isZero) << "\n";

    std::cout << "Not zero in buffer: " << *algo::find_not(v.begin(), v.end(), 0) << "\n";

    std::cout << "Find backward: " << *algo::find_backward(v.begin(), v.end(), 4);

    std::cout << "\n___________\n";

    return 0;
}



