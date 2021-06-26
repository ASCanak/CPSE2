#ifndef ICON_HPP
#define ICON_HPP

#include <SFML/Graphics.hpp>

class icon{
private:
    sf::RectangleShape spriteBox;
	sf::Vector2f position;
	sf::Vector2f size;

    std::string fileName;
    sf::Texture texture;
    sf::Color color;

public:
	icon(sf::Vector2f position, sf::Vector2f size, std::string fileName, sf::Color color = sf::Color::Transparent);
	
	void draw(sf::RenderWindow & window);

    bool collisionCheck(sf::Vector2i target);

    void setTexture(std::string fileName);
    void setColor(sf::Color newColor);
};

#endif