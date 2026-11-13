// Created by zhass on 2024-10-22.

#ifndef MYFUNC_H
#define MYFUNC_H


class myFunc {
    double avgSpeed;
public:
    explicit myFunc(double avSp) : avgSpeed(avSp) {}
    double operator()(double carSpeed) const{
        return carSpeed-avgSpeed;
    }
};



#endif //MYFUNC_H
