#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> generate(vector<int> & arr,int target,vector<int> &c ,int idx,vector<vector<int>> ans){

    if(target==0){
        ans.push_back(c);
        return ans;
    }

    for(int i=idx;i<arr.size();i++){
        
        if(arr[i] > target){
            break;
        }

        c.push_back(arr[i]);
        ans = generate(arr,target-arr[i],c,i,ans);
        c.pop_back();
    }

    return ans;
}


int main(){

    vector<int> arr={1,2,3};
    vector<int> c;
    vector<vector<int>> ans;

    ans = generate(arr,5,c,0,ans);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout << ans[i][j] << " ";
        }

        cout << endl;
    }
}