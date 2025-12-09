
#include <iostream>
using namespace std;

int bs(int arr[],int s,int e, int x){
   
   if(s>e) return -1;
   int mid=(s+e)/2;

   if(arr[mid]==x) return mid;

   if(arr[mid]> x) return bs(arr,s,mid-1,x);

   if(arr[mid]<x) return bs(arr,mid+1,e,x);
}


int binarySearch(int input[], int size, int element) {
    // Write your code here
    int s=0,e=size-1;
   return  bs(input,s,e,element);

}

int main() {
    int input[100000],length,element, ans;
    cin >> length;
    for(int i =0;i<length;i++)
    { 
        cin >> input[i];;
    }

    cin>>element;
    ans = binarySearch(input, length, element);
    cout<< ans << endl;
}