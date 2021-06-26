#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "../headers/drawable.hpp"

class rectangle : public drawable{
private:
	sf::RectangleShape object;
    
    sf::Vector2f position;
	sf::Vector2f size;
    sf::Color color;

public:
	rectangle(sf::Vector2f position, sf::Vector2f size, sf::Color color = sf::Color::Red);
	
	void draw(sf::RenderWindow & window) override;

    std::string getScreenObject() override;

	sf::Vector2f getPos() override;

    void jumpOnCollision(sf::Vector2f target) override;
    void jumpOnCollision(sf::Vector2i target) override;

    void jump(sf::Vector2f target);
    void jump(sf::Vector2i target);
};

#endif