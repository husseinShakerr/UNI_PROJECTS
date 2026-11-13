//
// Created by zhass on 2024-10-02.
//


#include "circle.h"



circle::circle(double radius, std::string color) : shape(color), radius(radius) {

}

double circle::get_area() {
    return PI * radius * radius;
}


