#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <functional>
#include <map>
#include <numeric>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
#include <range/v3/all.hpp>
#include "../aoc/util/util.hpp"
/*
 *           .
 *           .
 *       . . X . .
 *           .
 *           .
 *
 *
 * */
int main() {
    std::ifstream infile("input.txt");
    std::string buffer;
    std::map<std::vector<int>, int> positions;
    int distance;
    int count = 0;
    int countdub = 0;
    char move;
    int x = 0;
    int y = 0;
    while(infile >> move >> distance){
        bool visited = false;
        std::vector<int> currentpos;
            std::cout << "Starting at: " << x << " | " << y << " moving  " << move << " " << distance << "\n";
            if(move == 'L') {x-=distance; currentpos.push_back(x); currentpos.push_back(y);}
            else if(move == 'R') {x+=distance; currentpos.push_back(x); currentpos.push_back(y);}
            else if(move == 'U') {y+=distance; currentpos.push_back(y); currentpos.push_back(x);}
            else if(move == 'D') {y-=distance; currentpos.push_back(y); currentpos.push_back(x);}
            std::cout << "Resulting at:" <<  x << " | " << y << "\n";

            auto result = positions.insert(std::pair<std::vector<int>,int>(currentpos, 1));
            if(result.second == false){
                result.first->second++;
                std::cout << "Visited already \n";
            }
            else{
 std::cout<< " Added position to vector \n";
            }

    }
    for(auto & vec : positions){
        if(vec.second > 1){
            countdub++;
        }
        else count++;
    }
    std::cout<< "Unique Postions: " << count << " Duplicates " << countdub;
}
