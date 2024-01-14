//parseStringIntoWords.cpp
#include "ParseStringIntoWords.h"
#include <sstream>

std::vector<std::string> parseStringIntoWords(std::string string){
    std::vector<std::string> words;
    std::stringstream ss(string); 

    std::string currWord;
    while(ss >> currWord){
        words.push_back(currWord);
    }

    return words;
}