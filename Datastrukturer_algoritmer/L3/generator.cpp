// Created by zhass on 5/18/2025.

#include "generator.h"
#include <iostream>
#include <random>

std::vector<int> generator::sieveOfEratosthenes(size_t N) {
    std::vector<bool> list(N + 1, true);
    list[0] = list[1] = false;
    for (size_t i = 2; i * i <= N; i++) {
        if (list[i]) {
            for (size_t j = i * i; j <= N; j += i) {
                list[j] = false;
            }
        }
    }
    std::vector<int> primes;
    for (size_t i = 2; i <= N; i++) {
        if (list[i])
            primes.push_back(i);
    }
    return primes;
}
std::vector<int> generator::generate_search_values(const std::vector<int>& original_list, int samples) {
    std::vector<int> result;
    if (original_list.empty())
        return result;
    size_t N = original_list.size();
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<size_t> dist(0, N - 1);
    for (int i = 0; i < samples; i++) {
        size_t index = dist(rng);
        result.push_back(original_list[index]);
    }
    return result;
}

