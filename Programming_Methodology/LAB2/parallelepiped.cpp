//
// Created by zhass on 2024-10-02.
//

#include "parallelepiped.h"



parallelepiped::parallelepiped(double long_side, double short_side, double height, std::string color) : rectangle(long_side, short_side, color), height(height){

}



//Rectangular Parallelepiped = √ l2 + b2 + h2
double parallelepiped::get_area()  {
    return 2*(_sideA * _sideB + _sideA * height + _sideB*height);
}
