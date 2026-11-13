//
// Created by zhass on 2024-10-27.
//

#ifndef MENU_H
#define MENU_H

#include "button.h"

class menu: public sf::Drawable{
    std::map<std::string, button> buttons;
    sf::Sprite background;
    sf::Text headerText;


    public:
    void addButton(sf::Vector2f pos, sf::Texture& texture, std::string buttontext, sf::Font& font, sf::Vector2f bSize);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    void setBackground(const sf::Texture &texture);
    void setHeaderText(const sf::Font &font, const std::string &text, const int &characterSize, const sf::Color &color, sf::Vector2u position);

    std::string detectClick(const sf::Vector2i &mousePos) const;
};



#endif //MENU_H
