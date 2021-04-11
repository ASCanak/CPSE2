#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <exception>

class drawable{
public:
    virtual void draw(sf::RenderWindow &window) = 0;
    virtual void screen_object_write() = 0;

    virtual sf::Vector2f getPos();
    
    virtual void collisionCheck(sf::Vector2f target);
    virtual void collisionCheck(sf::Vector2i target);
};

#endif