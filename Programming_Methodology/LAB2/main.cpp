#include <iostream>
#include <memory>
#include <vector>

#include "cylinder.h"
#include "parallelepiped.h"
#include "rounded_rectangle.h"
#include "shape.h"
#include "square.h"


void get_data(std::vector<shape*> shapes) {
    double totalArea = 0;
    for (const auto& shape : shapes) {
        std::cout<<"Color: "<< shape->get_color()<<std::endl;
        std::cout<<"Area: " << shape->get_area()<<std::endl;
        std::cout<<"----------\n";
        totalArea += shape->get_area();
    }
    std::cout<<"Total area is: "<<totalArea<<std::endl;
}

int main()
{

    std::vector<shape*> shapes;
    shapes.emplace_back(new circle(6.80, "Red"));
    shapes.emplace_back(new cylinder(4.2, 8.4,"Blue"));
    shapes.emplace_back(new rectangle(18.32, 9.4,"Orange"));
    shapes.emplace_back(new parallelepiped(6.80, 5.82, 7,"Gul"));
    shapes.emplace_back(new rounded_rectangle(6.80,2.74, 3.5 ,"Green"));
    shapes.emplace_back(new square(6.80, "Lila"));

    get_data(shapes);



    return 0;
}
