// Created by zhass on 2024-10-16.


#ifndef GETGREATERSPEED_H
#define GETGREATERSPEED_H
#include "car.h"

class getGreaterSpeed {
    double comparing_speed;
public:
    explicit getGreaterSpeed(const double& comparing_speed) : comparing_speed(comparing_speed) {};
    bool operator() (const car& c) const {
        return c.getDouble() > comparing_speed;
    }
};


#endif //GETGREATERSPEED_H
