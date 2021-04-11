#include "../headers/wall.hpp"

wall::wall(sf::Vector2f position, sf::Vector2f size):
	position{position},
	size{size}
{}

void wall::draw(sf::RenderWindow & window){
	rectangle.setSize(size);
	rectangle.setFillColor(sf::Color::Red);
	rectangle.setPosition(position);
	window.draw(rectangle);
}

sf::FloatRect wall::collisionModel(){
	return rectangle.getGlobalBounds();
}

sf::Vector2f wall::getPos(){
	return rectangle.getPosition();
}