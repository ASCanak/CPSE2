#include "../headers/picture.hpp"

picture::picture(sf::Vector2f position, sf::Vector2f size, std::string fileName, sf::Color color):
	position{position},
	size{size},
    fileName{fileName},
	color{color}
{
    if(!texture.loadFromFile(fileName))
        std::cout << "couldn't find image" << fileName << "\n";
    texture.setSmooth(true);
	spriteBox.setOutlineColor(color);
	spriteBox.setOutlineThickness(1);
	spriteBox.setFillColor(sf::Color::White);
	spriteBox.setPosition(position);
    spriteBox.setSize(size);
    spriteBox.setTexture(&texture);
}

void picture::draw(sf::RenderWindow & window){
	spriteBox.setPosition(position);
	window.draw(spriteBox);
}

void picture::screen_object_write(std::string textfileName){
	std::ofstream myFile;

	myFile.open(textfileName, std::ios_base::app);
		myFile << "PICTURE " << "(" << position.x << "," << position.y << ") " << " (" << size.x << "," << size.y << ") " << fileName << " " << std::endl;
	myFile.close();
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