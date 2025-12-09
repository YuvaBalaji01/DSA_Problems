#include<iostream>
#include<vector>
using namespace std;

int subsets(int arr[],int n,int index,int row,vector<int> c,int o[][20]){

    o[row][0]=c.size();
    for(int i=0;i<c.size();i++) o[row][i+1]=c[i];
    row++;

    for(int i= index;i<n;i++){
        c.push_back(arr[i]);
        row = subsets(arr,n,i+1,row,c,o);
        c.pop_back();
    }

    return row;
}

int main(){
    int arr[3]={2,3,4};
    //int** o =new int*[1000];
    int o[1000][20];
    vector<int> c;
    int rowsize = subsets(arr,3,0,0,c,o);

    for(int i=0;i<rowsize;i++){

        for(int j=1;j<=o[i][0];j++)
        cout << o[i][j] << " ";

    cout << endl;


    }

    
   
}