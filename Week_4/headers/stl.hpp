#ifndef STL_HPP
#define STL_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <functional>
#include <set>
#include <map>

class stl{
private:
	std::string fileName;
    std::vector<char> charVector = {};
    std::vector<std::string> stringVector = {};
    std::map<char, int> mapOfLetterCounts;
    std::map<std::string, int> mapOfWordCounts;

    static char removePunctuationAndToLowercase(char c);
public:
	stl(std::string fileName);

    void printCharCount();                              //Opgave 2
    void printLineCount();                              //Opgave 3
    void printLetterCount();                            //Opgave 4
    void convertToLower();                              //Opgave 5
    void individualLetterCount();                       //Opgave 6
    void printIndividualLetterCount(unsigned int type); //Opgave 7
    void printTenMostCommonWords();                     //Opgave 8
};

#endif 