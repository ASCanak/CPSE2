#include "textInterface.hpp"

move textInterface::getInput(const int turn){
    int input = 0;

    std::cout << "enter input: ";
    std::cin >> input;

    while(input < -1 || input > 9){
        std::cout << "invalid input\n re-enter input: ";
        std::cin >> input; 
    }

    while(turn == 0 && input == -1){
        std::cout << "can't undo if you haven't done anything\n re-enter input:";
        std::cin >> input;
    }

    if(turn % 2 == 0)
        return {0, input};
    else 
        return {1, input};
}

void textInterface::draw(const int turn, const std::vector<int> board){
    std::cout << "type a number from 1-9 to place your ";
    
    if(turn % 2 == 0)
        std::cout << "x";
    else 
        std::cout << "o";
    
    std::cout << " or type -1 to undo and/or 0 to exit the game\n\n";

    std::cout << " 1 | 2 | 3 \n" 
              << "-----------\n"
              << " 4 | 5 | 6 \n"
              << "-----------\n"
              << " 7 | 8 | 9 \n\n";

    drawBoard(board);
}

void textInterface::drawWin(const int turn, const std::vector<int> board){
    drawBoard(board);
    
    if(turn % 2 == 0)
        std::cout << "player 'x' won\n";
    else 
        std::cout << "player 'o' won\n";

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