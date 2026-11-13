//
// Created by zhass on 2024-10-27.
//

#include "button.h"
const int BUTTON_TXT_SIZE{30};

/**
 * @brief Button Constructor. Sets buttons and text origin into the middle point of both.
 * Also sets position of button, button text and butto texture.
 * @param pos Position
 * @param texture Texture
 * @param text Text
 * @param font Font
 * @param bSize Size
 */
button::button(sf::Vector2f pos, sf::Texture& texture, std::string text, sf::Font& font, sf::Vector2f bSize) :  buttonText(text, font, BUTTON_TXT_SIZE), rectangle(bSize){
    rectangle.setOrigin(rectangle.getLocalBounds().width/2, rectangle.getLocalBounds().height/2);
    buttonText.setOrigin(buttonText.getLocalBounds().width/2, buttonText.getLocalBounds().height/2);
    rectangle.setPosition(pos);
    buttonText.setPosition(pos);
    rectangle.setTexture(&texture);

}

/**
 * brief Draws button content.
 * @param target Target to draw button on.
 * @param states 
 */
void button::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(rectangle);
    target.draw(buttonText);
}

/**
 * @brief Gets the global bounding rectangle of button.
 * @return Returns FloatRect of the global bounds of the button.
 */
sf::FloatRect button::getGlobalBounds() const {
    return rectangle.getGlobalBounds();
}
