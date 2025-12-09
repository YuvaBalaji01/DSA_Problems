#include<iostream>
#include<climits>
using namespace std;

int stepsto1(int n ,int arr[]){

    if(n==1) return 0;

    if(arr[n-1]!=-1) return arr[n-1];

    int a =INT_MAX,b=INT_MAX,c=INT_MAX;

    a = 1+stepsto1(n-1,arr);
    if(n%2==0)
    b= 1+stepsto1(n/2,arr);
    if(n%3==0)
    c = 1+stepsto1(n/3,arr);

    arr[n-1]=min(a,min(b,c));
    return arr[n-1];

}

int main(){

    int n ;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++) arr[i]=-1;

    int ans  = stepsto1(n,arr);
    cout << ans << endl;
}