#include<iostream>
#include <bits/stdc++.h> 
using namespace std;

int getans(int currentans ,int newans , int target){

    int diff1=abs(currentans-target);
    int diff2 = abs(newans-target);

    if(diff1==diff2) return min(currentans,newans);

    return (diff1<diff2?currentans:newans);

}

int fun(vector<int>& toppings,int ctidx , int numofct , int target){

    if(ctidx<0) return 0;

    int taketop=0,nottake=0;

    if(numofct < 2){
        taketop=toppings[ctidx]+fun(toppings,ctidx,numofct+1,target-toppings[ctidx]);
    }
    nottake=fun(toppings,ctidx-1,0,target);

    return getans(taketop,nottake,target);
}


int closestcost(int n,int m,vector<int>&base,vector<int>&toppings,int k){

    int ans = INT_MAX;

    for(int i=0;i<n;i++){
        int currentbase=base[i];
        if(currentbase<k){
            ans=getans(ans,currentbase+fun(toppings,m-1,0,k-currentbase),k);
        }
        ans=getans(ans,currentbase,k);
    }

    return ans;
}


int main(){

    int n=4,m=3;
    vector<int> base={1,8,3,4};
    vector<int> toppings={2,3,4};

    int ans = closestcost(n,m,base,toppings,20);

    cout << ans << endl;
}

