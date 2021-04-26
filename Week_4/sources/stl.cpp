#include "../headers/stl.hpp"

stl::stl(std::string fileName):
    fileName(fileName)
{
    std::ifstream textstream(fileName);
    char c;
    while(textstream.get(c))
        charVector.push_back(c);
    textstream.close();
}

void stl::printCharCount(){
    std::cout << "File contains: " << charVector.size() << " characters\n";
}

void stl::printLineCount(){
    std::cout << "File contains: " << std::count(charVector.begin(), charVector.end(), '\n') << " lines\n";
}

void stl::printLetterCount(){
    unsigned int letters = 0, temp_letters = 0;
    std::string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for(char c : alphabet){
        temp_letters = std::count(charVector.begin(), charVector.end(), c);
        letters += temp_letters;
    }
    std::cout << "File contains: " << letters << " letters\n";
}

void stl::convertToLower(){
    std::transform(charVector.begin(), charVector.end(), charVector.begin(), ::tolower);
}

void stl::individualLetterCount(){
    std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
    for(char c : alphabet)
        mapOfLetterCounts[c] = std::count(charVector.begin(), charVector.end(), c);
}

void stl::printIndividualLetterCount(unsigned int type){
    typedef std::pair<char, int> pair;
    std::vector<pair> vec;
    std::copy(mapOfLetterCounts.begin(), mapOfLetterCounts.end(), std::back_inserter<std::vector<pair>>(vec));
    
    if(type == 1){      //Alphabetical
        std::cout << "\nSorted Alphabetically:\n\n";
        
        std::sort(vec.begin(), vec.end(), [](const pair &l, const pair &r){
            if (l.first != r.first){
                return l.first < r.first;
            }
            return l.second < r.second;
        });
        
        for(auto const&pair : vec)
            std::cout << "Amount of " << pair.first << "'s: " << pair.second << "\n";
        
    }
    else if(type == 2){ //Count
        std::cout << "\nSorted Numerically:\n\n";
        
        std::sort(vec.begin(), vec.end(), [](const pair &l, const pair &r){
            if (l.second != r.second){
                return l.second > r.second;
            }
            return l.first > r.first;
        });

        for(auto const&pair : vec)
            std::cout << "Amount of " << pair.first << "'s: " << pair.second << "\n";
        
    }
    else
        std::cout << "did you mean printIndividualLetterCount(1 || 2)?\n";
}

char stl::removePunctuationAndToLowercase(char c){        
    if(c == '.' || c == '\t' || c == ',' || c == ';' || c == ':' || c == '}' || c == '{' || c == '(' || c == ')')
        return ' ';
    return(tolower(c));
}

void stl::printTenMostCommonWords(){
    std::cout << "\n Top 10 Most Common Words: \n\n";

    std::ifstream textstream(fileName);
    std::string s;
    while(!textstream.eof()){
        textstream >> s;
        std::transform(s.begin(), s.end(), s.begin(), removePunctuationAndToLowercase);
        stringVector.push_back(s);
    }
    textstream.close();

    for(unsigned int i = 0; i < 2000; i++){
        if(mapOfWordCounts.find(stringVector[i]) == mapOfWordCounts.end())
            mapOfWordCounts[stringVector[i]] = std::count(stringVector.begin(), stringVector.end(), stringVector[i]);
    }
    
    typedef std::pair<std::string, int> pair;
    std::vector<pair> vec;
    std::copy(mapOfWordCounts.begin(), mapOfWordCounts.end(), std::back_inserter<std::vector<pair>>(vec));  

    std::sort(vec.begin(), vec.end(), [](const pair &l, const pair &r){
        if (l.second != r.second){
            return l.second > r.second;
        }
        return l.first > r.first;
    });

    unsigned int j = 0;
    for(auto const&pair : vec){
        j++;
        if(j <= 10)
            std::cout << j <<". " << pair.first << " with " << pair.second << " occurences\n";
        else
            break;
    }
}