#include <iostream>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.length();
    int i = 0, j = n - 1;
    bool isPalindrome = true;
    while(j>=i){
        if(s[i] != s[j]){
            isPalindrome=false;
            break;}
            else{
                i++;j--;}
    }
    if(isPalindrome)
    cout << "Palindrome" << endl;
    else
    {
        cout << "Not a Palindrome" << endl;
    }
    
}