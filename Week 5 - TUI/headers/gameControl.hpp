#ifndef GAMECONTROL_HPP
#define GAMECONTROL_HPP

#include "textInterface.hpp"

class gameControl{
private:
    textInterface tui;

    std::vector<move> commandList = {};

    bool running = true;

    void gameLoop();
    
    std::vector<int> calcBoard();
    
    void newGame();

    bool checkInput(move input);
    bool checkWin();    

public:
    gameControl();
};

#endif