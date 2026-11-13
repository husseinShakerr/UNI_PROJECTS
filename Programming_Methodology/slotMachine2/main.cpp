#include <iostream>

#include "engine.h"
#include "graphics.h"
#include "menuCreator.h"


int main() {
    graphics w;
    menuResources resources;
    menu mainMenu;
    menuCreator::setupMainMenu(mainMenu, resources);
    menu inGameMenu;
    menuCreator::setUpInGameMenu(inGameMenu, resources);
    sf::Event event;
    while (w.isOpen()) {
        while (w.pollEvent(event)) {
            w.closeCheck(event);
        }
        w.clear();
        w.draw(mainMenu);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            if (mainMenu.detectClick(sf::Mouse::getPosition()) == "EXIT")
                return 0;
            if (mainMenu.detectClick(sf::Mouse::getPosition()) == "PLAY") {
                engine game(w);
                game.run(resources);
            }
        }
        w.display();
    }


    return 0;
}
