// Created by zhass on 5/23/2025.

#include <iostream>
#include "hashTable.h"

hashTable::hashTable(std::vector<int> &in) : buckets(in.size()*2), size_(0), table(buckets) {
    for (auto &num : in) {
        insert(num);
    }
}


void hashTable::clear() {
    for (auto& bucket : table) {
        bucket.clear();
    }
    size_ = 0;
}
void hashTable::insert(int key) {
    size_t hashValue = hashFunction(key);
    table[hashValue].push_back(key);
    size_++;
}


int hashTable::hashFunction(int key) const{
    std::hash<int> hasher;
    return hasher(key)%buckets;
}

bool hashTable::contains(int key) const {
    size_t hashValue = hashFunction(key);
    size_t i = 0;
    while (!table[hashValue].empty()) {
        if (table[hashValue][i]==key)
            return true;
        i++;
    }
    return false;
}
/*
void hashTable::printTable() const {
    for (int i = 0; i < buckets; i++) {
        for (int j = 0; j < table[i].size(); j++) {
            std::cout <<"Element: " << i << " value: " << table[i][j] << std::endl;
        }
    }
}*/

size_t hashTable::maxDepth() const {
    size_t maxDepth = 0;
    for (int i = 0; i < buckets; i++) {
        if (table[i].size() > maxDepth)
            maxDepth = table[i].size();
    }
    return maxDepth;
}
