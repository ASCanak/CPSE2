#include <SFML/Graphics.hpp>
#include "block.hpp"

block::block(sf::Vector2f position, float size):
	position{position},
	size{size}
{}

void block::draw(sf::RenderWindow & window){
	rectangle.setSize(sf::Vector2f(size, size));
	rectangle.setFillColor(sf::Color::Blue);
	rectangle.setPosition(position);
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
}

void block::jump(sf::Vector2f target){
	position = target;
}

void block::jump(sf::Vector2i target){
	jump( sf::Vector2f( 
		static_cast<float>(target.x), 
		static_cast<float>(target.y)
	));
}