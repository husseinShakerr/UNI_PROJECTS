// Created by zhass on 5/14/2025.

#pragma once
#include <numeric>
#include <string>
#include <vector>
#include "report.h"
#include "timer.h"
#include <cmath>

inline double mean(const std::vector<double>& values) {
    return std::accumulate(values.begin(), values.end(), 0.0) / values.size();
}
inline double standard_deviation(const std::vector<double>& values, double mean) {
    double sum = 0.0;
    for(double val : values) {
        sum += (val - mean) * (val - mean);
    }
    return std::sqrt(sum * (1.0 / (values.size() - 1)));
}

template <typename sortFunc>
void test_sorting(const std::string& method_name, sortFunc sort_func, report& rep, size_t N, std::vector<int>& original_list, int samples, const std::string& dataType) {
    std::vector<double> times;
    for (int i = 0 ; i < samples ; i++) {
        std::vector<int> data = original_list;
        timer t;
        sort_func(data);
        double elapsed = t.elapsed();
        times.push_back(elapsed);
    }
    double m = mean(times);
    double stdv = standard_deviation(times, m);
    rep.log_result(N, m, stdv, samples, dataType);
}

