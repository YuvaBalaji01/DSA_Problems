#include <iostream>
using namespace std;



bool helper(int arr[],int n,int index,int sum5,int sum3){
    if(index==n) return sum5==sum3;


    if(helper(arr,n,index+1,sum5+arr[index],sum3)) return true;
    if(helper(arr,n,index+1,sum5,sum3+arr[index])) return true;
 


    return false;
}



bool splitArray(int *input, int size) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */

    int d5=0,d3=0,j=0;
    int *r =new int[size];

    for(int i=0;i<size;i++){
        if (input[i]%5==0) d5+=input[i];
        else if(input[i]%3==0) d3+=input[i];
        else r[j++]=input[i];
    }

    bool ans=helper(r,j,0,d5,d3);
   

   delete [] r;
    return ans;
   
  
}


int main() {

	int size;
	cin>>size;
	int *input=new int[1+size];	
	
	for(int i=0;i<size;i++)
		cin>>input[i];
	
    if(splitArray(input, size)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }

	
	return 0;

}
