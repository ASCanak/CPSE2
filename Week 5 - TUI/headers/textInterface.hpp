#ifndef TEXTINTERFACE_HPP
#define TEXTINTERFACE_HPP

#include <iostream>
#include <vector> 
#include <string> 

struct move{bool plrID; int boxID;};

class textInterface{
private:
    void drawBoard(const std::vector<int> board);

    std::string int_plrID(int plrID);

public:
    textInterface(){}

    move getInput(const int turn);

    void draw(const int turn, const std::vector<int> board);
    void drawWin(const int turn, const std::vector<int> board);
};

#endif