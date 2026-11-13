//
// Created by zhass on 5/23/2025.
//

#include "timer.h"

timer::timer() {
    start = std::chrono::high_resolution_clock::now();
}
void timer::reset() {
    start = std::chrono::high_resolution_clock::now();
}
long long timer::elapsed() const {
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start);
    return duration.count();
}