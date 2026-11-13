// Created by zhass on 2024-10-26.

#include "graphics.h"
#include "menuCreator.h"

/**
 * @brief Graphics constructor.
 */
graphics::graphics() : window(sf::VideoMode::getDesktopMode(), "Fruits") {
    window.setFramerateLimit(60);
}

/**
 * @brief closes window
 * @param evnt waits for ent
 */
void graphics::closeCheck(sf::Event &evnt) {
    if (evnt.type == sf::Event::Closed) {
        window.close();
    }
}

/**
 * @brief opens window
 * @return true if window is open, false otherwise
 */
bool graphics::isOpen() const {
    return window.isOpen();
}

/**
 * @brief Clears window
 */
void graphics::clear() {
    window.clear();
}

/**
 * @brief Renders what have been drawn
 */
void graphics::display() {
    window.display();
}

/**
 * @brief Polls events.
 * @param event SFML Event object that gets filled with event data.
 * @return true if an event was polled from event que, otherwise false.
 */
bool graphics::pollEvent(sf::Event &event) {
    return window.pollEvent(event);
}

/**
 * @brief Closes window.
 */
void graphics::close() {
    window.close();
}

