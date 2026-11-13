//
// Created by zhass on 2024-10-29.
//

#ifndef SLOTMACHINE_H
#define SLOTMACHINE_H
#include <array>
#include <random>
#include <SFML/Graphics.hpp>


namespace payLine {
    const int apple{5};
    const int melon{30};
    const int banana{2};
}

class slotMachine : public sf::Drawable {
    std::random_device rd;
    std::mt19937 rng;
    sf::RectangleShape slotMachine_;
    sf::Texture machineTexture;
    sf::Texture banana_texture;
    sf::Texture melon_texture;
    sf::Texture apple_texture;
    enum fruits {
        apple, melon, banana
    };
    struct slot {
        explicit slot(float posX, float posY):slotRect({100,100}), fruit(apple) {
            slotRect.setPosition(posX, posY);
        }
        sf::RectangleShape slotRect;
        fruits fruit;
    };
    std::array<slot, 3> slots{slot(350,460), slot(500,460), slot(650,460)};
public:
    slotMachine(sf::Vector2f mPos, sf::Vector2f mSize);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    int spin(int bet);
    bool isWin() const;
    void setSlot(slot&);
    int payOut(int bet, int multiplier);

};


#endif //SLOTMACHINE_H
