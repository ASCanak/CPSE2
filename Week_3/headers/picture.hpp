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

public:
	picture(sf::Vector2f position, sf::Vector2f size, std::string fileName);
	
	void draw(sf::RenderWindow & window) override;

    void screen_object_write() override;

	sf::Vector2f getPos() override;

    void collisionCheck(sf::Vector2f target) override;
    void collisionCheck(sf::Vector2i target) override;

    void jump(sf::Vector2f target);
    void jump(sf::Vector2i target);
};

#endif