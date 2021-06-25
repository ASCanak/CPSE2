#include "gameControl.hpp"

gameControl::gameControl(){
    gameLoop();
}

void gameControl::gameLoop(){
    move input;
    while(running){
        tui.draw(commandList.size(), calcBoard());
        
        input = tui.getInput(commandList.size());
        
        while(!checkInput(input))
            input = tui.getInput(commandList.size());
        
        if(commandList.size() > 4){
            std::cout << "\nticTacToe terminated\n";
            if(checkWin()){
                tui.drawWin(commandList.size(), calcBoard());
                newGame();
            }
        }
        else if(commandList.size() == 9){
            std::cout << "\nticTacToe terminated\n";
            newGame();
        }
    }
    std::cout << "\nticTacToe terminated\n";
}

std::vector<int> gameControl::calcBoard(){
    std::vector<int> currentBoard = {-1, -1, -1, -1, -1, -1, -1, -1, -1};

    for(uint i = 0; i < commandList.size(); i++)
        currentBoard[commandList[i].boxID - 1] = commandList[i].plrID;
    
    return currentBoard;
}

void gameControl::newGame(){
    commandList.clear();
}

bool gameControl::checkInput(move input){
    if(input.boxID == 0){       //Close the game
        running = false;
        return true;
    }
    else if(input.boxID == -1){ //Undo
        commandList.pop_back();
        return true;
    }
    else if(input.boxID >= 1 && input.boxID <= 9){ //check if the value is already in the list
        if(commandList.size() > 0){
            for(uint i = 0; i < commandList.size(); i++){
                if(commandList[i].boxID == input.boxID)
                    return false;
            }  
        }
        commandList.push_back(input);
        return true;
    }
    else 
        return false;
}

bool gameControl::checkWin(){
    std::vector<int> currentBoard = calcBoard();

    for(uint i = 0; i < currentBoard.size(); i++){
        std::cout << currentBoard[i] << "\n";
    }
    
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