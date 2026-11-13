// Created by zhass on 2024-10-02.

#ifndef ROUNDED_RECTANGLE_H
#define ROUNDED_RECTANGLE_H
#include "rectangle.h"
#include "square.h"
#include "circle.h"


class rounded_rectangle : public rectangle {
protected:
    double radius;

public:
    explicit rounded_rectangle(double long_side, double short_side, double radius, std::string = UNCOLORED);
    double getQuarterCircle() const;
    double get_area() override;
};


#endif //ROUNDED_RECTANGLE_H
