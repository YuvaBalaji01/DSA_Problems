#include<iostream>
#include <iomanip>
using namespace std;

double gsum(int k){
    if(k==0) return 1.0;

    return (1.0/(1<<k))+gsum(k-1);
}

int main(){
    int k;
    cin >> k; 

    cout << fixed << setprecision(5) << gsum(k) << endl;
}