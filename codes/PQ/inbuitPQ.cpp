#include <iostream>
#include<queue>
using namespace std;

void ksorted(int arr[],int k,int n){
 
    priority_queue<int> pq;
    for(int i=0;i<k;i++){
       pq.push(arr[i]);
    }

    int j=0;
    for(int i=k;i<n;i++){

        arr[j]=pq.top();
        pq.pop();
        pq.push(arr[i]);
        j++;
    }

    while(!pq.empty()){
        arr[j]=pq.top();
        pq.pop();
        j++;
    }
}

int main(){
    int arr[5]={10,12,15,6,9};

    ksorted(arr,3,5);

    for(int i:arr){
        cout << i << " ";
    }
}