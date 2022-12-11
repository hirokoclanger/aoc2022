#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <memory>
#include <sys/wait.h>
#include <tuple>
#include <vector>
#include <functional>
#include <map>
#include <numeric>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
#include <range/v3/all.hpp>
#include "../aoc/util/util.hpp"
#include <array>
// Part 2
void row(std::vector<int> values, int current_row){

    int start = 40 * current_row - 40;
    for(int i = start; i < start + 40; i++){
        int sprite =values[i];
        if(i % 40 == (sprite - 1) || i % 40 == sprite || i % 40 == (sprite + 1) ){
            std::cout<<"#";
        }
        else{
            std::cout<<".";
        }
    }
    std::cout<<"\n";
}

void drawer(std::vector<int> values ){
    int screen_size = 7;

    for(int j = 0 ; j < screen_size; ++j ){
        row(values , j);
    }
}

// Part 1 Output
int output(int cycle, int count){
                if(cycle % 40 == 20 ){
                    std::cout<< cycle * count << "\n";
                    return cycle*count;
                }
                else return 0;
}

std::tuple<std::string, std::string> parseInstr(std::string str){

    auto tokens =  SplitString(str, ' ');
    return std::make_tuple(tokens[0] , tokens[1]);

}

int main()
	{
        int sum = 0;
		auto input = ReadAllLinesInFile("input.txt");
        std::vector<int> X{1};
        int cycle = 0;
        int count = 1;
        for(auto& line : input){

            const auto [instruction, value] = parseInstr(line);
            X.push_back(X.back());

            if(instruction=="noop") {cycle++;
               sum += output(cycle, count);
            }
            else if(instruction=="addx"){
                int x = std::stoi(value);
                X.push_back(X.back()+x);

                for(int i = 0; i <2; ++i){
                    cycle++;
                    sum += output(cycle, count);
                }

            count = count + x;
                }
        }
    // Part1
    std::cout << sum;
    for(int k : X ) std::cout<< k << "\n";

    // Part2
    drawer(X);
}
