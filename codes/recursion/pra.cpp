#include<iostream>
#include<vector>
using namespace std;

int permutations(int arr[],int n,int index, int row, vector<int> &c , int op[][20]){

    op[row][0]=c.size();
    for(int i=0;i<c.size();i++){
        op[row][i+1]=c[i];
    }
    row++;

    for(int i= index;i<n;i++){

        c.push_back(arr[i]);
        row= permutations(arr, n ,i+1 , row , c, op);
        c.pop_back();

    }

    return row;
}

int main(){

    int arr[3]={12,20,15};
    int op[10000][20];
    vector<int> c;
    int size= permutations(arr,3 ,0 , 0, c, op );
    for(int i=0;i<size;i++){
        for(int j=0;j<op[i][0];j++){
            cout << op[i][j+1] << " ";
        }

        cout << endl;
    }
}