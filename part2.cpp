#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <map>
#include <type_traits>
using namespace std;
int main(){
    ifstream infile("test.txt");
    string buffer;
    int scores;
    vector<string> lines;
// get char in line if is digit then range from starting to end is current range
// if comma then new pair
// if next range between prev range, count
    while(getline(infile, buffer, '\n')){
        vector<int> fir;
        int group = 1;
        vector<int> sec;
        for(string::iterator it = buffer.begin(); it != buffer.end(); ++it) {
            if(*it == ','){
                group = 2;
            }

            if(isdigit(*it) && group == 1){
                int number1 = std::stoi(*it);
                fir.push_back(number1);
            }
            if(isdigit(*it) && group == 2){
                int number = std::stoi(*it);
                sec.push_back(number);
            }
        }
        cout << fir[0];

        if(fir[0] >= sec[0] && fir[fir.size()] <= sec[sec.size()]){
            scores+=1;
        }
        else if(sec[0] >= fir[0] && sec[sec.size()] <= fir[fir.size()]){
            scores+=1;
        }

    }
   cout << scores;
}
