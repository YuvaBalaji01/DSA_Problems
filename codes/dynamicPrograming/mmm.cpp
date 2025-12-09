#include<iostream>
#include<climits>
using namespace std;

int minmatmulneeded(int arr[],int s,int e,int ** dp){

    if(s==e || s== e-1) return 0;

    if(dp[s][e]!=-1) return dp[s][e];

    int minans = INT_MAX;

    for(int i=s+1;i<e;i++){

        int minm = minmatmulneeded(arr,s,i,dp)+minmatmulneeded(arr,i,e,dp)+arr[s]*arr[i]*arr[e];

        minans  =  min(minans,minm);

    }

    dp[s][e] = minans;

    return minans;
}

int main(){

    int n;
    cin >> n;
    int arr[n+1];
    for(int i=0;i<=n;i++) cin >> arr[i];

    int ** dp = new int*[n+1];

    for(int i=0;i<=n;i++){
        dp[i] = new int[n+1];
    }

    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            dp[i][j]=-1;
        }
    }

    int ans = minmatmulneeded(arr,0,n,dp);

    cout << ans << endl;

    for(int i=0;i<=n;i++) delete [] dp[i];

    delete [] dp;
}