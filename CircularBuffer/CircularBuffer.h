//
// Created by Igor on 15.04.2022.
//

#pragma once

template<typename _tp, typename _alloc = std::allocator<_tp> >
class CircularBuffer {
private:
    _tp *data_;
    size_t capacity_;
    _tp *start_ = NULL;
    _tp *end_ = NULL;

    _tp *pointerIncrement(_tp *pointer) {
        pointer = data_ + (pointer + 1 - data_) % capacity_;
        return pointer;
    }

    _tp *pointerDecrement(_tp *pointer) {
        if (pointer == data_) {
            pointer = data_ + capacity_ - 1;
            return pointer;
        }
        --pointer;
        return pointer;
    }

public:

    CircularBuffer() : data_(NULL), capacity_(0) {}

    explicit CircularBuffer(size_t capacity) {
        data_ = new _tp[capacity];
        capacity_ = capacity;
    }



    ~CircularBuffer() {
        delete[] data_;
    }

    _tp &operator[](size_t index) const{
        if (end_ == NULL){
            throw std::runtime_error("Error: circular buffer is empty");
        }
        if (index >= capacity_){
            throw std::runtime_error("Error: index is out of range");
        }
        return *(data_ + (start_ + index - data_) % capacity_);
    }

    void push_back(const _tp value) {
        if (end_ == NULL) {
            *data_ = value;
            start_ = end_ = data_;
            return;
        }
        end_ = pointerIncrement(end_);
        if (end_ == start_) {
            start_ = pointerIncrement(start_);
        }
        *end_ = value;
    }

    void push_front(const _tp value) {
        if (start_ == NULL) {
            *data_ = value;
            end_ = start_ = data_;
            return;
        }
        start_ = pointerDecrement(start_);
        if (end_ == start_) {
            end_ = pointerDecrement(end_);
        }
        *start_ = value;
    }

    void pop_back() {
        if (end_ == NULL) {
            return;
        }
        if (end_ == start_) {
            end_ = NULL;
            start_ = NULL;
            return;
        }
        end_ = pointerDecrement(end_);
    }

    void pop_front() {
        if (start_ == NULL) {
            return;
        }
        if (end_ == start_) {
            end_ = NULL;
            start_ = NULL;
            return;
        }
        *start_ = -1;
        start_ = pointerIncrement(start_);
    }

    _tp front(){
        return *start_;
    }

    _tp back(){
        return *end_;
    }



    void print() {
        for (_tp *i = data_; i < data_ + capacity_; ++i) {
            std::cout << *i << " ";
        }
        std::cout << "\n" << "start: " << start_ - data_ << " end: " << end_ - data_ << "\n";
    }

    size_t capacity() const { return capacity_; }

};



