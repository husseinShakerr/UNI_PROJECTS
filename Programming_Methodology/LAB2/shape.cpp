//
// Created by zhass on 2024-10-02.
//

#include "shape.h"



shape::shape(std::string color) : color(color) {}

std::string shape::get_color() const {
    return this->color;
}



