//
// Created by zhass on 2024-09-09.
//

#ifndef INT_SORTED_H
#define INT_SORTED_H
#include "int_buffer.h"


class int_sorted {

    int_buffer buff;

public:
    int_sorted(const int *source, size_t size);

    size_t size() const;

    void insert(int value);

    const int *begin() const;

    const int *end() const;

    void selection_sort();

    int_sorted merge(const int_sorted &merge_with) const;

    void printArr();
};


int_sorted sort(const int *begin, const int *end);

int_sorted sort(const int *begin, const int *end);
#endif //INT_SORTED_H
