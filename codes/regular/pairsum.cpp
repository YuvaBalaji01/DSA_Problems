#include <iostream>
#include <algorithm>
using namespace std;

int pairSum(int *arr, int n, int num)
{
	//Write your code here

	sort(arr,arr+n);
   
	int i=0,j=n-1,ans=0;

	while(i<j){
      
		if(arr[i]+arr[j]<num) i++;

		else if(arr[i]+arr[j]>num) j--;
        
		else {
			if(arr[i]==arr[j]){
				int x = j-i+1;
				ans+=x*(x-1)/2;
		        i+=n;j-=n;
			}

			else {
				int si=i,ei=j;
				while(arr[si]==arr[si+1]) si++;
				while(arr[ei]==arr[ei-1]) ei--;

				int g1=si-i+1,g2=j-ei+1;
				ans+=g1*g2;
				i+=g1;j-=g2;
			}
		}




	}

	return ans;


	
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int size;
		int x;

		cin >> size;
		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}

		cin >> x;

		cout << pairSum(input, size, x) << endl;

		delete[] input;
	}
	
	return 0;
}