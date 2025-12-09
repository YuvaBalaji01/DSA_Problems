#include<iostream>
#include<map>
using namespace std;

int main(){

    int arr[6]={1,2,2,3,3,3};

    map<int,int> m;

    for(int i=5;i>=0;i--){

        m[arr[i]]++;
    }

    int ans=0;
    map<int,int>:: iterator it = m.begin();

    while(it!=m.end()){

        if(it->first==it->second) {
            ans = it->first;
        }

        it++;
    }

    cout << ans << endl;
}