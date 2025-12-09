#include<iostream>
using namespace std;

int ks_dp(int * W,int * V ,int n ,int Mw,int ** op){

    if(n==0 || Mw==0) return 0;

    if(op[n][Mw]!=-1) return op[n][Mw];

    if(Mw < W[0]) {
        op[n][Mw] = ks_dp(W + 1, V + 1, n - 1, Mw, op);
        return  op[n][Mw];
    }
   

    int x = V[0]+ks_dp(W+1,V+1,n-1,Mw-W[0],op);
    int y = ks_dp(W+1,V+1,n-1,Mw,op);

    op[n][Mw]=max(x,y);

    return max(x,y);
}

int knapsack2(int *W,int *V,int n,int MW){

    if(n==0 || MW==0) return 0;

    if(MW<W[0])
    return knapsack2(W+1,V+1,n-1,MW);

    int x= V[0] + knapsack2(W+1,V+1,n-1,MW-W[0]);
    int y =knapsack2(W,V,n-1,MW);

    return max(x,y);
}

int knapsack(int * W,int* V,int n, int MW,int v,int idx){

    if(idx>=n) return v;

    int ans  = v;

    for(int i=idx;i<n;i++){

        if(MW>=W[i]){
            int tempval = knapsack(W,V,n,MW-W[i],v+V[i],i+1);
            ans = max(ans,tempval);
        }
    }

    return ans;
}

int main() {
    int n;
    cout << "Enter number of items: ";
    cin >> n;

    
    int *W = new int[n];
    int *V = new int[n];

    cout << "Enter weights:\n";
    for (int i = 0; i < n; i++) cin >> W[i];

    cout << "Enter values:\n";
    for (int i = 0; i < n; i++) cin >> V[i];

    int MW;
    cout << "Enter max weight: ";
    cin >> MW;

    int ** op = new int*[n+1];

    for(int i=0;i<=n;i++){
        op[i] = new int[MW+1];
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=MW;j++){
            op[i][j]=-1;
        }
    }

    cout << "Maximum value: " << ks_dp(W, V, n, MW,op) << endl;

    delete[] W;
    delete[] V;
    for(int i=0;i<n;i++) delete [] op[i];
    delete [] op;
}
