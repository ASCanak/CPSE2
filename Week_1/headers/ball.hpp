#ifndef BALL_HPP
#define BALL_HPP

#include "../headers/drawable.hpp"
#include <iostream>

class ball : public drawable{
public:
	sf::CircleShape circle;

	ball(sf::Vector2f position, sf::Vector2f speed, float size = 10.0);

	void draw(sf::RenderWindow & window) override;

	sf::FloatRect collisionModel() override;

	sf::Vector2f getPos() override;

	void collisionCheck(std::vector<drawable*> objects);

	void move();

private:
	sf::Vector2f position, speed;
	float size;
};

#endif