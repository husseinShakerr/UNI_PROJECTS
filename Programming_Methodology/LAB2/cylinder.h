//
// Created by zhass on 2024-10-02.
//

#ifndef CYLINDER_H
#define CYLINDER_H
#include "circle.h"


class cylinder : public circle{
    double height;
public:
    explicit cylinder(double radius, double height, std::string color);
    double get_area()  override;
};



#endif //CYLINDER_H
