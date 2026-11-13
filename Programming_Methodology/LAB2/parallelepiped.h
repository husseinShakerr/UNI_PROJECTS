//
// Created by zhass on 2024-10-02.
//

#ifndef PARALLELEPIPED_H
#define PARALLELEPIPED_H
#include "rectangle.h"


class parallelepiped : public rectangle {
protected:
    double height;

public:

    explicit parallelepiped(double long_side, double short_side, double height, std::string color);

    double get_area() override;
};


#endif //PARALLELEPIPED_H
