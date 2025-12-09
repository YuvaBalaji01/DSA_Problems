#include <iostream>
#include <algorithm>
using namespace std;

int tripletSum(int *arr, int n, int num)
{
	//Write your code here
    
	sort(arr,arr+n);
	int ans=0;

	for(int i=0;i<n-1;i++){
		int j=i+1,k=n-1;

		while(j<k){
			int cs=arr[i]+arr[j]+arr[k];

			if(cs==num){
               ans++;
			   int tk=k-1;
			   while(tk>j){
				   if(arr[tk]==arr[k]){
					   ans++;
					   tk--;
				   }
				   else break;
			   }
			   j++;
			}

			else if(cs<num) j++;

			else k--;
		}
	}

	return ans;
	
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
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

		cout << tripletSum(input, size, x) << endl;

		delete[] input;
	}

	return 0;
}