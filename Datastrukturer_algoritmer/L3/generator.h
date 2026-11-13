// Created by zhass on 5/18/2025.

#ifndef GENERATOR_H
#define GENERATOR_H
#include <vector>


class generator {
public:
    static std::vector<int> sieveOfEratosthenes(size_t);
    static std::vector<int> generate_search_values(const std::vector<int>& original_list, int samples);
};


#endif //GENERATOR_H
