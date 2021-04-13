#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include "../headers/drawable.hpp"

class unknown_color : public std::exception{
private:
    std::string popup;
public: 
    unknown_color(const std::string & name):
    
    popup{std::string("unknown color [") + name + "]"}{}

    const char * what() const noexcept override{
        return popup.c_str();
    }
};

class unkown_shape : public std::exception{
private:
    std::string popup;
public:
    unkown_shape(const std::string & name):

    popup{std::string("unknown shape [") + name + "]"}{}

    const char * what() const noexcept override{
        return popup.c_str();
    }
};

class invalid_position : public std::exception{
private:
    std::string popup;
public:
    invalid_position(const char & name):

    popup{std::string("unknown shape [") + name + "]"}{}

    const char * what() const noexcept override {
        return popup.c_str();
    }
};

class end_of_file : public std::exception{
private: 
    std::string popup;
public:
    end_of_file():

    popup{std::string("end of file")}{}
    
    const char * what() const noexcept override{
        return popup.c_str();
    }
};

#endif