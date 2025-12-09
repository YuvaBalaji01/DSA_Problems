#include<iostream>
#include<unordered_map>
using namespace std; 

int sumo(int arr[0],int n){

    unordered_map<int,int> m;
    int ans=0;

    for(int i=0;i<n;i++){

        if(m.count(-arr[i])>0){
            ans+=m[-arr[i]];

        }

        m[arr[i]]++;
    }

    return ans;
}


int main(){

    int n;
    cin >> n;
    int arr[n];

    for(int i=0;i<n;i++) cin >> arr[i];

    cout << sumo(arr,n) << endl;
}