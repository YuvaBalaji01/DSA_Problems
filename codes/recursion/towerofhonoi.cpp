#include<iostream>
using namespace std;

void honai(int n , char s, char h ,char d){
    if(n==0) return;

    if(n==1){
        cout << s << " " << d << endl;
        return;
    }

    honai(n-1,s,d,h);
    cout << s << " " << d  << endl;
    honai(n-1,h,s,d);

    return;
}

int main(){

    int n ;
    cin >> n;
    honai(n,'a','b','c');
}