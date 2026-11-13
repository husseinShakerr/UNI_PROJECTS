//
// Created by zhass on 2024-10-29.
//

#ifndef RUNMACHINE_H
#define RUNMACHINE_H
#include "graphics.h"
#include "menuCreator.h"

class engine {
    graphics& window;

    public:
    explicit engine(graphics& window);

    void run(menuResources &resource);
};



#endif //RUNMACHINE_H
