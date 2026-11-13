//
// Created by zhass on 2024-10-02.
//

#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.h"


class rectangle : public shape{
protected:
    double _sideA, _sideB;

public:
    explicit rectangle(double long_side, double short_side, std::string color);
    double get_area() override;
};



#endif //RECTANGLE_H
