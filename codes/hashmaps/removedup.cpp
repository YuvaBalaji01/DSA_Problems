#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

vector<int> removedup(int arr[],int n){

    unordered_map<int,bool> map;
    vector<int> v;

    for(int i=0;i<n;i++){

        if(!map[arr[i]]) v.push_back(arr[i]); map[arr[i]]=true;

       
    }

    return v;

}

int main(){

    int arr[7]={1,2,1,2,3,4,3};
    vector<int> ans = removedup(arr,7);
    for(int i=0;i<ans.size();i++) cout << ans[i] << " ";
}