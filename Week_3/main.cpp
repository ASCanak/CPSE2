#include "../headers/circle.hpp"
#include "../headers/drawable.hpp"
#include "../headers/exceptions.hpp"
#include "../headers/factory.hpp"
#include "../headers/line.hpp"
#include "../headers/picture.hpp"
#include "../headers/rectangle.hpp"

int main(int argc, char *argv[]){
	sf::RenderWindow window{ sf::VideoMode{ 1280, 720 }, "SFML window" };

	std::ifstream input("map.txt");
	std::vector<drawable*> objects;

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

		window.clear();
			for(auto &item : objects){
				if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
					item -> jumpOnCollision(sf::Mouse::getPosition(window));
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
	myFile.open("map.txt", std::ofstream::trunc);
		for(auto &item : objects)
			myFile << item -> getScreenObject();
	myFile.close();

	std::cout << "Terminating application\n";
	return 0;
}