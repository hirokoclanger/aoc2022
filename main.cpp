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
std::tuple<int, int> range_in_values(int current_row){
    int end = 0;
    int start = 0;
    if(current_row == 0){
        start = 0;
        end = 40;
    }
    else if(current_row == 1){
        start = 40;
        end = 80;
    }
    else if(current_row == 2){
        start = 80;
        end = 120;
    }
    else if(current_row == 3){
        start = 120;
        end = 160;
    }
    else if(current_row == 4){
        start = 160;
        end = 200;
    }
    else if(current_row == 5){
        start = 200;
        end = 240;
    }
    return std::make_tuple(start, end);

}
void row(std::vector<int> values, int current_row){
    const auto [start, end] = range_in_values(current_row);

    for(int i = start; i < end; i++){
        int sprite =values[i];
        if(i%40 == (sprite-1) || i%40 == sprite || i%40 == (sprite+1) ){
            std::cout<<"#";
        }
        else{
            std::cout<<".";
        }
    }
    std::cout<<"\n";
}

void drawer(std::vector<int> values ){

  int screen_size = 6;
  for(int j = 0 ; j < screen_size; ++j ){
    row(values , j);
  }
}

// Part 1 Output
int output(int cycle, int count){

            if(cycle == 20){
                std::cout<< cycle * count << "\n";
                return cycle*count;
            }
            if(cycle == 60){
                std::cout<< cycle * count << "\n";
                return cycle*count;
            }
            if(cycle == 100){
                std::cout<< cycle * count << "\n";
                return cycle*count;
            }
            if(cycle == 140){
                std::cout<< cycle * count << "\n";
                return cycle*count;
            }
            if(cycle == 180){
                std::cout<< cycle * count << "\n";
                return cycle*count;
            }
            if(cycle == 220){
                std::cout<< cycle * count << "\n";
                return cycle*count;
            }
            return 0;
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
            if(line.empty()){
                continue;
            }

            const auto [instruction, value] = parseInstr(line);
            X.push_back(X.back());

            if(instruction=="noop") {cycle++;
               sum += output(cycle, count);
            }
            else if(instruction=="addx"){
                int x = std::stoi(value);
                X.push_back(X.back()+x);
                if(x < 0){
                    int range = x*-1;
                    for(int i = 0; i <2; ++i){
                        cycle++;
                       sum += output(cycle, count);
                    }
                    count = count + x;
                }
                else{
                    int range = x;
                    for(int i = 0; i <2; ++i){
                        cycle++;
                         sum += output(cycle, count);
                    }
                    count = count + x;
                }
            }
        }
        // Part1
        std::cout << sum;
        for(int k : X ) std::cout<< k << "\n";
        // Part2
        drawer(X);
    }
