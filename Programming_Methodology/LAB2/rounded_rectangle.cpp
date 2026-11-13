// Created by zhass on 2024-10-02.


#include "rounded_rectangle.h"



rounded_rectangle::rounded_rectangle(double long_side, double short_side, double radius,std::string color) : rectangle(long_side, short_side,color),radius(radius){

}

double rounded_rectangle::get_area() {

    return (rectangle::get_area() - (4*getQuarterCircle())) + PI*radius*radius;
}
double rounded_rectangle::getQuarterCircle() const {
    return radius*radius;
}




