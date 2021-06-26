#include "../headers/line.hpp"

line::line(sf::Vector2f position, sf::Vector2f size, sf::Color color):
	position{position},
	size{size},
    color{color}
{
    object.setPosition(position);
    object.setSize(size);
    object.setFillColor(color);
}

void line::draw(sf::RenderWindow & window){
	object.setPosition(position);
	window.draw(object);
}

std::string line::getScreenObject(){
	std::string objectData;
	
	objectData.append("LINE (");
	objectData.append(std::to_string(position.x));
	objectData.append(",");
	objectData.append(std::to_string(position.y));
	objectData.append(") (");
	objectData.append(std::to_string(size.x));
	objectData.append(",");
	objectData.append(std::to_string(size.y));
	objectData.append(") yellow\n");

	return objectData;
}

sf::Vector2f line::getPos(){
	return object.getPosition();
}

void line::jumpOnCollision(sf::Vector2f target){
    if((target.x >= position.x && target.y >= position.y) && (target.x <= (position.x + size.x) && target.y <= (position.y + size.y)))
        jump(target); 
}
    
void line::jumpOnCollision(sf::Vector2i target){
    jumpOnCollision( sf::Vector2f( 
		static_cast<float>(target.x), 
		static_cast<float>(target.y)
	));
}

void line::jump(sf::Vector2f target){
	position = target;
    position.x -= size.x * 0.5;
    position.y -= size.y * 0.5;
}

void line::jump(sf::Vector2i target){
	jump( sf::Vector2f( 
		static_cast<float>(target.x), 
		static_cast<float>(target.y)
	));
}