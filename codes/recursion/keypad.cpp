#include <iostream>
#include <string>
#include<unordered_map>
using namespace std;

unordered_map<int,string> m ={
    {2,"abc"},{3,"def"},{4,"ghi"},{5,"jkl"},{6,"mno"},{7,"pqrs"},{8,"tuv"},{9,"wxyz"}
};

void helper(int n , string op){

    if(n==0 || n==1){
        cout << op << endl;
        return;
    }

    int ld = n%10;
    string s =m[ld];

    helper(n/10,s[0]+op);
    helper(n/10,s[1]+op);
    helper(n/10,s[2]+op);
    if(s[3]!='\0')
    helper(n/10,s[3]+op);

    return;
}

void printKeypad(int num){
    /*
    Given an integer number print all the possible combinations of the keypad. You do not need to return anything just print them.
    */
   helper(num,"");
}


int main(){
    int num;
    cin >> num;

    printKeypad(num);

    return 0;
}