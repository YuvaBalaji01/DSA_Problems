#include <iostream>
#include <unordered_map>
#include<vector>
using namespace std;

vector<int> longestConsecutiveIncreasingSequence(int *arr, int n) {
    // Your Code goes here
	int maxlen=0;
    unordered_map<int,int> m;
    int si;

    for(int i=0;i<n;i++) m[arr[i]]=true;

    for(int i=0;i<n;i++){

        int t=arr[i];
        int len=0;
        int s=arr[i];

        while(m[t] ){
            len++;
            t++;
        }

        t=arr[i]-1;

        while(m[t]){
            len++;
            s=t;
            t--;
        }

        if(maxlen< len){

            maxlen=len;
            si=s;
        }
		else if(maxlen==len){
			int index1;
			for(i=0;i<n;i++){
				if(arr[i]==s) {
					index1=i;
					break;
				}
			}
			int index2;
			for(i=0;i<n;i++){
				if(arr[i]==si) {
					index2=i;
					break;
				}
			}
			si=(index1<index2)?arr[index1]:arr[index2];
		}

        for(int i=s;i<=s+len-1;i++) m[i]=false;
    }

	vector<int> v;
	v.push_back(si);
	v.push_back(si+maxlen-1);

	return v;

}

int main(){


   
}