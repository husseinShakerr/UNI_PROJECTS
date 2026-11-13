// Created by zhass on 2024-10-15.


#ifndef CAR_H
#define CAR_H
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


class car {
    std::string name;
    double topSpeed;

public:
    car() = default;
    car(std::string cModel, double tSpeed) : name(std::move(cModel)), topSpeed(tSpeed) {};
    std::string getName() const {
        return name;
    }
    double getDouble() const {
        return topSpeed;
    }
    bool operator==(const std::string& other_name) const {
        return name == other_name;
    }
    bool operator==(const double& other_speed) const {
        return topSpeed == other_speed;
    }
    bool operator==(const car& other_element) const {
        return name == other_element.name && topSpeed == other_element.topSpeed;
    }

    friend std::ostream& operator<<(std::ostream& os, const car& car) {
        os << "Model: " << car.name << " Top Speed: " << car.topSpeed;
        return os;
    }
};

bool getAdjObjName(const car& car1, const car& car2);


#endif //CAR_H
