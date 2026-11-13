// Created by zhass on 5/19/2025.

#include "search.h"
#include "bst.h"


int search::sequential_search(std::vector<int> &list, int key) {
    for (int i = 0; i < list.size(); i++) {
        if (list[i] == key) {
            return i;
        }
    }
    return -1;
}

int search::binary_search_recursive(std::vector<int> &list, int low, int high, int key) {
    if (high >= low) {
        int mid = low + (high - low) / 2;
        if (list[mid] == key)
            return mid;
        if (list[mid] > key)
            return binary_search_recursive(list, low, mid - 1, key);
        return binary_search_recursive(list, mid + 1, high, key);
    }
    return -1;
}
bool sequential_search(std::vector<int> &list, int value) {
    return search::sequential_search(list, value) != -1;
}
bool binary_search_recursive(std::vector<int> &list, int value) {
    return search::binary_search_recursive(list, 0, static_cast<int>(list.size()) - 1, value) != -1;
}
bool hash_search(const hashTable &ht, int value) {
    return ht.contains(value);
}
bool bst_search(const bst &tree, int value) {
    return tree.searchKey(value);
}

