#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <functional>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
#include <range/v3/all.hpp>
struct File{
    std::string path;
    int filesize = 0;
};

struct Directory{
    std::string path;
    int size = -1;
    std::unordered_set<std::string> childDir;
    std::unordered_set<std::string> childFiles;
};

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

    auto files = std::unordered_map<std::string, File>{};
    auto dirs = std::unordered_map<std::string, Directory>{};
void Parse(){

    auto input = ReadAllLinesInFile("input.txt");
    auto current = std::vector<std::string>{{"/"}};
    dirs["/"] = Directory{"/"};
    for(const auto& line : input){
        auto token = SplitString(line, ' ');

        if(token[0] == "$"){

                if(token[1] == "ls"){
                    continue;
                }
                else{
                    const auto& target = token[2];
                    if(target == "/"){
                        current.clear();
                        current.emplace_back("/");
                    }
                    else if(target == ".."){
                        current.pop_back();
                    }
                    else{
                        auto next_dir = current.back() + target + "/";
                        current.emplace_back(next_dir);
                    }
                    std::cout << current.back() << "\n";
                }
        }
        else{
            auto& parent = dirs.at(current.back());
            if(token[0] == "dir"){
                auto path = current.back() + token[1] + "/";
                if(!dirs.contains(path)){
                    dirs[path] = Directory{path};
                }
                parent.childDir.insert(path);
            }
            else{

                auto path = current.back() + token[1];
                if(!files.contains(token[1])){
                    files[path] = File{ path, std::stoi(token[0])};
                }
                parent.childFiles.insert(path);
            }
        }
    }
}
int CountSize(Directory& directory){
    if(directory.size >= 0){
        return directory.size;
    }
    auto totalfile = ranges::accumulate(directory.childFiles, 0, [](int sum, const std::string& path){return sum + files.at(path).filesize;});

    directory.size = ranges::accumulate(directory.childDir, totalfile, [](int sum, const std::string& path){return sum + CountSize(dirs.at(path));});
    return directory.size;
}

int main(void){
    Parse();
    CountSize(dirs.at("/"));

    // Part 1
    auto output = [](const Directory& directory){return directory.size <= 100000;};
    auto totalDirSize = ranges::accumulate(dirs | ranges::views::values | ranges::views::filter(output),0, [](int sum, const Directory& directory){return sum + directory.size;});
    std::cout<<totalDirSize << "\n";

    // Part2
    const auto totalSpace = 70000000;
    const auto targetSpace = 30000000;
    const auto unused = totalSpace - dirs.at("/").size;
    const auto sizeToDelete = targetSpace - unused;

    auto directoriesSortedBySize = dirs | ranges::views::values | ranges::to<std::vector>();
		ranges::sort(directoriesSortedBySize, std::less<int>{}, [](const Directory& directory) { return directory.size; });

		auto deletedDirectorySize = 0;
		for (const auto& directory : directoriesSortedBySize)
		{
			if (directory.size >= sizeToDelete)
			{
				deletedDirectorySize = directory.size;
				break;
			}
		}
        std::cout << deletedDirectorySize;
}

