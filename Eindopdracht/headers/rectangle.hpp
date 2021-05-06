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

    void screen_object_write(std::string textfileName) override;

	sf::Vector2f getPos() override;

    bool collisionCheck(sf::Vector2i target) override;

    void jump(sf::Vector2f target) override;
    void jump(sf::Vector2i target) override;

    sf::Color getColor() override;
    void setColor(sf::Color newColor) override;
};

#endif