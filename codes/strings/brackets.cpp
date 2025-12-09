#include <iostream>
#include <string>
using namespace std;

int countBracketReversals(string input) {
	// Write your code here
   int n=input.length();
   if(n%2!=0) return -1;
   int open =0;
   int close=0;
   for(int i=0;i<n;i++){
    if(input[i]=='{') open++;
    else{
        if(open>0) open--;
        else close++;
    }
   }

   return (open+1)/2+(close+1)/2;
}

int main() {
    string input;
    cin >> input;
    cout << countBracketReversals(input);
}