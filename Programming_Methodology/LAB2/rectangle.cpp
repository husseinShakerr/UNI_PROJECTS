//
// Created by zhass on 2024-10-02.
//

#include "rectangle.h"



rectangle::rectangle(double long_side, double short_side, std::string color) : shape(color), _sideA(long_side), _sideB(short_side) {

}

double rectangle::get_area() {
    return _sideA * _sideB;
}
