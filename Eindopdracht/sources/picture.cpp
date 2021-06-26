#include "../headers/picture.hpp"

picture::picture(sf::Vector2f position, sf::Vector2f size, std::string fileName, sf::Color color):
	position{position},
	size{size},
    fileName{fileName},
	color{color}
{
    if(!texture.loadFromFile(fileName)){
		spriteBox.setOutlineColor(sf::Color::Red);
		spriteBox.setOutlineThickness(8);
	}
    else{
		texture.setSmooth(true);
		spriteBox.setTexture(&texture);
		spriteBox.setOutlineThickness(1);
		spriteBox.setOutlineColor(color);
	}
	spriteBox.setFillColor(sf::Color::White);
	spriteBox.setPosition(position);
    spriteBox.setSize(size);
}

void picture::draw(sf::RenderWindow & window){
	window.draw(spriteBox);
}

std::string picture::getScreenObject(){
	std::string objectData;
	
	objectData.append("PICTURE (");
	objectData.append(std::to_string(int(position.x)));
	objectData.append(",");
	objectData.append(std::to_string(int(position.y)));
	objectData.append(") (");
	objectData.append(std::to_string(int(size.x)));
	objectData.append(",");
	objectData.append(std::to_string(int(size.y)));
	objectData.append(") ");
	objectData.append(fileName);
	objectData.append(" \n");

	return objectData;
}

sf::Vector2f picture::getPos(){
	return spriteBox.getPosition();
}

bool picture::collisionCheck(sf::Vector2i target){
    if((target.x >= position.x && target.y >= position.y) && (target.x <= (position.x + size.x) && target.y <= (position.y + size.y)))
		return 1;
	return 0;
}

void picture::jump(sf::Vector2f target){
	position = target;
    position.x -= size.x * 0.5;
    position.y -= size.y * 0.5;
	spriteBox.setPosition(position);
}

void picture::jump(sf::Vector2i target){
	jump( sf::Vector2f( 
		static_cast<float>(target.x), 
		static_cast<float>(target.y)
	));
}

sf::Color picture::getColor(){
	return color; 
}
    
void picture::setColor(sf::Color newColor){
	color = newColor;
	spriteBox.setOutlineColor(color);
}