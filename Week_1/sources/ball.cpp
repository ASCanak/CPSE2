#include "../headers/ball.hpp"

ball::ball(sf::Vector2f position, sf::Vector2f speed, float size):
	position{position},
	speed{speed},
	size{size}
{
	circle.setRadius(size);
	circle.setPosition(position);
}

void ball::draw(sf::RenderWindow & window){
	window.draw(circle);
}

void ball::move(){
	position += speed;
	circle.setPosition(position);
}

sf::FloatRect ball::collisionModel(){
	return circle.getGlobalBounds();
}

sf::Vector2f ball::getPos(){
	return circle.getPosition();
}

void ball::collisionCheck(std::vector<drawable*> objects){
	for(auto &item : objects){
		if(collisionModel() != (item -> collisionModel())){
			circle.setPosition({position.x + speed.x, position.y});
			if(collisionModel().intersects(item -> collisionModel()))
				speed.x *= -1;
			
			circle.setPosition({position.x, position.y + speed.x});
			if(collisionModel().intersects(item -> collisionModel()))
				speed.y *= -1;

			circle.setPosition({position + speed});
			if(collisionModel().intersects(item -> collisionModel())){
				speed.x *= -1;
				speed.y *= -1;
			}
		}
		circle.setPosition(position);
	}	
}