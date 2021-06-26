#include "../headers/graphicalInterface.hpp"

int main(){
	sf::RenderWindow window(sf::VideoMode(550, 550), "ticTacToe", sf::Style::Close | sf::Style::Titlebar);

	graphicalInterface GUI(window);

	return 0;
}