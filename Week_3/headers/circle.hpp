#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "../headers/drawable.hpp"

class circle : public drawable{
private:
	sf::CircleShape object;
    
    sf::Vector2f position;
    float size;
    sf::Color color;

public:
	circle(sf::Vector2f position, float size = 10.0, sf::Color color = sf::Color::White);

	void draw(sf::RenderWindow & window) override;

    void screen_object_write() override;

	sf::Vector2f getPos() override;

    void collisionCheck(sf::Vector2f target) override;
    void collisionCheck(sf::Vector2i target) override;

    void jump(sf::Vector2f target);
	void jump(sf::Vector2i target);
};

#endif