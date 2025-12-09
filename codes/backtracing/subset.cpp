#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> subset(int k,vector<int> vec,vector<vector<int>> ans,vector<int>& c){

    for(int i=0;i<vec.size();i++){

        c.push_back(vec[i]);
        int target = k-vec[i];

        while(target>0){
            c.push_back(vec[i]);
            target-=vec[i];
        }

        if(target==0){
            ans.push_back(c);
        }

        
    }
}

