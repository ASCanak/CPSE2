#include "../headers/picture.hpp"

picture::picture(sf::Vector2f position, sf::Vector2f size, std::string fileName):
	position{position},
	size{size},
    fileName{fileName}
{
    if(!texture.loadFromFile(fileName))
        std::cout << "couldn't find image" << fileName << "\n";
    spriteBox.setPosition(position);
    spriteBox.setSize(size);
    spriteBox.setTexture(&texture);
}

void picture::draw(sf::RenderWindow & window){
	spriteBox.setPosition(position);
	window.draw(spriteBox);
}

void picture::screen_object_write(){
	std::ofstream myFile;
	myFile.open("map.txt", std::ios_base::app);
		myFile << "PICTURE " << "(" << position.x << "," << position.y << ") " << " (" << size.x << "," << size.y << ") " << fileName << " " << std::endl;
	myFile.close();
}

sf::Vector2f picture::getPos(){
	return spriteBox.getPosition();
}

void picture::collisionCheck(sf::Vector2f target){
    if((target.x >= position.x && target.y >= position.y) && (target.x <= (position.x + size.x) && target.y <= (position.y + size.y)))
        jump(target); 
}
    
void picture::collisionCheck(sf::Vector2i target){
    collisionCheck( sf::Vector2f( 
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