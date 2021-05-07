#include "../headers/drawable.hpp"
#include "../headers/ball.hpp"
#include "../headers/wall.hpp"
#include "../headers/block.hpp"
#include "../headers/action.hpp"

int main(int argc, char *argv[]){
	sf::RenderWindow window{ sf::VideoMode{ 640, 480 }, "SFML window" };

	ball  my_ball  {sf::Vector2f{ 320.0, 240.0 }, sf::Vector2f{ 2.0, 2.0 }};
	wall  top	   {sf::Vector2f{ 0.0, 0.0 }	, sf::Vector2f{ 640.0, 10.0 }};
	wall  left	   {sf::Vector2f{ 0.0, 0.0 }	, sf::Vector2f{ 10.0, 480.0 }};
	wall  right	   {sf::Vector2f{ 630.0, 0.0 }	, sf::Vector2f{ 10.0, 480.0 }};
	wall  bottom   {sf::Vector2f{ 0.0, 470.0 }	, sf::Vector2f{ 640.0, 10.0 }};
	block my_block {sf::Vector2f{ 32.0, 240.0 }	, 40};

	std::vector<drawable*> objects = {
		&my_ball, &top, &left, &right, &bottom, &my_block
	};

	action actions[] = {
		action(sf::Keyboard::Left,  [&](){my_block.move(sf::Vector2f(-5.0,  0.0));}),
		action(sf::Keyboard::Right, [&](){my_block.move(sf::Vector2f(+5.0,  0.0));}),
		action(sf::Keyboard::Up,    [&](){my_block.move(sf::Vector2f( 0.0, -5.0));}),
		action(sf::Keyboard::Down,  [&](){my_block.move(sf::Vector2f( 0.0, +5.0));}),
		action(sf::Mouse::Left,     [&](){my_block.jump(sf::Mouse::getPosition(window));}),
		action(true, 				[&](){my_ball.collisionCheck(objects);}),
		action(true,                [&](){my_ball.move();})
	};

	while(window.isOpen()){
		for(auto &action : actions)
			action();

		window.clear();
			for(auto &item : objects)
				item -> draw(window);
		window.display();

		sf::sleep(sf::milliseconds(20));

        sf::Event event;		
	    while(window.pollEvent(event)){
			if(event.type == sf::Event::Closed)
				window.close();
		}	
	}
	std::cout << "Terminating application\n";
	return 0;
}