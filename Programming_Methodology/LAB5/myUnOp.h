// Created by zhass on 2024-10-22.


#ifndef MYUNOP_H
#define MYUNOP_H
#include "car.h"


class myUnOp {
    public:
    double operator()(const car& c) {
        return c.getDouble();
    }
};



#endif //MYUNOP_H
