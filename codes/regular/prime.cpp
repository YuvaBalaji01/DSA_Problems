#include <iostream>
using namespace std;
int main (){
    int n;
    cin >> n;
    int  a=2;
    bool prime = true;
    while(a<=n/2){
        if(n%a==0)
       { prime =false;
        break;}
        a++;
    }
    if(prime)
    cout << "its a prime num" << endl;
    else 
    cout << "not a prime" << endl;

}