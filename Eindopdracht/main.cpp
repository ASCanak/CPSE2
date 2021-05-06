#include "../headers/actions.hpp"
#include "../headers/circle.hpp"
#include "../headers/drawable.hpp"
#include "../headers/exceptions.hpp"
#include "../headers/factory.hpp"
#include "../headers/picture.hpp"
#include "../headers/rectangle.hpp"

#define hudCircle 2
#define hudBlock 3
#define selectorTool 4
#define deletingTool 5
#define toForegroundTool 6
#define toBackgroundTool 7

int main(){
	sf::RenderWindow window{ sf::VideoMode{ 1280, 720 }, "SFML window" };

	std::string textfileName = "objects.txt";
	std::ifstream objectsIn(textfileName);
	std::vector<drawable*> objects;

// FACTORY IN
	try{
		for(;;)
			objects.push_back(screen_object_read(objectsIn)); //objects.insert(objects.begin(), screen_object_read(input));
	}	
	catch(const end_of_file &){
		//do nothing
	}
	catch(std::exception & problem){
		std::cout << problem.what();
	}

	unsigned int selectedObjectID = 0;
	bool activeObject = false;
	unsigned int state = selectorTool;
	unsigned int previous_State = 0;
	
	sf::Color activeColor = sf::Color::Black;
	objects[hudCircle] -> setColor(activeColor);
	objects[hudBlock] -> setColor(activeColor);
	objects[selectorTool] -> setColor(sf::Color::Red);

	while(window.isOpen()){		
// DRAWING
		window.clear();
			for(auto &item : objects)
				item -> draw(window);
		window.display();

// WINDOW EVENTS
        sf::Event event;		
	    while(window.pollEvent(event)){
			unsigned int i = 0;
			
			for(auto &item : objects){
				if(i <= 12){ //Pressing items from the Menu
					if(event.mouseButton.button == sf::Mouse::Left){
						if(item -> collisionCheck(sf::Mouse::getPosition(window))){
							if(i == 2 && state == selectorTool){ //Creating a circle with the desired color
								objects.push_back(new circle({1135,15}, 25, activeColor));
								activeObject = true;
								selectedObjectID = objects.size() - 1;
							}
							else if(i == 3 && state == selectorTool){ //Creating a cube with the desired color
								objects.push_back(new rectangle({1135,75}, {50,50}, activeColor));
								activeObject = true;
								selectedObjectID = objects.size() - 1;
							}
							else if(i >= 4 && i <= 7){
								if(i == 4 && state != selectorTool){			//Selecting the selector tool
									previous_State = state;
									state = selectorTool;
								}
								else if(i == 5 && state != deletingTool){		//Selecting the deleting tool
									previous_State = state;
									state = deletingTool;
								}
								else if(i == 6 && state != toForegroundTool){	//Selecting the to foreground tool
									previous_State = state;
									state = toForegroundTool;
								}
								else if(i == 7 && state != toBackgroundTool){	//Selecting the to background tool
									previous_State = state;
									state = toBackgroundTool;
								}
								objects[previous_State] -> setColor(sf::Color(35,39,42));
								objects[state] -> setColor(sf::Color::Red);
							}
							else if(i >= 8 && i <= 12 && state == selectorTool){ //Setting the new desired color
								activeColor = item -> getColor();
								objects[hudCircle] -> setColor(activeColor);
								objects[hudBlock] -> setColor(activeColor);
							}
						}
					}
				}
				else{ // Pressing objects
					if(i == selectedObjectID && activeObject && state == selectorTool){
						if(event.mouseButton.button == sf::Mouse::Left && event.type == sf::Event::MouseButtonReleased){
							selectedObjectID = 0;
							activeObject = false;
						}
						else
							item -> jump(sf::Mouse::getPosition(window));
					}
					else if(!selectedObjectID && state == selectorTool){
						if(event.mouseButton.button == sf::Mouse::Left){
							if(item -> collisionCheck(sf::Mouse::getPosition(window))){
								item -> jump(sf::Mouse::getPosition(window));
								objects.push_back(item);
								objects.erase(objects.begin()+i);
								activeObject = true;
								selectedObjectID = objects.size()-1;
							}
						}
					}
					if(event.mouseButton.button == sf::Mouse::Left){
						if(item -> collisionCheck(sf::Mouse::getPosition(window))){
							if(state == deletingTool) 			//delete
								objects.erase(objects.begin()+i);
							else if(state == toForegroundTool){ //drag to the foreground
								objects.push_back(item);
								objects.erase(objects.begin()+i);
							}
							else if(state == toBackgroundTool){ //drag to the background
								objects.insert(objects.begin()+13, objects[i]);
								objects.erase(objects.begin()+i+1);
							}
						}
					}
				}
				i++;
			}
			if(event.type == sf::Event::Closed)
				window.close();
		}
		sf::sleep(sf::milliseconds(20));	
	}

// FACTORY OUT
	std::ofstream myFile;
	myFile.open(textfileName, std::ofstream::trunc);
		for(auto &item : objects)
			item -> screen_object_write(textfileName);
	myFile.close();

	std::cout << "Terminating application\n";
	return 0;
}