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
    string scoreset;
    string buffer;
    vector<string> lines;
    while(getline(infile, buffer, '\n')){
        string fir;
        int len = buffer.size();
        //  get all 3 lines and compare them, the get the single idenity item
        for(string::iterator it = buffer.begin(); it != buffer.end(); ++it) {
              fir+= *it;
        }
        lines.push_back(fir);

    }

    for(int l = 0;  l < lines.size(); l+=3){
        for(char b : lines[l]){
            auto line2 = std::find(lines[l+1].begin(), lines[l+1].end(), b);
            auto line3 = std::find(lines[l+2].begin(), lines[l+2].end(), b);

            if(line2 != end(lines[l+1]) && line3 != end(lines[l+2])){
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
