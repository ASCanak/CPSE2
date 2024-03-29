#include "../headers/rectangle.hpp"

rectangle::rectangle(sf::Vector2f position, sf::Vector2f size, sf::Color color):
	position{position},
	size{size},
    color{color}
{
    object.setPosition(position);
    object.setSize(size);
    object.setFillColor(color);
}

void rectangle::draw(sf::RenderWindow & window){
	object.setPosition(position);
	window.draw(object);
}

std::string rectangle::getScreenObject(){
	std::string objectData;
	
	objectData.append("RECTANGLE (");
	objectData.append(std::to_string(position.x));
	objectData.append(",");
	objectData.append(std::to_string(position.y));
	objectData.append(") (");
	objectData.append(std::to_string(size.x));
	objectData.append(",");
	objectData.append(std::to_string(size.y));
	objectData.append(") blue\n");

	return objectData;
}

sf::Vector2f rectangle::getPos(){
	return object.getPosition();
}

void rectangle::jumpOnCollision(sf::Vector2f target){
    if((target.x >= position.x && target.y >= position.y) && (target.x <= (position.x + size.x) && target.y <= (position.y + size.y)))
        jump(target); 
}
    
void rectangle::jumpOnCollision(sf::Vector2i target){
    jumpOnCollision( sf::Vector2f( 
		static_cast<float>(target.x), 
		static_cast<float>(target.y)
	));
}

void rectangle::jump(sf::Vector2f target){
	position = target;
    position.x -= size.x * 0.5;
    position.y -= size.y * 0.5;
}

void rectangle::jump(sf::Vector2i target){
	jump( sf::Vector2f( 
		static_cast<float>(target.x), 
		static_cast<float>(target.y)
	));
}