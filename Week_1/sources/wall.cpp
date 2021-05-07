#include "../headers/wall.hpp"

wall::wall(sf::Vector2f position, sf::Vector2f size):
	position{position},
	size{size}
{
	rectangle.setSize(size);
	rectangle.setFillColor(sf::Color::Red);
	rectangle.setPosition(position);
}

void wall::draw(sf::RenderWindow & window){
	window.draw(rectangle);
}

sf::FloatRect wall::collisionModel(){
	return rectangle.getGlobalBounds();
}

sf::Vector2f wall::getPos(){
	return rectangle.getPosition();
}