//
// Created by Igor on 15.04.2022.
//

#pragma once

template<typename _tp>
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

    class Iterator {
        _tp *_data_;
        size_t _capacity_;
        _tp *_start_ = NULL;
        _tp *_end_ = NULL;

        _tp *pointerIncrement(_tp *pointer) {
            pointer = _data_ + (pointer + 1 - _data_) % _capacity_;
            return pointer;
        }

        _tp *pointerDecrement(_tp *pointer) {
            if (pointer == _data_) {
                pointer = _data_ + _capacity_ - 1;
                return pointer;
            }
            --pointer;
            return pointer;
        }

    public:
        using iterator_category = std::random_access_iterator_tag;
        using value_type = _tp;
        using difference_type = std::ptrdiff_t;
        using pointer = _tp*;
        using reference = _tp&;

        Iterator(_tp *data, size_t capacity, _tp *start, _tp *end) {
            _data_ = data;
            _capacity_ = capacity;
            _start_ = start;
            _end_ = end;
        }

        Iterator(const Iterator &other) {
            _data_ = other._data_;
            _capacity_ = other._capacity_;
            _start_ = other._start_;
            _end_ = other._end_;
        }

        ~Iterator() = default;

        Iterator &operator+=(difference_type other) {
            for (int i = 0; i < other; ++i) {
                _start_ = pointerIncrement(_start_);
            }
            return *this;
        }

        Iterator operator+(difference_type other) {
            Iterator temp = *this;
            temp += other;
            return temp;
        }

        Iterator &operator++() {
            _start_ = pointerIncrement(_start_);
            return *this;
        }

        Iterator &operator-=(difference_type other) {
            for (int i = 0; i < other; ++i) {
                _start_ = pointerDecrement(_start_);
            }
            return *this;
        }

        Iterator operator-(difference_type other) {
            Iterator temp = *this;
            temp -= other;
            return temp;
        }

        difference_type operator-(const Iterator &other) {
            _tp *tempThis = this->_start_;
            int thisIndex = 0;
            _tp *tempOther = other._start_;
            int otherIndex = 0;
            while (tempThis != this->_end_ or other._start_ != tempOther) {
                if (tempThis != this->_end_){
                    tempThis = pointerIncrement(tempThis);
                    ++tempThis;
                }
                if (other._start_ != tempOther){
                    tempOther = pointerIncrement(tempOther);
                    ++otherIndex;
                }
            }
            return abs(thisIndex - otherIndex);
        }

        Iterator &operator--() {
            _start_ = pointerDecrement(_start_);
        }

        _tp &operator*() {
            return *_start_;
        }

        _tp *operator->() {
            return _start_;
        }

        bool operator==(const Iterator &other) {
            return _start_ == other._start_;
        }

        bool operator!=(const Iterator &other) {
            return _start_ != other._start_;
        }

        bool operator<(const Iterator &other) {
            _tp *tempThis = this->_start_;
            _tp *tempOther = other._start_;
            while (tempThis != this->_end_ or other._start_ != tempOther) {
                tempThis = pointerIncrement(tempThis);
                tempOther = pointerIncrement(tempOther);
                if (tempThis == this->_end_ and tempOther != other._end_) {
                    return true;
                }
            }
            return false;
        }

        bool operator>(const Iterator &other) {
            _tp *tempThis = this->_start_;
            _tp *tempOther = other._start_;
            while (tempThis != this->_end_ or other._start_ != tempOther) {
                tempThis = pointerIncrement(tempThis);
                tempOther = pointerIncrement(other);
                if (tempOther == other._end_ and tempThis != this->_end_) {
                    return true;
                }
            }
            return false;
        }

        bool operator>=(const Iterator &other) {
            _tp *tempThis = this->_start_;
            _tp *tempOther = other._start_;
            while (tempThis != this->_end_ or other._start_ != tempOther) {
                tempThis = pointerIncrement(tempThis);
                tempOther = pointerIncrement(other);
                if (tempOther == other._end_) {
                    return true;
                }
            }
            return false;
        }

        bool operator<=(const Iterator &other) {
            _tp *tempThis = this->_start_;
            _tp *tempOther = other._start_;
            while (tempThis != this->_end_ or other._start_ != tempOther) {
                tempThis = pointerIncrement(tempThis);
                tempOther = pointerIncrement(other);
                if (tempThis == this->_end_) {
                    return true;
                }
            }
            return false;
        }
    };

    CircularBuffer() : data_(NULL), capacity_(0) {}

    explicit CircularBuffer(size_t capacity) {
        data_ = new _tp[capacity];
        capacity_ = capacity;
    }


    ~CircularBuffer() {
        delete[] data_;
    }

    _tp &operator[](size_t index) const {
        if (end_ == NULL) {
            throw std::runtime_error("Error: circular buffer is empty");
        }
        if (index >= capacity_) {
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

    _tp front() {
        return *start_;
    }

    _tp back() {
        return *end_;
    }

    void resize(size_t capacity) {
        if (capacity < capacity_) {
            throw std::runtime_error("Error: capacity be cannot be reduced in circular buffer");
        }
        if (start_ == NULL) {
            capacity_ = capacity;
            data_ = new _tp[capacity_];
            return;
        }
        if (start_ == end_) {
            capacity_ = capacity;
            _tp temp = *start_;
            data_ = new _tp[capacity_];
            *data_ = temp;
            return;
        }
        _tp *tempData = new _tp[capacity];
        size_t tempIndex = 0;
        for (_tp *i = start_; i != end_; i = pointerIncrement(i)) {
            std::cout << *i << "\n";
            tempData[tempIndex] = *i;
            ++tempIndex;
        }
        tempData[tempIndex] = *end_;
        start_ = tempData;
        end_ = tempData + tempIndex;
        capacity_ = capacity;
        delete[] data_;
        data_ = tempData;
    }

    Iterator begin() const{
        return Iterator(data_, capacity_, start_, end_);
    }

    Iterator end() const{
        return Iterator(data_, capacity_, end_, end_);
    }


    void print() {
        for (_tp *i = data_; i < data_ + capacity_; ++i) {
            std::cout << *i << " ";
        }
        std::cout << "\n" << "start: " << start_ - data_ << " end: " << end_ - data_ << "\n";
    }

    size_t capacity() const { return capacity_; }

};



