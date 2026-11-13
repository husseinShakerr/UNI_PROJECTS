// Created by zhass on 5/19/2025.

#ifndef SEARCH_H
#define SEARCH_H
#include "bst.h"
#include "hashTable.h"


class search {
public:
    static int sequential_search(std::vector<int>& list, int key);

    static int binary_search_recursive(std::vector<int>& list, int low, int high, int key);
};
bool sequential_search(std::vector<int> &list, int value);
bool binary_search_recursive(std::vector<int> &list, int value);
bool hash_search(const hashTable&, int value);
bool bst_search(const bst &tree, int value);
#endif //SEARCH_H
