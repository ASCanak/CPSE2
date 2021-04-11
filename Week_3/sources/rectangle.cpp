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

void rectangle::screen_object_write(){
	std::ofstream myFile;
	myFile.open("map.txt", std::ios_base::app);
		myFile << "RECTANGLE " << "(" << position.x << "," << position.y << ") " << " (" << size.x << "," << size.y << ") " << color << " " << std::endl;
	myFile.close();
}

sf::Vector2f rectangle::getPos(){
	return object.getPosition();
}

void rectangle::collisionCheck(sf::Vector2f target){
    if((target.x >= position.x && target.y >= position.y) && (target.x <= (position.x + size.x) && target.y <= (position.y + size.y)))
        jump(target); 
}
    
void rectangle::collisionCheck(sf::Vector2i target){
    collisionCheck( sf::Vector2f( 
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