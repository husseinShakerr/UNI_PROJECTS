// Created by zhass on 2024-10-26.

#ifndef WINDOW_H
#define WINDOW_H
#include <SFML/Graphics.hpp>


class graphics {
    sf::RenderWindow window;

    public:
    graphics();

    void closeCheck(sf::Event &evnt);

    template<typename T>
    void draw(T& obj) {
        window.draw(obj);
    }

    bool isOpen() const;

    void clear();

    void display();

    bool pollEvent(sf::Event & event);

    void close();

};



#endif //WINDOW_H
