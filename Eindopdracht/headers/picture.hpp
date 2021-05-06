#ifndef PICTURE_HPP
#define PICTURE_HPP

#include "../headers/drawable.hpp"

class picture : public drawable{
private:
    sf::RectangleShape spriteBox;
	sf::Vector2f position;
	sf::Vector2f size;

    std::string fileName;
    sf::Texture texture;
    sf::Color color;

public:
	picture(sf::Vector2f position, sf::Vector2f size, std::string fileName, sf::Color color = sf::Color::Transparent);
	
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