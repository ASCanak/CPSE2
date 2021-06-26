#include "../headers/picture.hpp"

picture::picture(sf::Vector2f position, sf::Vector2f size, std::string fileName):
	position{position},
	size{size},
    fileName{fileName}
{
    if(!texture.loadFromFile(fileName)){
        spriteBox.setFillColor(sf::Color::White);
		spriteBox.setOutlineColor(sf::Color::Red);
		spriteBox.setOutlineThickness(8);
	}
    else
		spriteBox.setTexture(&texture);
	
	spriteBox.setPosition(position);
    spriteBox.setSize(size);
}

void picture::draw(sf::RenderWindow & window){
	spriteBox.setPosition(position);
	window.draw(spriteBox);
}

std::string picture::getScreenObject(){
	std::string objectData;
	
	objectData.append("PICTURE (");
	objectData.append(std::to_string(position.x));
	objectData.append(",");
	objectData.append(std::to_string(position.y));
	objectData.append(") (");
	objectData.append(std::to_string(size.x));
	objectData.append(",");
	objectData.append(std::to_string(size.y));
	objectData.append(") ");
	objectData.append(fileName);
	objectData.append(" \n");

	return objectData;
}

sf::Vector2f picture::getPos(){
	return spriteBox.getPosition();
}

void picture::jumpOnCollision(sf::Vector2f target){
    if((target.x >= position.x && target.y >= position.y) && (target.x <= (position.x + size.x) && target.y <= (position.y + size.y)))
        jump(target); 
}
    
void picture::jumpOnCollision(sf::Vector2i target){
    jumpOnCollision( sf::Vector2f( 
		static_cast<float>(target.x), 
		static_cast<float>(target.y)
	));
}

void picture::jump(sf::Vector2f target){
	position = target;
    position.x -= size.x * 0.5;
    position.y -= size.y * 0.5;
}

void picture::jump(sf::Vector2i target){
	jump( sf::Vector2f( 
		static_cast<float>(target.x), 
		static_cast<float>(target.y)
	));
}