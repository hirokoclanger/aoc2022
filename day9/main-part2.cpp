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
#include "Utilities/Hashing.h"
#include <array>
struct Point {
        int x = 0;
        int y = 0;

        Point operator-(const Point &other) const { return Point{x - other.x, y - other.y}; };

        auto operator<=>(const Point &) const = default;
};

 IMPLEMENT_STD_HASH(Point, value.x, value.y);

Point GetNextTailPosition(const Point& head, const Point& tail)
	{
        int count = 0 ;
		auto relative = head - tail;
		if (std::abs(relative.x) <= 1 && std::abs(relative.y) <= 1)
		{
			return tail;
		}

		if (head.y == tail.y)
		{
			return Point{ head.x > tail.x ? head.x - 1 : head.x + 1, tail.y };
		}
		else if (head.x == tail.x)
		{
			return Point{ tail.x, head.y > tail.y ? head.y - 1 : tail.y - 1 };
		}
		else
		{
			return Point
			{
				head.x > tail.x ? tail.x + 1 : tail.x - 1,
				head.y > tail.y ? tail.y + 1 : tail.y - 1
			};
		}

    }
int main()
	{
		auto input = ReadAllLinesInFile("input.txt");
		auto childs = std::array<Point, 10>{0};

        auto& head = childs[0];
		auto& tail = childs[childs.size()-1];
        std::unordered_set<Point> visited{tail};
		for (const auto& line : input)
		{
			auto direction = line[0];
			auto magnitude = std::stoi(line.substr(2));

			while (magnitude-- > 0)
			{
				switch (direction)
				{
				case 'L':
					head.x--;
					break;
				case 'R':
					head.x++;
					break;
				case 'U':
					head.y--;
					break;
				case 'D':
					head.y++;
					break;
				}

                for(auto current = 0, next = 1; next < childs.size(); ++current, ++next ){
                   childs[next] = GetNextTailPosition(childs[current], childs[next]);
                }
                visited.insert(tail);
            }
        }
        std::cout<< "\n" << visited.size();
    }
