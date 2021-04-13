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

void circle::screen_object_write(){
	std::ofstream myFile;
	myFile.open("map.txt", std::ios_base::app);
		myFile << "CIRCLE " << "(" << position.x << "," << position.y << ") red " << size << std::endl;
	myFile.close();
}

sf::Vector2f circle::getPos(){
	return object.getPosition();
}

void circle::collisionCheck(sf::Vector2f target){
    if((target.x >= position.x && target.y >= position.y) && (target.x <= (position.x + (size * 2)) && target.y <= (position.y + (size * 2))))
        jump(target); 
}
    
void circle::collisionCheck(sf::Vector2i target){
    collisionCheck( sf::Vector2f( 
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