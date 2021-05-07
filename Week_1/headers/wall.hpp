#ifndef WALL_HPP
#define WALL_HPP

#include "../headers/drawable.hpp"

class wall : public drawable{
private:
	sf::RectangleShape rectangle;
	sf::Vector2f position, size;

public:
	wall(sf::Vector2f position, sf::Vector2f size);
	
	void draw(sf::RenderWindow & window) override;

	sf::FloatRect collisionModel() override;

	sf::Vector2f getPos() override;
};

#endif