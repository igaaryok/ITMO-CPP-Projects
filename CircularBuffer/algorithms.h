//
// Created by Igor on 23.04.2022.
//

#pragma once

#include <vector>

namespace algo {
    template<class iterator, class predicate>
    bool all_of(iterator begin, iterator end, predicate pred) {
        while (begin != end) {
            if (!pred(*begin)) {
                return false;
            }
            ++begin;
        }
        return true;
    }

    template<class iterator, class predicate>
    bool none_of(iterator begin, iterator end, predicate pred) {
        while (begin != end) {
            if (pred(*begin)) {
                return false;
            }
            ++begin;
        }
        return true;
    }

    template<class iterator, class predicate>
    bool any_of(iterator begin, iterator end, predicate pred) {
        while (begin != end) {
            if (pred(*begin)) return true;
            ++begin;
        }
        return false;
    }

    template<class iterator, class predicate>
    bool one_of(iterator begin, iterator end, predicate pred) {
        int is_true = 0;
        while (begin != end) {
            if (pred(*begin)) {
                is_true++;
            }
            ++begin;
        }
        if (is_true == 1)
            return true;
        else
            return false;
    }

    template <class ForwardIt, class Compare>
    bool is_sorted(ForwardIt first, ForwardIt last, Compare comp)
    {
        if (first != last) {
            ForwardIt next = first;
            while (++next != last) {
                if (comp(*next, *first))
                    return false;
                first = next;
            }
        }
        return true;
    }

    template <class ForwardIt>
    bool is_sorted(ForwardIt first, ForwardIt last)
    {
        if (first != last) {
            ForwardIt next = first;
            while (++next != last) {
                if (*next < *first)
                    return false;
                first = next;
            }
        }
        return true;
    }

    template<class iterator, class predicate>
    bool is_partitioned(iterator begin, iterator end, predicate pred) {
        while (begin != end and pred(*begin)) {
            ++begin;
        }
        while (begin != end) {
            if (pred(*begin)) {
                return false;
            }
            ++begin;
        }
        return true;
    }

    template<class _tp, class T>
    _tp find_not(_tp first, _tp last, const T &val) {
        while (first != last) {
            if (*first != val){
                return first;
            }
            ++first;
        }
        return last;
    }

//    template<class iterator, class T>
//    iterator find_backward(iterator first, iterator last, const T &val) {
//        while (last != first) {
//            if (*last == val) return last;
//            --last;
//        }
//        return first;
//    }

    template<class iterator, class T>
    constexpr iterator find_backward(iterator first, iterator last, const T& value)
    {
        for (; (first-1) != last; --last) {
            if (*last == value) {
                return last;
            }
        }
        return last;
    }


    template<class RandomAccessIterator, class predicate>
    bool is_polindrome(RandomAccessIterator begin, RandomAccessIterator end, predicate comp) {
        int i = 0;
        while ((begin + i) != end) {
            if (!comp(*(begin+i), *(end-i))){
                return false;
            }
            ++begin;
        }
        return true;
    }

    template<class RandomAccessIterator>
    bool is_polindrome(RandomAccessIterator begin, RandomAccessIterator end) {
        int i = 0;
        while ((begin + i) != end) {
            if (*(begin + i) != *(end - i - 1)){
                return false;
            }
            ++i;
        }
        return true;
    }
}

