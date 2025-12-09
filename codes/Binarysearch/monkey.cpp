#include<iostream>
using namespace std;

int rate(int ba[],int n,int hrs){
    int size = ba[n-1];
    int arr[5];

    for(int i=0;i<ba[n-1];i++){
        arr[i]=i+1;
    }

    int s=0;
    int e =ba[n-1]-1;
    int actrate;
    
    while(s<=e){
        int mid = (s+e)/2;
        int time=0;
         
        for(int i=0;i<n;i++){
            int t = ba[i];
            
            while(t>0){
                t-=arr[mid];
                time++;
            }
        }

        if(time<=hrs){
            actrate=arr[mid];
            s=mid+1;
        }
        else {
            e=mid-1;
        }
    }

    return actrate;
}

int main(){

    int arr[5]={1,2,3,4,5};

    int ans = rate(arr,5,5);

    cout << ans << endl;
}