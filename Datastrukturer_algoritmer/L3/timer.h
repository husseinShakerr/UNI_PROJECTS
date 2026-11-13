//
// Created by zhass on 5/23/2025.
//

#ifndef TIMER_H
#define TIMER_H
#include <chrono>


class timer {
    std::chrono::high_resolution_clock::time_point start;
public:
    timer();
    void reset();
    long long elapsed() const;
};



#endif //TIMER_H
