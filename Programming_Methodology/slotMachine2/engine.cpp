//
// Created by zhass on 2024-10-29.
//

#include "engine.h"
#include "menu.h"
#include "menuCreator.h"
#include "slotMachine.h"

/**
 * @brief Constructor for engine.
 * @param window Takes graphics parameter.
 */
engine::engine(graphics &window) : window(window) {
}

/**
 * @brief Runs the slot machine itself. Creates the inGameMenu and handles events and rendering inGame window.
 * @param resource menuResources struct object that holds background textures and font.
 */
void engine::run(menuResources &resource) {
    unsigned int credit = 50;
    menu ingameMenu;
    menuCreator::setUpInGameMenu(ingameMenu, resource);
    slotMachine machine({300, 300}, {500, 500});
    sf::Event mouseevent{};
    while (window.isOpen()) {
        if(window.pollEvent(mouseevent)) {
            if (mouseevent.type == sf::Event::MouseButtonReleased) {
                if (ingameMenu.detectClick(sf::Mouse::getPosition()) == "SPIN") {
                    if (credit >= 5) {
                        credit -= 5;
                        credit += machine.spin(5);
                    }
                }
                if(ingameMenu.detectClick(sf::Mouse::getPosition()) == "RETURN") {
                    return;
                }
            }
            window.closeCheck(mouseevent);
        }
        sf::Text t(sf::Text(std::to_string(credit), resource.font, 50));
        window.clear();
        window.draw(ingameMenu);
        window.draw(t);
        window.draw(machine);
        window.display();
    }
}
