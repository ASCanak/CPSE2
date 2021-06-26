#ifndef GRAPHICALINTERFACE_HPP
#define GRAPHICALINTERFACE_HPP

#include "gameControl.hpp"
#include "icon.hpp"

class graphicalInterface{
private:
    sf::RenderWindow &window;
    gameControl ticTacToe;

    bool win = false;

    std::string int_Filename(int plrID);

    void gameLoop();
    void initObjects(std::vector<icon*> &objects);

    void getInput(std::vector<icon*> &objects, const int turn);
    void getContinueInput(std::vector<icon*> &objects);
    
    void draw(std::vector<icon*> &objects);
    void drawCurrentPlr(std::vector<icon*> &objects);
    void drawBoard(std::vector<icon*> &objects, const std::vector<int> board);

public:
    graphicalInterface(sf::RenderWindow &window);
};

#endif