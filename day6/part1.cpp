#include <fstream>
#include <ranges>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <map>
#include <queue>
#include <unordered_map>
#include <type_traits>
std::vector<std::string> ReadAllLinesInFile(std::string path)
	{
		auto lines = std::vector<std::string>{};

        std::ifstream infile(path);
		auto currentLine = std::string{};
		while (std::getline(infile, currentLine))
		{
			lines.emplace_back(currentLine);
		}

		return lines;
	}


int main(void){
    auto filestream = ReadAllLinesInFile("input.txt");
    auto packetSize = 14;
    int total;
    auto line = filestream[0];
    for(int i = 0; i < line.size()-packetSize; ++i){
        auto packet = line.substr(i, packetSize);
        std::sort(packet.begin(), packet.end());

           for (int i = 0; i < packet.length()-1; i++) {
                if (packet[i] == packet[i + 1]) {
                    packet.erase(i, i+1);
                }
            }

       if(packet.size() == packetSize){
            total = i + packetSize;
            break;
        }
    }
    std::cout << total;
}
