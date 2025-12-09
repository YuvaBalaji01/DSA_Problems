#include <iostream>
#include<cmath>
#include<queue>
using namespace std;

void findMedian(int *arr, int n){

    priority_queue<int> mal;
    priority_queue<int,vector<int>,greater<int>> mir;

    for(int i=0;i<n;i++){

        if(mal.empty() || mal.top()>arr[i]) mal.push(arr[i]);
        else mir.push(arr[i]);

       if(mal.size() > mir.size()+1){
        mir.push(mal.top());
        mal.pop();
       }

       else if(mir.size() > mal.size()){

        mal.push(mir.top());
        mir.pop();
       }

        if((i+1)%2==0)
        cout <<( mal.top()+mir.top())/2 << " ";
        else 
        cout << mal.top() << " ";
    }

}

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    findMedian(arr,n);

    delete[] arr;
}
