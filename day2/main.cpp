
#include <fstream>
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(){
 ifstream infile("in.txt");

  int scores= 0;
  char a, b;
  while(infile>>a>>b){
    if(b == 'X'){
      if(a == 'A') scores+=3;
      if(a == 'B') scores+=1;
      if(a == 'C') scores+=2;
    }
   if(b == 'Y'){
        scores+=3;
      if(a == 'A') scores+=1;
      if(a == 'B') scores+=2;
      if(a == 'C') scores+=3;
    }
   if(b == 'Z'){
        scores+=6;
      if(a == 'A') scores+=2;
      if(a == 'B') scores+=3;
      if(a == 'C') scores+=1;
    }
  }
cout << scores;
}

