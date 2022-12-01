#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <type_traits>
using namespace std;
bool isEmpty(string buffer){
  for(int i = 0; i<buffer.length(); i++){
    if(buffer[i] != '\t') //add chars you want to exempt here
      return false;
  }
return true;
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
        cout << curr_elf;
    }
}
}
