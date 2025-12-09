#include<iostream>
#include<climits>
using namespace std;

bool isvalid(int x,int y,int n,int m, int ** arr){
    if(x>=n || y>=m) return false;

     return true;

}

int dp(int n ,int m,int ** arr,int ** check){

    check[n-1][m-1]=arr[n-1][m-1];

    for(int i=m-2;i>=0;i--){
        check[n-1][i]=arr[n-1][i]+check[n-1][i+1];
    }

    for(int i=n-2;i>=0;i--){
        check[i][m-1]=arr[i][m-1]+check[i+1][m-1];
    }

    for(int i=n-2;i>=0;i++){
        for(int j=m-2;j>=0;j++){
            check[i][j]=arr[i][j]+min(check[i+1][j],min(check[i+1][j+1],check[i][j+1]));
        }
    }

    return check[0][0];
}

int mincostpath(int x,int y,int n,int m,int ** arr,int** check){

    if(x==n-1&& y==m-1) return arr[x][y];

    if(check[x][y]!=-1) return check[x][y];

    int right=INT_MAX,down=INT_MAX,da=INT_MAX;

    if(isvalid(x,y+1,n,m,arr)) right=mincostpath(x,y+1,n,m,arr,check); 

    if(isvalid(x+1,y,n,m,arr)) down=mincostpath(x+1,y,n,m,arr,check);

    if(isvalid(x+1,y+1,n,m,arr)) da=mincostpath(x+1,y+1,n,m,arr,check); 

    int ans = arr[x][y]+min(right,min(down,da));

    check[x][y]=ans;

    return ans;
}


int main(){

    int n,m;
    cin >> n >> m;

    int** arr = new int*[n];
    int** check = new int*[n];
    for(int i = 0; i < n; i++) {
    arr[i] = new int[m];
    check[i] = new int[m];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> arr[i][j];
            check[i][j]=-1;
        }
    }

    int ans  = dp(n,m,arr,check);

    cout  << ans << endl;


}