#ifndef FACTORY_HPP
#define FACTORY_HPP

#include "drawable.hpp"
#include "exceptions.hpp"
#include "circle.hpp"
#include "picture.hpp"
#include "rectangle.hpp"

std::ifstream &operator>>(std::ifstream &input, sf::Vector2f &rhs){
    char c;

    if(!(input >> c))
        throw end_of_file(); 
    if(c != '(')
        throw invalid_position(c); 
    if(!(input >> rhs.x))
        throw end_of_file(); 
    if(!(input >> c )) 
        throw end_of_file();
    if(!(input >> rhs.y)) 
        throw end_of_file(); 
    if(!(input >> c))
        throw end_of_file(); 
    if(c != ')')
        throw invalid_position(c);
    
    return input;
}

std::ifstream &operator>>(std::ifstream &input, sf::Color &rhs){
    std::string s;
    input >> s;

    const struct{const char* name; sf::Color color;} colors[]{
        {"red",         sf::Color::Red},
        {"green",       sf::Color::Green},
        {"blue",        sf::Color::Blue},
        {"yellow",      sf::Color::Yellow},
        {"magenta",     sf::Color::Magenta},
        {"black",       sf::Color::Black},
        {"white",       sf::Color::White},
        {"cyan",        sf::Color::Cyan},
        {"transparent", sf::Color::Transparent},
        {"dark_grey",   sf::Color(44,47,51)},
        {"darker_grey", sf::Color(35,39,42)}
    };

    for(auto const &color : colors){
        if(color.name == s){
            rhs = color.color;
            return input;
        }
    }

    if(s == "")
        throw end_of_file();

    throw unknown_color(s);
}

drawable* screen_object_read(std::ifstream &input){
    std::string id;
    sf::Vector2f position;
    float size_f;
    sf::Vector2f size_2f;
    sf::Color color;
    std::string fileName;
    
    input >> id;

    if(id == "CIRCLE"){
        input >> position >> color >> size_f;
        return new circle(position, size_f, color);
    }
    else if(id == "PICTURE"){
        input >> position >> size_2f >> fileName ;
        return new picture(position, size_2f, fileName);
    }
    else if(id == "RECTANGLE"){
        input >> position >> size_2f >> color;
        return new rectangle(position, size_2f, color);
    }
    else if (id == "")
        throw end_of_file();

    throw unkown_shape( id );
}

#endif