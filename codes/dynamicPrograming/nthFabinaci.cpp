#include<iostream>
using namespace std;

bool funcheck(int n, int check[]){
     
    if(check[n]==-1) return false;

    return true;
}

int nthf(int n ,int check[]){

    if(n<=1) return n;

    int a =0,b=0;

    if(funcheck(n-1,check)) a= check[n-1];
    else {
        a = nthf(n-1,check);
        check[n-1]=a;
    }
    if(funcheck(n-2,check)) b= check[n-2];
    else {
        b= nthf(n-2,check);
        check[n-2]=b;
    }

    return a+b;
}

int nthf2(int n,int check[]){

    if(n<=1) return n;

    if(check[n]!=-1) return check[n];

    int a = nthf2(n-1,check);
    int b = nthf2(n-2,check);

    check[n]=a+b;

    return a+b;
}

int main(){

    int n;
    cin >> n;
    int check[n+1];

    for(int i=0;i<n+1;i++){
        check[i]=-1;
    }

    int ans = nthf2(n,check);
    cout << ans << endl;

}