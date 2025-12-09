#include<iostream>
using namespace std;

int coin(int c[],int n,int sum ,int t,int ** op,int idx){

    if(n<=0) return 0;
    if(sum == t) return 1;
    if(sum >t) return 0;

    if(op[sum][idx]==-1) return op[sum][idx];

    int ans=0;
    for(int i=idx;i<n;i++){
        ans+=coin(c,n,sum+c[i],t,op,i);
    }

    op[sum][idx]=ans;

    return ans;
}

int main(){

    int n;
    cin >> n;
    int c[n];
    for(int i=0;i<n;i++) cin >> c[i];
    int t;
    cin >> t;
    int **op=new int*[t+1];
    for(int i=0;i<=t;i++) op[i]=new int[n];

    for(int i=0;i<=t;i++){
        for(int j=0;j<n;j++){
            op[i][j]=-1;
        }
    }

    int ans = coin(c,n,t,0,op,0);

    cout << ans << endl;

    for(int i=0;i<=t;i++) delete [] op[i];

    delete [] op;
}