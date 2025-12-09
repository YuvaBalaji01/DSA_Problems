#include <iostream>
#include <string>
using namespace std;

int returnPermutations(string input, string output[]){
   	
	if(input[0]=='\0'){
		output[0]="";
		return 1;
	}

	int size = returnPermutations(input.substr(1),output);

    string* temp = new string[10000];

	int k=0;
	for(int i=0;i<input.length();i++){
		for(int j=0;j<size;j++){
			string s = output[j];
			s.insert(i,1,input[0]);
			temp[k++]=s;
		}
	}

	for(int i=0;i<k;i++) output[i]=temp[i];

	delete [] temp;

	return size*input.length();
	
}

using namespace std;

int main(){
    string input;
    cin >> input;
    string output[10000];
    int count = returnPermutations(input, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}
