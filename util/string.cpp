#include "headers.hpp"

std::vector<std::string> SplitString(std::string in_str, char splitter){
    size_t pos = 0;
    std::string line = in_str;
    std::vector <std::string> tokens;
    std::stringstream check1(line);
    std::string buffer;
    while(getline(check1, buffer, splitter))
    {
        tokens.push_back(buffer);
    }
    return tokens;
}

