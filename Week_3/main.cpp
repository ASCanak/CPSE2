#include "../headers/actions.hpp"
#include "../headers/circle.hpp"
#include "../headers/drawable.hpp"
#include "../headers/exceptions.hpp"
#include "../headers/factory.hpp"
#include "../headers/picture.hpp"
#include "../headers/rectangle.hpp"


int main(int argc, char *argv[]){
	sf::RenderWindow window{ sf::VideoMode{ 1280, 720 }, "SFML window" };

	std::ifstream input("map.txt");

	circle my_ball(sf::Vector2f{ 200.0, 240.0 }, 90, sf::Color::Red);
	rectangle my_Rectangle(sf::Vector2f{ 640.0, 240.0 }, sf::Vector2f{ 700.0, 320.0 }, sf::Color::Blue);
	picture my_Picture(sf::Vector2f{ 320.0, 240.0 }, sf::Vector2f{ 400.0, 320.0 }, "assets/BackgroundTile.png");

	std::vector<drawable*> objects = {
		&my_ball, &my_Rectangle, &my_Picture
	};

	try{
		for(;;)
			objects.push_back(screen_object_read(input));	
	}	
	catch(const end_of_file &){
		//do nothing
	}
	catch(std::exception & problem){
		std::cout << problem.what();
	}

	while(window.isOpen()){		
		if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
			for(auto &item : objects)
				item -> collisionCheck(sf::Mouse::getPosition(window));
		}

		window.clear();
			for(auto &item : objects){
				item -> draw(window);
			}
		window.display();

		sf::sleep(sf::milliseconds(20));


        sf::Event event;		
	    while(window.pollEvent(event)){
			if(event.type == sf::Event::Closed)
				window.close();
		}	
	}

	std::ofstream myFile;
	myFile.open("object.txt", std::ios_base::app);
		for(auto &item : objects)
			item -> screen_object_write();
	myFile.close();

	std::cout << "Terminating application\n";
	return 0;
}