#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <map>
#include <queue>
#include <unordered_map>
#include <type_traits>
using namespace std;
/*
[S]                 [T] [Q]
[L]             [B] [M] [P]     [T]
[F]     [S]     [Z] [N] [S]     [R]
[Z] [R] [N]     [R] [D] [F]     [V]
[D] [Z] [H] [J] [W] [G] [W]     [G]
[B] [M] [C] [F] [H] [Z] [N] [R] [L]
[R] [B] [L] [C] [G] [J] [L] [Z] [C]
[H] [T] [Z] [S] [P] [V] [G] [M] [M]
 1   2   3   4   5   6   7   8   9
 */
void crane(deque<char> &take, deque<char> &place, int numMoves) {
    stack<char> temp;
    for (int i = 0; i < numMoves; i++) {
        temp.push(take.back());
        take.pop_back();
    }
    while (!temp.empty()) {
        place.push_back(temp.top());
        temp.pop();
    }
    return;
}
int main() {

    unordered_map<int, deque<char> > map;
    map[1] = {'H','R','B','D','Z','F','L','S'};
    map[2] = {'T','B','M','Z','R'};
    map[3] = {'Z','L','C','H','N','S'};
    map[4] = {'S','C','F','J'};
    map[5] = {'P','G','H','W','R','Z','B'};
    map[6] = {'V','J','Z','G','D','N','M','T'};
    map[7] = {'G','L','N','W','F','S','P','Q'};
    map[8] = {'M','Z','R'};
    map[9] = {'M','C','L','G','V','R','T'};

    ifstream input("input.txt");
    string instruct;

    while (getline(input, instruct)) {
        string numMoves = "", take = "", place = "";
        if (isdigit(instruct[6])) {
            numMoves = instruct.substr(5, 2);
            take = instruct[13];
            place = instruct[18];
        }
        else {
            numMoves = instruct[5];
            take = instruct[12];
            place = instruct[17];
        }
        cout << numMoves << " " << take << " " << place << endl;
        crane(map[stoi(take)], map[stoi(place)], stoi(numMoves));
    }
    cout << "Column 1: " << map[1].back() << endl;
    cout << "Column 2: " << map[2].back() << endl;
    cout << "Column 3: " << map[3].back() << endl;
    cout << "Column 4: " << map[4].back() << endl;
    cout << "Column 5: " << map[5].back() << endl;
    cout << "Column 6: " << map[6].back() << endl;
    cout << "Column 7: " << map[7].back() << endl;
    cout << "Column 8: " << map[8].back() << endl;
    cout << "Column 9: " << map[9].back() << endl;
}
