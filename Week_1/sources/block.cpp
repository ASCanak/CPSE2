#include "../headers/block.hpp"

block::block(sf::Vector2f position, float size):
	position{position},
	size{size}
{
	rectangle.setSize(sf::Vector2f(size, size));
	rectangle.setFillColor(sf::Color::Blue);
	rectangle.setPosition(position);
}

void block::draw(sf::RenderWindow & window){
	window.draw(rectangle);
}

sf::FloatRect block::collisionModel(){
	return rectangle.getGlobalBounds();
}

sf::Vector2f block::getPos(){
	return rectangle.getPosition();
}

void block::move(sf::Vector2f delta){
	position += delta;
	rectangle.setPosition(position);
}

void block::jump(sf::Vector2f target){
	position = target;
	rectangle.setPosition(position);
}

void block::jump(sf::Vector2i target){
	jump( sf::Vector2f( 
		static_cast<float>(target.x), 
		static_cast<float>(target.y)
	));
}