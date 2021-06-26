#include "graphicalInterface.hpp"

graphicalInterface::graphicalInterface(sf::RenderWindow &window):
    window(window)
{
    gameLoop();
}

void graphicalInterface::gameLoop(){
    std::vector<icon*> objects;

    initObjects(objects);

    while(window.isOpen()){		
        draw(objects);

        getInput(objects, ticTacToe.getTurn());

        if(ticTacToe.getTurn() == 9){
            objects[11] -> setColor(sf::Color::Red);
        }
        else if(ticTacToe.checkWin()){
            objects[11] -> setColor(sf::Color::Red);
            win = true;
        }
        else{
            objects[11] -> setColor(sf::Color::Transparent);
            win = false;
        }

        sf::sleep(sf::milliseconds(20));
    }
    std::cout << "\nticTacToe terminated\n\n";
}

void graphicalInterface::initObjects(std::vector<icon*> &objects){
    sf::Vector2f size = {100,100};
    
    objects.push_back(new icon({-100, -100}, {1480, 1000}, "assets/empty_Tile.png"));

    objects.push_back(new icon({150, 200}, size, "assets/empty_Tile.png"));
    objects.push_back(new icon({250, 200}, size, "assets/empty_Tile.png"));
    objects.push_back(new icon({350, 200}, size, "assets/empty_Tile.png"));
    objects.push_back(new icon({150, 300}, size, "assets/empty_Tile.png"));
    objects.push_back(new icon({250, 300}, size, "assets/empty_Tile.png"));
    objects.push_back(new icon({350, 300}, size, "assets/empty_Tile.png"));
    objects.push_back(new icon({150, 400}, size, "assets/empty_Tile.png"));
    objects.push_back(new icon({250, 400}, size, "assets/empty_Tile.png"));
    objects.push_back(new icon({350, 400}, size, "assets/empty_Tile.png"));

    objects.push_back(new icon({325, 50}, size, "assets/undo_Button.png"));
    objects.push_back(new icon({175, 50}, size, "assets/play_Button.png"));
    
    objects.push_back(new icon({25, 200}, size, "assets/cross_Tile.png"));
}

void graphicalInterface::getInput(std::vector<icon*> &objects, const int turn){
    sf::Event event;		
    while(window.pollEvent(event)){
        unsigned int i = 0;
        
        for(auto &item : objects){
            if(i >= 1){
                if(event.mouseButton.button == sf::Mouse::Left && event.type == sf::Event::MouseButtonPressed && item -> collisionCheck(sf::Mouse::getPosition(window))){
                    if(i >= 1 && i <= 9 && win == false){
                        ticTacToe.checkInput(i);
                    }
                    else if(i == 10 && turn != 0){
                        ticTacToe.undo();
                    }
                    else if(i == 11){
                        ticTacToe.newGame();
                    }
                }
            }
            i++;
        }
        
        if(event.type == sf::Event::Closed)
            window.close();
    }
}

void graphicalInterface::draw(std::vector<icon*> &objects){
    drawCurrentPlr(objects);
    drawBoard(objects, ticTacToe.calcBoard());
    
    window.clear();
        for(auto &item : objects)
            item -> draw(window);
	window.display();
}

void graphicalInterface::drawCurrentPlr(std::vector<icon*> &objects){
    if(ticTacToe.getTurn() % 2)
        objects[12] -> setTexture("assets/circle_Tile.png");
    else
        objects[12] -> setTexture("assets/cross_Tile.png");
}

void graphicalInterface::drawBoard(std::vector<icon*> &objects, const std::vector<int> board){
    unsigned int i = 0;
    
    for(auto &item : objects){
        if(i >= 1 && i <= 9)
            item -> setTexture(int_Filename(board[i - 1]));
        i++;
    }
}

std::string graphicalInterface::int_Filename(int plrID){
    if(plrID == 0)
        return "assets/cross_Tile.png";
    else if(plrID == 1)
        return "assets/circle_Tile.png";
    else
        return "assets/empty_Tile.png";
}