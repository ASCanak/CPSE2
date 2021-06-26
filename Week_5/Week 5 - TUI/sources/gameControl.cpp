#include "gameControl.hpp"

std::vector<int> gameControl::calcBoard(){
    std::vector<int> currentBoard = {-1, -1, -1, -1, -1, -1, -1, -1, -1};

    for(uint i = 0; i < commandList.size(); i++)
        currentBoard[commandList[i] - 1] = i % 2;
    
    return currentBoard;
}

bool gameControl::checkInput(int input){ //check if the value is already in the list
    if(commandList.size() > 0){
        for(uint i = 0; i < commandList.size(); i++){
            if(commandList[i] == input)
                return true;
        }  
    }
    commandList.push_back(input);
    return false;
}

bool gameControl::checkWin(){
    std::vector<int> currentBoard = calcBoard();
    
    if(currentBoard[0] == currentBoard[1] && currentBoard[1] == currentBoard[2] && !(currentBoard[0] < 0))      //Horizontal top row
        return true;
    else if(currentBoard[3] == currentBoard[4] && currentBoard[4] == currentBoard[5] && !(currentBoard[3] < 0)) //Horizontal middle row
        return true;
    else if(currentBoard[6] == currentBoard[7] && currentBoard[7] == currentBoard[8] && !(currentBoard[6] < 0)) //Horizontal bottom row
        return true;
    else if(currentBoard[0] == currentBoard[3] && currentBoard[3] == currentBoard[6] && !(currentBoard[0] < 0)) //Vertical left row
        return true;
    else if(currentBoard[1] == currentBoard[4] && currentBoard[4] == currentBoard[7] && !(currentBoard[1] < 0)) //Vertical middle row
        return true;
    else if(currentBoard[2] == currentBoard[5] && currentBoard[5] == currentBoard[8] && !(currentBoard[2] < 0)) //Vertical right row
        return true;
    else if(currentBoard[0] == currentBoard[4] && currentBoard[4] == currentBoard[8] && !(currentBoard[0] < 0)) //Top left to bottom right
        return true;
    else if(currentBoard[2] == currentBoard[4] && currentBoard[4] == currentBoard[6] && !(currentBoard[2] < 0)) //Top Right to bottom Left
        return true;
    return false;
}