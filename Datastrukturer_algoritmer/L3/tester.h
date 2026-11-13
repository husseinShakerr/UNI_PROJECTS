// Created by zhass on 5/23/2025.


#pragma once
#include <complex>
#include <cmath>
#include <numeric>
#include <random>
#include <vector>
#include "generator.h"
#include "reporter.h"
#include "timer.h"

template<typename T>
double calc_mean(const std::vector<T> &primes) {
    return static_cast<double>(std::accumulate(primes.begin(), primes.end(), 0.0) / primes.size());
}

template<typename T>
double calc_stdv(std::vector<T> &primes, double mean) {
    double sum = 0.0;
    for (double prime: primes) {
        sum += (prime - mean) * (prime - mean);
    }
    return std::sqrt(sum / (static_cast<double>(primes.size() - 1)));
}

template<typename searchFunc, typename Container>
void test_search(generator &g, searchFunc search_func, reporter &reporter, size_t N, Container container,
                 const std::vector<int> &search_values, int samples) {
    std::vector<long long> times;
    times.reserve(samples);
    timer t;
    for (auto &value: search_values) {
        t.reset();
        for (size_t i = 0; i < samples; i++) {
            search_func(container, value);
        }
        times.push_back(t.elapsed() / samples);
    }
    double m = calc_mean(times);
    double stdv = calc_stdv(times, m);
    reporter.logger(N, m, stdv, samples);
}
