// Created by zhass on 5/14/2025.

#include "timer.h"

timer::timer() {
    start_time = std::chrono::high_resolution_clock::now();
}
void timer::reset() {
    start_time = std::chrono::high_resolution_clock::now();
}
long long timer::elapsed() const {
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
    return duration.count();
}