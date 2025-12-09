#include <iostream>
#include <string>
using namespace std;

void substrs(string input,string  output){

  if(input[0] =='\0'){

    cout << output << endl;
    return;

  }

  substrs(input.substr(1),output);
  substrs(input.substr(1),output+input[0]);

  return;
}

int main(){

    string i = "abc";
    string o = "";

    substrs(i,o);

    
}