#include<iostream>
#include<vector>
using namespace std;

void  unqsubset(vector<int> arr,int index,vector<int> c,vector<vector<int>> &op){

    op.push_back(c);
    

    for(int i=index ; i< arr.size();i++){

        if(i>index && arr[i]==arr[i-1]) continue;

        c.push_back(arr[i]);
        unqsubset(arr,i+1,c,op);
        c.pop_back();
    }

    return ;
}

int main(){

    vector<int> arr ={1,1,2};
    vector<int> c;
    vector<vector<int>> op;

     unqsubset(arr,0,c,op);

    for(int i=0;i<op.size();i++){
        for(int j=0;j<op[i].size();j++){

            cout << op[i][j] << " ";
        }
        cout << endl;
    }
}