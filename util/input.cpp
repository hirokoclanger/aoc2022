#include "headers.hpp"

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
