// Created by zhass on 2024-10-27.

#include "menuCreator.h"
#include "menu.h"

/**
 * @brief Sizes for buttons.
 */
namespace buttonSizes {
    constexpr float buttonSizeX{300};
    constexpr float buttonSizeY{205};
};

/**
 * @brief Loads textures and fonts for buttons and background.
 */
menuResources::menuResources() : buttonTexture(), bg_texture(), font() {
    bg_texture.loadFromFile("b7.jpg");
    buttonTexture.loadFromFile("button_texture.jpg");
    font.loadFromFile("ARIAL.ttf");
}

/**
 * Sets up main menu. Here gets header text, background and buttons created.
 * @param mainMenu
 * @param resources
 */
void menuCreator::setupMainMenu(menu &mainMenu, menuResources& resources) {
    //mainMenu.setBackground(resources.bg_texture);
    mainMenu.setHeaderText(resources.font, "WELCOME TO FRUITS", 50, sf::Color::White, {sf::VideoMode::getDesktopMode().width/2, 200});
    mainMenu.addButton({600, 400}, resources.buttonTexture, "PLAY", resources.font, {buttonSizes::buttonSizeX,buttonSizes::buttonSizeY});
    mainMenu.addButton({600, 700}, resources.buttonTexture, "EXIT", resources.font, {buttonSizes::buttonSizeX, buttonSizes::buttonSizeY});
    mainMenu.addButton({1200, 400}, resources.buttonTexture, "SETTINGS", resources.font, {buttonSizes::buttonSizeX, buttonSizes::buttonSizeY});
    mainMenu.addButton({1200, 700}, resources.buttonTexture, "PROFILE", resources.font, {buttonSizes::buttonSizeX, buttonSizes::buttonSizeY});
}

/**
 * @brief Sets up in-game menu.
 * @param inGameMenu
 * @param resources
 */
void menuCreator::setUpInGameMenu(menu& inGameMenu, menuResources& resources){
    //inGameMenu.setBackground(resources.bg_texture);
    inGameMenu.addButton({1200, 400}, resources.buttonTexture, "SPIN", resources.font, {buttonSizes::buttonSizeX, buttonSizes::buttonSizeY});
    inGameMenu.addButton({1200, 620}, resources.buttonTexture, "RETURN", resources.font, {buttonSizes::buttonSizeX, buttonSizes::buttonSizeY});

}

