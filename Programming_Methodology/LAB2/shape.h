// Created by zhass on 2024-10-02.


#ifndef SHAPE_H
#define SHAPE_H

#define PI 3.14159265359
#define UNCOLORED ""
#include <string>


class shape {
    std::string color;
public:

    explicit shape(std::string color = UNCOLORED);
    virtual double get_area() = 0;
    std::string get_color() const;


};

#endif //SHAPE_H
