#include <fstream>
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(){
    ifstream infile("input.txt");
    map<string, int> movement;
    movement.insert(pair<string, int>("forward" , 0));
    movement.insert(pair<string, int>("down" , 0));
    movement.insert(pair<string, int>("up" , 0));
    string d;
    int b;
    int aim = 0;
    while (infile >> d >> b)
    {

        cout << aim << "\n";
        if(d == "forward"){
        movement[d] = movement[d] + b;
        movement["down"] = movement["down"] + (b*aim);
        }
        else if(d == "down")
        aim = aim + b ;
        if(d == "up")
        aim = aim - b;
    }
    int total = movement["forward"] * movement["down"];
    cout << total << "\n" ;
    for(auto& i : movement){
        cout << i.first << "\t" << i.second << "\n";
    }
}
