//
// Created by Igor on 17.05.2022.
//

#include "PoolAllocator.h"

#include <iostream>
#include <vector>
#include <chrono>
#include <map>

long long myAllocatorTest(int n) {
    auto start = std::chrono::steady_clock::now();
    std::vector<int, PoolAllocator<int>> vec;

    for (int i = 0; i < n; ++i) {
        vec.push_back(i);
    }

    auto end = std::chrono::steady_clock::now();

    auto result = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    return result.count();
}

long long stdAllocatorTest(int n) {
    auto start = std::chrono::steady_clock::now();
    std::vector<int> vec;

    for (int i = 0; i < n; ++i) {
        vec.push_back(i);
    }

    auto end = std::chrono::steady_clock::now();

    auto result = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    return result.count();
}

int main(int argc, char *argv[]) {
    int n = 100000;

    std::map<int, PoolAllocator<int>> mapa;

    mapa[0] = 0;
    mapa[1] = 1;
    mapa[2] = 2;
    mapa[3] = 3;
    mapa[4] = 4;

    std::cout << "Time is: " << myAllocatorTest(n) << " microseconds\n";

    std::cout << "Time is: " << stdAllocatorTest(n) << " microseconds\n";
    return 0;
}