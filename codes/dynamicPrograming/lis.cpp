#include<iostream>
using namespace std;

int LIS(int * arr,int n){

    int * op = new int[n];
    op[0]=1;

    for(int i=1;i<n;i++){
        op[i]=1;
        for(int j=i-1;j>=0;j--){
            if(arr[i]>arr[j]){
                int ans  = op[j]+1;
                if(ans > op[i]) op[i]=ans;
            }
        }
    }

    int finalans=1;

    for(int i=1;i<n;i++){
        if(op[i] > finalans) finalans=op[i];
    }

    delete [] op;

    return finalans;
}


int main(){
     int n;
     cin >> n;
    int * arr = new int[n];
    for(int i=0;i<n;i++) cin >> arr[i];

    int ans = LIS(arr,n);

    cout << ans << endl;

    delete [] arr;
}