#include <iostream>
using namespace std;


void merge(int arr[], int start, int mid, int end) {
    int n1 = mid - start + 1;
    int n2 = end - mid;

    // Create temp arrays
    int* left = new int[n1];
    int* right = new int[n2];

    // Copy data to temp arrays
    for (int i = 0; i < n1; i++)
        left[i] = arr[start + i];
    for (int i = 0; i < n2; i++)
        right[i] = arr[mid + 1 + i];

    // Merge the temp arrays back into arr[]
    int i = 0, j = 0, k = start;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }

    // Copy the remaining elements
    while (i < n1) arr[k++] = left[i++];
    while (j < n2) arr[k++] = right[j++];

    delete[] left;
    delete[] right;
}

void mergeSort(int arr[], int l, int r) {
    // Write Your Code Here

    if(l>=r) return ;

    int mid =(l+r)/2;

    mergeSort(arr,l,mid);

    mergeSort(arr,mid+1,r);

    merge(arr,l,mid,r);
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int arr_size = sizeof(arr)/sizeof(arr[0]);

    mergeSort(arr, 0, arr_size - 1);

    for(int i = 0; i < arr_size; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}