#include<iostream>
#include<algorithm>
using namespace std;

/*
	The function is called with the parameters:
	quickSort(input, 0, size - 1);

*/

int partitionArray(int input[], int start, int end) {
	// Write your code here
    int p=input[start];
	int pi=start;
	for(int i=start+1;i<=end;i++){
		if(input[i]<=p) pi++;
	}
    swap(input[start],input[pi]);

	int i=start,j=end;

	 while (i < pi && j > pi) {
        if (input[i] <= p) {
            i++;
        } else if (input[j] > p) {
            j--;
        } else {
            swap(input[i++], input[j--]);
        }
    }


	return pi;
	
}

void quickSort(int input[], int start, int end) {
	/*
		Don't write main().
		Don't read input, it is passed as function argument.
		Change in the given array itself.
		Taking input and printing output is handled automatically.
	*/

	if(start>=end) return ;

	int pi=partitionArray(input,start,end);

	quickSort(input,start,pi-1);

	quickSort(input,pi+1,end);
}


int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, size - 1);

    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    return 0;
}
