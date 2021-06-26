#include "../headers/icon.hpp"

icon::icon(sf::Vector2f position, sf::Vector2f size, std::string fileName, sf::Color color):
	position{position},
	size{size},
    fileName{fileName}
{
    if(!texture.loadFromFile(fileName)){
		spriteBox.setOutlineColor(sf::Color::Red);
		spriteBox.setOutlineThickness(8);
	}
    else{
		spriteBox.setOutlineColor(color);
		spriteBox.setOutlineThickness(3);
		texture.setSmooth(true);
		spriteBox.setTexture(&texture);
	}
	spriteBox.setFillColor(sf::Color::White);
	spriteBox.setPosition(position);
    spriteBox.setSize(size);
}

void icon::draw(sf::RenderWindow & window){
	window.draw(spriteBox);
}

bool icon::collisionCheck(sf::Vector2i target){
    if((target.x >= position.x && target.y >= position.y) && (target.x <= (position.x + size.x) && target.y <= (position.y + size.y)))
		return 1;
	return 0;
}

void icon::setTexture(std::string fileName){
	if(!texture.loadFromFile(fileName)){
		spriteBox.setOutlineColor(sf::Color::Red);
		spriteBox.setOutlineThickness(8);
	}
    else{
		texture.setSmooth(true);
		spriteBox.setTexture(&texture);
	}
}

void icon::setColor(sf::Color newColor){
	spriteBox.setOutlineColor(newColor);
}