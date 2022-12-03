#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <type_traits>
using namespace std;
int main(){
    ifstream infile("input.txt");
    map<char, int> wrongitems;
    string scoreset;
    string buffer;
    while(getline(infile, buffer, '\n')){
        vector<char> fir;
        vector<char> sec;
        int len = buffer.size();
        for(string::iterator it = buffer.begin(); it != buffer.end()-(len/2); ++it) {
              fir.push_back(*it);
        }

        for(string::iterator it = buffer.begin()+(len/2); it != buffer.end(); ++it) {
              sec.push_back(*it);
        }

        for(char b : sec){
            auto position = std::find(fir.begin(), fir.end(), b);
            if(position != end(fir)){
                scoreset+=b;
                break;
            }
        }
    }
    int score = 0;
    for(char k : scoreset){
        int ia = (int) k;
        if(islower(ia)){
            score+=(ia-96);
        }
        else {
            score+=(ia-38);
        }
    }
    cout << score;
}
