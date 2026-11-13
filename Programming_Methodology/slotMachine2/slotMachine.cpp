// Created by zhass on 2024-10-29.

#include "slotMachine.h"

/**
 * Sizes for the machine.
 */
namespace machineSizes {
    constexpr float mSizeX{350.0};
    constexpr float mSizeY{150.0};
}

/**
 * @brief Constructs the machine. Loads up textures. Sets Machine positioning and slots.
 * @param mPos Machine position.
 * @param mSize Machine size.
 */
slotMachine::slotMachine(sf::Vector2f mPos, sf::Vector2f mSize) : slotMachine_(mSize), rd(std::random_device()), rng(rd()) {
    banana_texture.loadFromFile("banana.png");
    melon_texture.loadFromFile("melon.png");
    apple_texture.loadFromFile("apple.png");
    slotMachine_.setPosition(mPos);
    machineTexture.loadFromFile("slots.png");
    slotMachine_.setTexture(&machineTexture);
    for(auto &slot: slots) {
        setSlot(slot);
    }
}

/**
 * @brief Draws the machine and its slots on render target.
 * @param target Target to draw content on.
 * @param states
 */
void slotMachine::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(slotMachine_);
    for(auto& sl : slots) {
        target.draw(sl.slotRect);
    }
}

/**
 * @brief Randomizes the slots.
 * @param bet Takes betting amount.
 * @return Returns integer
 */
int slotMachine::spin(int bet) {
    std::uniform_int_distribution<> randomFruit(apple, banana);
    for (auto &spinner: slots) {
        spinner.fruit = static_cast<fruits>(randomFruit(rng));
        setSlot(spinner);
    }
    if (isWin()) {
        switch (slots[0].fruit) {
            case banana:
                return payOut(bet, payLine::banana);
            case apple:
                return payOut(bet, payLine::apple);
            case melon:
                return payOut(bet, payLine::melon);
        }
    }
    return 0;
}

/**
 * @brief Checks if the spin got a win.(3 of same fruit).
 * @return Returns true if the first, second and third value of fruit array is the same, else false.
 */
bool slotMachine::isWin() const {
    return (slots[0].fruit == slots[1].fruit && slots[1].fruit == slots[2].fruit);
}

/**
 * @brief Sets texture for the slot based on the number returned from slot.
 * @param slot
 */
void slotMachine::setSlot(slot& slot) {
    switch (slot.fruit) {
        case banana:
            slot.slotRect.setTexture(&banana_texture);
            return;
        case apple:
            slot.slotRect.setTexture(&apple_texture);
            return;
        case melon:
            slot.slotRect.setTexture(&melon_texture);
    }
}

/**
 * @brief Adds winning amount to credit.
 * @param bet int for betting amount.
 * @param multiplier Integer multiplied with.
 * @return Returns winning amount.
 */
int slotMachine::payOut(int bet, int multiplier) {
    return bet * multiplier;
}