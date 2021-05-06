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

    void screen_object_write(std::string textfileName) override;

	sf::Vector2f getPos() override;

    bool collisionCheck(sf::Vector2i target) override;

    void jump(sf::Vector2f target) override;
	void jump(sf::Vector2i target) override;

    sf::Color getColor() override;
    void setColor(sf::Color newColor) override;
};

#endif