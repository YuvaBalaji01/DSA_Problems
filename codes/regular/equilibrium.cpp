#include <iostream>
using namespace std;

int findEquilibriumIndex(int *arr, int n)
{
    //Write your code here
    if(n==0) return -1;
    int mid = n/2;
    int rs=0,ls=0;

    for(int i=0;i<mid;i++) rs+=arr[i];
    for(int i=mid+1;i<n;i++) ls+=arr[i];

    int i=n/2;

    while(i>=0){
        if(rs==ls)return mid;
        else if (rs>ls) {
            ls+=arr[mid];
            mid--;
            rs-=arr[mid];
           
            
        }

        else if (rs<ls){
            rs+=arr[mid];
            mid++;
            
            ls-=arr[mid];
        }
        i--;
    }

    return -1;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int size;
		cin >> size;
		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}

		cout << findEquilibriumIndex(input, size) << endl;

		delete[] input;
	}
	return 0;
}