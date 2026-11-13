//
// Created by zhass on 2024-10-02.
//

#include "square.h"


square::square(double side, std::string color) : shape(color), _side(side){

}

double square::get_area()  {
    return _side * _side;
}

