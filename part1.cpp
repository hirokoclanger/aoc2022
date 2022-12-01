#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <type_traits>
using namespace std;

bool isEmpty(string buffer){
  for(int i = 0; i<buffer.length(); i++){
    if(buffer[i] != '\t')
      return false;
  }
return true;
}

bool compare(const pair<int, int>&a, const pair<int, int>&b)
{
   return a.second<b.second;
}

int main(){
    ifstream infile("input.txt");
    map<int, int> elfs;

    elfs.insert(pair<int, int>(1, 0));
    int b;
    int curr_elf = 1;

    string buffer;
    while(getline(infile, buffer, '\n')){

    if(isEmpty(buffer)){
        curr_elf++;
        elfs.insert(pair<int, int>(curr_elf, 0));
    } else {
        elfs[curr_elf] = elfs[curr_elf] + stoi(buffer);
    }
}
    int max_elf = max_element(elfs.begin(), elfs.end(), compare)->second;
    cout<<max_elf<<endl;
}
