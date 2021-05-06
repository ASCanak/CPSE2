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

void rectangle::screen_object_write(std::string textfileName){
	std::ofstream myFile;
	std::string strColor;
	
	if(color == sf::Color::Black)strColor = "black";
	else if(color == sf::Color::Red)strColor = "red";
	else if(color == sf::Color::Green)strColor = "green";
	else if(color == sf::Color::Blue)strColor = "blue";
	else if(color == sf::Color::Yellow)strColor = "yellow";
	else if(color == sf::Color::Magenta)strColor = "magenta";
	else if(color == sf::Color(44,47,51))strColor = "dark_grey";
	else if(color == sf::Color(35,39,42))strColor = "darker_grey";

	myFile.open(textfileName, std::ios_base::app);
		myFile << "RECTANGLE " << "(" << position.x << "," << position.y << ") " << " (" << size.x << "," << size.y << ") " << strColor << std::endl;
	myFile.close();
}

sf::Vector2f rectangle::getPos(){
	return object.getPosition();
}

bool rectangle::collisionCheck(sf::Vector2i target){
    if((target.x >= position.x && target.y >= position.y) && (target.x <= (position.x + size.x) && target.y <= (position.y + size.y)))
		return 1;
	return 0;
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

sf::Color rectangle::getColor(){
	return color; 
}
    
void rectangle::setColor(sf::Color newColor){
	color = newColor;
	object.setFillColor(color);
}