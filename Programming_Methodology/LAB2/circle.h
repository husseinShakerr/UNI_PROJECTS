//
// Created by zhass on 2024-10-02.
//

#ifndef CIRCLE_H
#define CIRCLE_H
#include "shape.h"



class circle : public shape{
protected:
    double radius;
public:
    explicit circle(double radius, std::string color);
    double get_area() override;
};



#endif //CIRCLE_H
