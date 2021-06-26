#include "../headers/circle.hpp"

circle::circle(sf::Vector2f position, float size, sf::Color color):
	position{position},
	size{size},
    color{color}
{
    object.setPosition(position);
    object.setRadius(size);
    object.setFillColor(color);
}

void circle::draw(sf::RenderWindow & window){
	object.setPosition(position);
	window.draw(object);
}

std::string circle::getScreenObject(){
	std::string objectData;
	
	objectData.append("CIRCLE (");
	objectData.append(std::to_string(position.x));
	objectData.append(",");
	objectData.append(std::to_string(position.y));
	objectData.append(") red ");
	objectData.append(std::to_string(size));
	objectData.append("\n");

	return objectData;
}

sf::Vector2f circle::getPos(){
	return object.getPosition();
}

void circle::jumpOnCollision(sf::Vector2f target){
    if((target.x >= position.x && target.y >= position.y) && (target.x <= (position.x + (size * 2)) && target.y <= (position.y + (size * 2))))
        jump(target); 
}
    
void circle::jumpOnCollision(sf::Vector2i target){
    jumpOnCollision( sf::Vector2f( 
		static_cast<float>(target.x), 
		static_cast<float>(target.y)
	));
}

void circle::jump(sf::Vector2f target){
	position = target;
    position.x -= size;
    position.y -= size;
}

void circle::jump(sf::Vector2i target){
	jump( sf::Vector2f( 
		static_cast<float>(target.x), 
		static_cast<float>(target.y)
	));
}