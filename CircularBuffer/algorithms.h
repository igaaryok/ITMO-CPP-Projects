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

    template<class iterator>
    bool is_sorted(iterator begin, iterator end) {
        if (begin == end) {
            return true;
        }
        iterator tempIt = begin;
        for (iterator i = begin; i != end; ++i) {
            if (*i < *tempIt) {
                return false;
            }
            ++tempIt;
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

    template<class iterator, class T>
    iterator find_backward(iterator first, iterator last, const T &val) {
        while (last != first) {
            if (*last == val) return last;
            --last;
        }
        return first;
    }

    template<class iterator, class predicate>
    bool is_polindrome(iterator begin, iterator end, predicate pred) {
        std::vector<bool> answer;
        while (begin != end) {
            answer.push_back(pred(*begin));
            ++begin;
        }
        for (std::size_t i = 0, j = answer.size() - 1; i < j; ++i, --j)
            if (answer[i] != answer[j])
                return false;
        return true;
    }
}

