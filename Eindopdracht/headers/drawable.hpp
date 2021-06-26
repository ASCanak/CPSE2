#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <exception>

class drawable{
public:
    virtual void draw(sf::RenderWindow &window) = 0;
    virtual std::string getScreenObject() = 0;

    virtual sf::Vector2f getPos();
    
    virtual bool collisionCheck(sf::Vector2i target);

    virtual void jump(sf::Vector2f target);
	virtual void jump(sf::Vector2i target);

    virtual sf::Color getColor();
    virtual void setColor(sf::Color newColor);
};

#endif