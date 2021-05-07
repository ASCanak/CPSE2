#ifndef BALL_HPP
#define BALL_HPP

#include "../headers/drawable.hpp"

class ball : public drawable{
private:
	sf::CircleShape circle;
	sf::Vector2f position, speed;
	float size;

public:
	ball(sf::Vector2f position, sf::Vector2f speed, float size = 10.0);

	void draw(sf::RenderWindow & window) override;

	sf::Vector2f getPos() override;

	sf::FloatRect collisionModel() override;

	void collisionCheck(std::vector<drawable*> objects);

	void move();
};

#endif