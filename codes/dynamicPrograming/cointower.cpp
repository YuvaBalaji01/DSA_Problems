#include<iostream>
using namespace std;

int winner(int n,int x,int y){

    if(n==1) return 1;

    int op[n+1];
    for(int i=0;i<=n;i++) op[i]=-1;

    op[1]=1;
    op[x]=1;
    op[y]=1;

    for(int i=2;i<=n;i++){
        if(op[i]==-1){
            if(i-1>=1 && op[i-1]^1) op[i]=1;
            else if(i-x>=1 && op[i-x]^1) op[i]=1;
            else if(i-y>=1 && op[i-y]^1) op[i]=1;
            else op[i]=0;
        }
    }

    if(op[n]==1) return 1;
    return 2;
}

int main(){

    int n;
    cin >> n;
    int x,y;
    cin >> x >> y;

    int ans = winner(n,x,y);

    if(ans==1) cout << "player 1" << endl;
    else cout << "player 2" << endl; 
}