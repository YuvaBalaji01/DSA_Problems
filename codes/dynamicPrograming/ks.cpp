#include<iostream>
using namespace std;

int knapscak(int * W,int *V,int n, int MW){

    if(n==0 || MW==0) return 0;

    if(MW<W[0]) return knapscak(W+1,V+1,n-1,MW);

    int x = V[0]+knapscak(W+1,V+1,n-1,MW-W[0]);
    int y = knapscak(W+1,V+1,n-1,MW);

    return max(x,y);
}

int main(){

    int n;
    cin >> n;
    int * W = new int[n];
    int * V = new int[n];

    for(int i=0;i<n;i++) cin >> W[i];
    for(int i=0;i<n;i++) cin >> V[i];

    cout << knapscak(W,V,n,50);

}