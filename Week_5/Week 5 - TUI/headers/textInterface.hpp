#ifndef TEXTINTERFACE_HPP
#define TEXTINTERFACE_HPP

#include "gameControl.hpp"

class textInterface{
private:
    gameControl ticTacToe;

    bool running = true;

    std::string int_plrID(int plrID);

    void gameLoop();
    void getInput(const int turn);

    void draw();
    void drawInstructions(const int turn);
    void drawTie();
    void drawWin(const int turn);
    void drawBoard(const std::vector<int> board);

public:
    textInterface();
};

#endif