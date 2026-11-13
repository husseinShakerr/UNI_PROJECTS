// Created by zhass on 2024-10-27.


#ifndef MENUCREATORS_H
#define MENUCREATORS_H

#include "menu.h"

struct menuResources {
    sf::Texture buttonTexture;
    sf::Texture bg_texture;
    sf::Font font;
    menuResources();
};

class menuCreator {
public:
    static void setupMainMenu(menu &mainMenu, menuResources& resources);
    static void setUpInGameMenu(menu &inGameMenu, menuResources& resources);
};


#endif //MENUCREATORS_H
