//
// Created by Igor on 18.05.2022.
//

#pragma once

#include <memory>
#include <limits>
#include <iostream>

#define POOL_SIZE 1000000

template<class T>
class PoolAllocator {
public:
    typedef T value_type;

    PoolAllocator() = default;

    PoolAllocator(size_t size) noexcept: size_(size) {}

    template<class U>
    constexpr PoolAllocator(const PoolAllocator<U> &) noexcept {}

    ~PoolAllocator() noexcept {
        free(memory_pointer);
    }

    T *allocate(size_t n) {

        if (!memory_pointer) {
            size_t blockSize = POOL_SIZE * sizeof(T);

            memory_pointer = static_cast<T *>(std::malloc(blockSize));

            last_data = memory_pointer;
        }

        if (n > POOL_SIZE)
            throw std::bad_array_new_length();

        if (last_data <= memory_pointer + POOL_SIZE) {
            last_data = last_data + n;
            //report(last_data, n);
            return last_data;
        } else {
            last_data = memory_pointer;
            if (last_data) {
                return last_data;
            }
        }

        throw std::bad_alloc();

    }

    void deallocate(T *p, size_t n) noexcept {
        //report(p, n, 0);
    }

private:

    T *memory_pointer = nullptr;

    T *last_data;

    size_t size_ = POOL_SIZE;

    void report(T *p, std::size_t n, bool alloc = true) const {
        std::cout << (alloc ? "Alloc: " : "Dealloc: ") << sizeof(T) * n
                  << " bytes at " << std::hex << std::showbase
                  << reinterpret_cast<void *>(p) << std::dec << '\n';
    }
};

template<class T, class U>
bool operator==(const PoolAllocator<T> &, const PoolAllocator<U> &) {
    return true;
}

template<class T, class U>
bool operator!=(const PoolAllocator<T> &, const PoolAllocator<U> &) {
    return false;
}