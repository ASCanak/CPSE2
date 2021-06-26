#include "textInterface.hpp"

textInterface::textInterface(){
    gameLoop();
}

void textInterface::gameLoop(){
    while(running){
        draw();

        getInput(ticTacToe.getTurn());
        
        if(ticTacToe.getTurn() == 9){
            drawBoard(ticTacToe.calcBoard());
            drawTie();
            ticTacToe.newGame();
        }
        else if(ticTacToe.getTurn() > 4){
            if(ticTacToe.checkWin()){
                drawBoard(ticTacToe.calcBoard());
                drawWin(ticTacToe.getTurn());
                ticTacToe.newGame();
            }
        }
    }
    std::cout << "\nticTacToe terminated\n\n";
}

void textInterface::getInput(const int turn){
    int input = 0;

    std::cout << "\nenter input: ";
    std::cin >> input;

    if(input == 0)
        running = false;
    else if(input == -1){
        if(turn != 0)
            ticTacToe.undo();
        else{
            std::cout << "\nyou can't undo on the first turn";
            getInput(turn);
        }
    }
    else if(input >= 1 && input <= 9){
        if(ticTacToe.checkInput(input)){
            std::cout << "\nthat spot's taken";
            getInput(turn);
        }
    }
    else{
        std::cout << "\ninvalid input";
        getInput(turn);
    }
}

void textInterface::draw(){
    drawInstructions(ticTacToe.getTurn());
    drawBoard(ticTacToe.calcBoard());
}

void textInterface::drawInstructions(const int turn){
    std::cout << "\ntype a number from 1-9 to place your ";
    
    if(turn % 2 == 0)
        std::cout << "'x'";
    else 
        std::cout << "'o'";
    
    std::cout << " or type -1 to undo and/or 0 to exit the game\n\n";

    std::cout << " 1 | 2 | 3 \n" 
              << "-----------\n"
              << " 4 | 5 | 6 \n"
              << "-----------\n"
              << " 7 | 8 | 9 \n\n";
}

void textInterface::drawTie(){
    char input = ' ';

    std::cout << "\nit's a tie!\n";

    while(input != '1'){
        std::cout << "enter '1' to play a new game: ";
        std::cin >> input; 
    }
}

void textInterface::drawWin(const int turn){
    if(turn % 2 == 0)
        std::cout << "\nplayer 'x' won!\n";
    else 
        std::cout << "\nplayer 'o' won!\n";

    char input = ' ';

    while(input != '1'){
        std::cout << "enter '1' to play a new game: ";
        std::cin >> input; 
    }
}

void textInterface::drawBoard(const std::vector<int> board){
    std::cout << int_plrID(board[0]) << "|" << int_plrID(board[1]) << "|" << int_plrID(board[2]) << "\n"
              << "-----------\n"
              << int_plrID(board[3]) << "|" << int_plrID(board[4]) << "|" << int_plrID(board[5]) << "\n"
              << "-----------\n"
              << int_plrID(board[6]) << "|" << int_plrID(board[7]) << "|" << int_plrID(board[8]) << "\n";
}

std::string textInterface::int_plrID(int plrID){
    if(plrID == 0)
        return " x ";
    else if(plrID == 1)
        return " o ";
    else
        return "   ";
}