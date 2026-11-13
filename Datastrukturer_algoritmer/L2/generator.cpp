//
// Created by zhass on 5/3/2025.
//


#include "generator.h"
#include <iostream>
#include <random>

std::vector<int> generator::randomNumbers(size_t size) {
    std::vector<int> numbers;
    std::mt19937 mt(std::random_device{}());
    std::uniform_int_distribution<int> dist(0, 50);
    for (int i = 0; i < size; i++) {
        numbers.push_back(dist(mt));
    }
    return numbers;
}

std::vector<int> generator::ascending(size_t size) {
    std::vector<int> numbers;
    std::mt19937 mt(std::random_device{}());
    std::uniform_int_distribution<int> dist(1, 5);
    int current = 0;
    for (int i  = 1; i < size; i++) {
        current += dist(mt);
        numbers.push_back(current);
    }
    return numbers;
}
std::vector<int> generator::descending(size_t size) {
    std::vector<int> numbers;
    std::mt19937 mt(std::random_device{}());
    std::uniform_int_distribution<int> dist(1, 5);
    int current = static_cast<int>(size) * 5;
    //std::cout<<"current = "<<current<<std::endl;
    for (int i  = 1; i < size; i++) {
        numbers.push_back(current);
        current -= dist(mt);
    }
    return numbers;
}

std::vector<int> generator::constants(size_t size) {
    std::vector<int> numbers;
    for (int i = 0; i < size; i++) {
        numbers.push_back(1);
    }
    return numbers;
}