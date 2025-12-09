#include <iostream>
using namespace std;

int findUnique(int *arr, int n) {
    // Write your code here

    int me=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>me) me=arr[i];
    }

    int size = (me>n)?me+1:n;

    int* ar = new int[size];
    for(int i=0;i<size;i++) ar[i]=0;
    for(int i=0;i<n;i++) ar[arr[i]]++;

    for(int i=0;i<size;i++){
        if(ar[i]==1) return i;
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int size;
        cin >> size;
        int *input = new int[size];

        for (int i = 0; i < size; ++i) {
            cin >> input[i];
        }

        cout << findUnique(input, size) << endl;
    }

    return 0;
}