#ifndef BLOCK_HPP
#define BLOCK_HPP

#include <SFML/Graphics.hpp>
#include "drawable.hpp"

class block : public drawable{
public:
	sf::RectangleShape rectangle;
	
	block(sf::Vector2f position, float size = 30.0);

	void draw(sf::RenderWindow & window) override;

	sf::FloatRect collisionModel() override;

	sf::Vector2f getPos() override;

	void move(sf::Vector2f delta);

	void jump(sf::Vector2f target);
	void jump(sf::Vector2i target);

private:
	sf::Vector2f position;
	float size;
};

#endif