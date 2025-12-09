#include <iostream>
#include <vector>
using namespace std;
#include<queue>


int buyTicket(int *arr, int n, int k) {
    // Write your code here
    
    priority_queue<int> pq;
    queue<pair<int,int>> q;

    for(int i=0;i<n;i++){
        q.push({arr[i],i});
        pq.push(arr[i]);
    }

    int t=0;
    while(!q.empty()){

        int cp = q.front().first;
        int ci = q.front().second;
        q.pop();

        
        if(cp==pq.top()){

            t++;
            pq.pop();
            if(ci==k) return t;
        }

        else {
            q.push({cp,ci});
        }
    }

}

int main() {
    int n;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    cout << buyTicket(arr, n, k);

    delete[] arr;
}