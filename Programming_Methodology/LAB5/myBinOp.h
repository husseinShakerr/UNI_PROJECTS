// Created by zhass on 2024-10-22.

#ifndef MYBINOP_H
#define MYBINOP_H
#include "car.h"


class myBinOp {
public:
    double operator()(double total, const car &car) const {
        return total + car.getDouble();
    }
};


#endif //MYBINOP_H
