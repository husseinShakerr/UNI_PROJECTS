// Created by zhass on 2024-10-27.

#include "menu.h"

/**
 * @brief Adds button into a std::map container.
 * Also constructs the button once the button is added into the map.
 * @param pos Button position
 * @param texture Button Texture
 * @param buttontext Button text
 * @param font Button text font
 * @param bSize Button size
 */
void menu::addButton(sf::Vector2f pos, sf::Texture& texture, std::string buttontext, sf::Font& font, sf::Vector2f bSize) {
    buttons.emplace(buttontext, button(pos, texture, buttontext, font, bSize));
}

/**
 * @brief Draws background, header text and buttons objects on target.
 * @param target
 * @param states
 */
void menu::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(background);
    target.draw(headerText);
    for(const auto& b: buttons) {
        target.draw(b.second);
    }
}

/**
 * @brief Sets background texture for the menu object.
 * @param bg_texture sf::Texture that holds texture data.
 */
void menu::setBackground(const sf::Texture& bg_texture) {
    background.setTexture(bg_texture);
}

/**
 * @brief Sets header text
 * @param font sf::Font header text font
 * @param text std::string header text
 * @param characterSize Integer header text size
 * @param color sf::Color header text color
 * @param position 2 floats for header text position.
 */
void menu::setHeaderText(const sf::Font &font, const std::string &text, const int &characterSize, const sf::Color &color, const sf::Vector2u position) {
    headerText.setFont(font);
    headerText.setString(text);
    headerText.setCharacterSize(characterSize);
    headerText.setOrigin(headerText.getLocalBounds().width/2, headerText.getLocalBounds().height/2);
    headerText.setFillColor(color);
    headerText.setPosition(position.x, position.y);
}

/**
 * @brief Detects a mouse click if a button is clicked. Buttons is stored in std::map of key and button objects.
 * @param mousePos 2 intergers for mouse position
 * @return returns the string of the key, if no button pressed; returns empty string.
 */
std::string menu::detectClick(const sf::Vector2i& mousePos) const {
    for (const auto& [key, button] : buttons) {
        sf::FloatRect buttonBounds = button.getGlobalBounds();

        if (buttonBounds.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
            return key;
        }
    }
    return "";
}

