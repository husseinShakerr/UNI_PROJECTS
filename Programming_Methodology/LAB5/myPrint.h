// Created by zhass on 2024-10-15.

#ifndef MYPRINT_H
#define MYPRINT_H
#include "car.h"
/*
template<typename T>
class myPrint {
public:
    void operator()(const T &content) const {
        std::cout<<content<<std::endl;
    }

};*/


class myPrint {
public:
    void operator()(const car &obj) const {
        std::cout << "Name: " << obj.getName() << " | Top speed: " << obj.getDouble() << "KM/H" << "\n";
    }
    void operator()(const double& d) const {
        std::cout << "Top speed: " << d << "\n";
    }
};
#endif //MYPRINT_H
