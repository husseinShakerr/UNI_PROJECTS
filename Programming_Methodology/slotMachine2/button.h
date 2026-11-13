// Created by zhass on 2024-10-27.

#ifndef BUTTON_H
#define BUTTON_H
#include <SFML/Graphics.hpp>

class button: public sf::Drawable{
    sf::RectangleShape rectangle;
    sf::Text buttonText;
    public:
    button(sf::Vector2f pos, sf::Texture& texture, std::string text, sf::Font& font, sf::Vector2f buttonSize);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    sf::FloatRect getGlobalBounds() const;
};



#endif //BUTTON_H
