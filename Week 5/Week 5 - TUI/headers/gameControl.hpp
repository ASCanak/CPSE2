#ifndef GAMECONTROL_HPP
#define GAMECONTROL_HPP

#include <vector> 
#include <string> 
#include <iostream>

class gameControl{
private:
    std::vector<int> commandList = {};  

public:
    std::vector<int> calcBoard();

    int getTurn(){return commandList.size();};
    
    void newGame(){commandList.clear();};
    void undo(){commandList.pop_back();};

    bool checkInput(int input);
    bool checkWin(); 
};

#endif