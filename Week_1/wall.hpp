#ifndef WALL_HPP
#define WALL_HPP

#include <SFML/Graphics.hpp>
#include "drawable.hpp"

class wall : public drawable{
public:
	sf::RectangleShape rectangle;

	wall(sf::Vector2f position, sf::Vector2f size);
	
	void draw(sf::RenderWindow & window) override;

	sf::FloatRect collisionModel() override;

	sf::Vector2f getPos() override;

private:
	sf::Vector2f position;
	sf::Vector2f size;
};

#endif