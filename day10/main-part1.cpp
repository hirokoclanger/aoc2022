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
            if(instruction=="noop") {cycle++;
               sum += output(cycle, count);
            }
            else if(instruction=="addx"){
                int x = std::stoi(value);
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
        std::cout << sum;
    }
