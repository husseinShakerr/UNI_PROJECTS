//
// Created by zhass on 2024-10-02.
//



#include "cylinder.h"
#include "shape.h"


cylinder::cylinder(double radius, double height, std::string color) : circle(radius, color), height(height) {

}
double cylinder::get_area()  {
    return PI *radius*radius*height;
}
