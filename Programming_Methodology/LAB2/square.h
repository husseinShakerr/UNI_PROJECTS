//
// Created by zhass on 2024-10-02.
//

#ifndef SQUARE_H
#define SQUARE_H
#include "shape.h"


class square : public shape {
protected:
    double _side;

public:

    explicit square(double side, std::string color);

    double get_area() override;

};


#endif //SQUARE_H
