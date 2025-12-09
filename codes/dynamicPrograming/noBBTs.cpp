#include<iostream>
using namespace std;

int mod = 1e9+7;

int noofBBTs(int h,int check[]){

    if(h==1) return 1;
    if(h==2) return 3;

    if(check[h-1]!=-1) return check[h-1];

    long long x = noofBBTs(h-1,check);
    long long y = noofBBTs(h-2,check);

    int res1 = (1*x*x)%mod;
    int res2 = (2*x*y)%mod;

    check[h-1]= (res1+res2)%mod;
    return (res1+res2)%mod;
}

int main(){
    int h;
    cin >> h;

    int check[h];

    for(int i=0;i<h;i++) check[i]=-1;


    int ans  = noofBBTs(h,check);

    cout << ans << endl;
}