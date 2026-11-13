//
// Created by zhass on 2024-09-09.
//

#include "int_sorted.h"

#include <thread>

#include "int_buffer.h"




int_sorted::int_sorted(const int *source, size_t size) : buff(source, size) {
    if (size > 1) {
        *this = sort(source, source + size);
    }
}

void int_sorted::insert(int value) {
    int_sorted temp(&value, 1);
    *this = merge(temp);
}

size_t int_sorted::size() const {
    return buff.size();
}

const int *int_sorted::begin() const {
    return buff.begin();
}

const int *int_sorted::end() const {
    return buff.end();
}

int_sorted int_sorted::merge(const int_sorted &merge_with) const {
    int_buffer new_array = int_buffer(this->buff.size() + merge_with.size());
    size_t ind = 0;
    const int *a = merge_with.begin();
    const int *b = this->begin();
    while (a != merge_with.end() && b != this->end()) {
        if (*a < *b) {
            new_array[ind++] = *a++;
        } else {
            new_array[ind++] = *b++;
        }
    }
    while (a != merge_with.end()) {
        new_array[ind++] = *a++;
    }
    while (b != this->end()) {
        new_array[ind++] = *b++;
    }
    int_sorted nArr(nullptr, 0);
    nArr.buff = new_array;
    return nArr;
}

int_sorted sort(const int *begin, const int *end) {
    if (begin == end) {
        return int_sorted{nullptr, 0};
    }
    if (begin == end - 1) {
        return int_sorted{begin, 1};
    }
    ptrdiff_t half = (end - begin) / 2;
    const int *mid = begin + half;
    return sort(begin, mid).merge(sort(mid, end));
}

void int_sorted::selection_sort() {
    size_t size = buff.size();
    for (size_t x = 0; x < size - 1; ++x) {
        size_t ind = x;
        for (size_t y = x + 1; y < size; ++y) {
            if (buff[y] < buff[ind]) {
                ind = y;
            }
        }
        std::swap(buff[x], buff[ind]);
    }
}

void int_sorted::printArr() {
    buff.printArr();
}
