#include <SFML/Graphics.hpp>
#include "ball.hpp"

ball::ball(sf::Vector2f position, sf::Vector2f speed, float size):
	position{position},
	speed{speed},
	size{size}
{}

void ball::draw(sf::RenderWindow & window){
	circle.setRadius(size);
	circle.setPosition(position);
	window.draw(circle);
}

void ball::move(){
	position += speed;
}

sf::FloatRect ball::collisionModel(){
	return circle.getGlobalBounds();
}

sf::Vector2f ball::getPos(){
	return circle.getPosition();
}

void ball::collisionCheck(std::vector<drawable*> objects){
	sf::FloatRect ballModel = collisionModel();
	for(auto &item : objects){
		if(ballModel != (item -> collisionModel())){
			if(ballModel.intersects(item -> collisionModel())){
				if(ballModel.intersects(item -> collisionModel()) == ballModel.intersects(objects[2] -> collisionModel()) || ballModel.intersects(item -> collisionModel()) == ballModel.intersects(objects[3] -> collisionModel()))
					speed.x *= -1;
				else if(ballModel.intersects(item -> collisionModel()) == ballModel.intersects(objects[1] -> collisionModel()) || ballModel.intersects(item -> collisionModel()) == ballModel.intersects(objects[4] -> collisionModel()))
					speed.y *= -1;
				else if(ballModel.intersects(item -> collisionModel()) == ballModel.intersects(objects[5] -> collisionModel())){
					if(position.x < (objects[5] -> getPos().x) || position.x < (objects[5] -> getPos().x))
						speed.x *= -1;
					else
						speed.y *= -1;					
				}
			}
		}
	}		
}