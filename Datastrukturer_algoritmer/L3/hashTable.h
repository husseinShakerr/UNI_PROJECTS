// Created by zhass on 5/23/2025.

#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <vector>

class hashTable {
    size_t buckets;
    std::vector<std::vector<int>> table;
    size_t size_;

public:
    explicit hashTable(std::vector<int> &in);

    void insert(int key);

    size_t size() const { return size_; }

    void clear();

    int hashFunction(int key) const;

    bool contains(int key) const;

    //void printTable() const;

    size_t maxDepth() const;


};

#endif //HASHTABLE_H
