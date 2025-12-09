#include <iostream>
#include<climits>
using namespace std;


int mincnt(int n ,int check[]){

    if(n==0) return 0;

    if(check[n-1]!=-1 ) return check[n-1];

    int minans = INT_MAX;

    for(int i=0;(i*i)<n;i++){

       int  cnt =1+mincnt(n-(i*i),check);

       minans=min(minans,cnt);

    }

    check[n-1]=minans;

    return minans;
}


int main(){

    int n;
    cin>> n;
    int check[n];

    for(int i=0;i<n;i++) check[i]=-1;

    int ans  =  mincnt(n,check);

    cout << ans << endl;
}